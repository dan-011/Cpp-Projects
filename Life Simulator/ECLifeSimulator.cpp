//
//  ECLifeSimulator.cpp
//  
//
//  Created by Yufeng Wu on 10/12/22.
//

#include "ECLifeSimulator.h"
using namespace std;

// ********************************************************
// Life simulator

ECLifeSimulator::ECLifeSimulator(){}
ECLifeSimulator::~ECLifeSimulator(){
    DeleteMemory();
}
void ECLifeSimulator::Initialize(){
    DeleteMemory();
    orgVec.clear();
    orgMap.clear();
}

void ECLifeSimulator::DeleteMemory(){
    /*for(ECOrganism* org : orgVec){
        delete org;
    }*/
    for(auto p : events){
        for(ECEvent* event : p.second){
            delete event;
        }
    }
}

int ECLifeSimulator::AddOrganism(ECOrganism *ptr){
    orgVec.push_back(ptr);
    orgMap.insert(pair<string, ECOrganism*>(ptr->GetName(), ptr));
    unsigned int pos = orgVec.size() - 1;
    posMap.insert(pair<ECOrganism*, int>(ptr, pos));
    return pos;
}
    
// Schedule a daily event for an organism, at certain time of day (hours), type of event (0: eat, 1: work), subtype of the event (for work, the kind of work)
void ECLifeSimulator::AddDailyEvent( double hours, int indexOrganism, int type, int subtype ){
    ECOrganism* org = orgVec[indexOrganism];
    ECEvent* event = new ECEvent(org, (EventType)type, subtype, indexOrganism);
    if(events.find(hours) == events.end()){ // if it is NOT in events
        vector<ECEvent*> e = {event};
        events.insert(pair<double, vector<ECEvent*>>(hours, e));
    }
    else{
        vector<ECEvent*>& e = events.at(hours);
        int insertAt = -1;
        for(unsigned int i = 0; i < e.size(); i++){
            if(e[i]->GetPosition() > event->GetPosition()){
                insertAt = i;
                break;
            }
        }
        if(insertAt < 0) e.push_back(event);
        else e.insert(e.begin() + insertAt, event);
    }
    if(setHours.find(hours) == setHours.end()){
        eventHours.push_back(hours);
        setHours.insert(hours);
    }
}
    
bool ECLifeSimulator::TestTime(double currentTime, double hour){
    return (currentTime == hour) || hour == 0;// || condition2;
}

// Run simulation from some time (hours) until there is no living organisms or run out of time (as specified in timeLimt, which is in the unit of hours)
//Return the total elapsed time from start to end of the simulation (in hours).
double ECLifeSimulator::Simulate(double hoursStart, double timeLimit){ // POP BACK FROM EVENTS
    sort(eventHours.begin(), eventHours.end());
    double elapsedTime = 0;
    double currentTime = hoursStart;
    set<string> setAlives;
    GetAliveOrganisms(setAlives);
    auto k = eventHours.begin();
    while(*k < hoursStart) k++;
    while(setAlives.size() > 0 && elapsedTime <= timeLimit){
        while(k != eventHours.end() && TestTime(currentTime, *k)){ // while we are not at the end of event hours and the current time is within the bounds
            double hour = *k;
            if(events.find(hour) != events.end()){ // if it IS in events
                vector<ECEvent*>& _events = events.at(hour);
                for(ECEvent* event : _events){ // for each event in events
                    if(event->GetEventType() == Eat){
                        event->GetOrganism()->Eat(hour);
                    }
                    else if(event->GetEventType() == Work){
                        event->GetOrganism()->Work(hour, event->GetSubtype());
                    }
                    else{
                        throw string("This shouldn't happen");
                    }
                }
            }
            k++;
        }
        if(currentTime == 24){
            k = eventHours.begin();
            currentTime = 0;
        }
        GetAliveOrganisms(setAlives);
        if(setAlives.size() == 0 || elapsedTime == timeLimit) break;
        elapsedTime += 0.5;
        currentTime += 0.5;
    }
    return elapsedTime;
}

    
// Collect info on simulation
// Get the alive organisms and return their names in the passed-in set
void ECLifeSimulator::GetAliveOrganisms(std::set<std::string> &setAlives) const{
    setAlives.clear();
    for(ECOrganism* org : orgVec){
        if(org->IsAlive()){
            setAlives.insert(org->GetName());
        }
    }
}
    
// Get the vitality of a specific organism (as named)
double ECLifeSimulator::GetVitalityFor(const std::string &orgName) const{
    ECOrganism* org = orgMap.at(orgName);
    return org->GetVitality();
}

int ECLifeSimulator::GetOrganismPosition(ECOrganism* organism) const{
    return posMap.at(organism);
}

ECEvent::ECEvent(ECOrganism* organism, EventType event, int subtype, int position): org(organism), eventType(event), subtype(subtype), pos(position){}
ECEvent::~ECEvent(){}
ECOrganism* ECEvent::GetOrganism() const{
    return org;
}
EventType ECEvent::GetEventType() const{
    return eventType;
}
int ECEvent::GetSubtype() const{
    return subtype;
}
int ECEvent::GetPosition() const{
    return pos;
}