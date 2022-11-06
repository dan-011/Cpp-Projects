//
//  ECLifeSimulator.h
//  
//
//  Created by Yufeng Wu on 10/12/22.
//

#ifndef ECLifeSimulator_h
#define ECLifeSimulator_h

#include "ECOrganism.h"
#include "ECEvent.h"
#include <algorithm>
#include <vector>
#include <map>
#include <set>
#include <string>

using namespace std;
// ********************************************************
// Life simulator

class ECLifeSimulator
{
public:
    ECLifeSimulator();
    ~ECLifeSimulator();
    // Initialize the simulation. Clear out all previous inputs (including the organisms)
    void Initialize();
    
    // Add an organism to simulate. Note: don't free its memory inside simulator
    // return its position in the list of organisms (to be used in future reference)
    int AddOrganism(ECOrganism *ptr);
    
    // Schedule a daily event for an organism, at certain time of day (hours), type of event (0: eat, 1: work), subtype of the event (for work, the kind of work)
    void AddDailyEvent( double hours, int indexOrganism, int type, int subtype );
    
    // Run simulation from some time (hours) until there is no living organisms or run out of time (as specified in timeLimt, which is in the unit of hours)
    //Return the total elapsed time from start to end of the simulation (in hours).
    double Simulate(double hoursStart, double timeLimit);
    
    // Collect info on simulation
    // Get the alive organisms and return their names in the passed-in set
    void GetAliveOrganisms(std::set<std::string> &setAlives) const;
    
    // Get the vitality of a specific organism (as named)
    double GetVitalityFor(const std::string &orgName) const;
    
private:
    std::vector<ECOrganism*> orgVec;
    std::map<std::string, ECOrganism*> orgMap;
    std::map<ECOrganism*, int> posMap;
    std::map<double, vector<ECEvent*>> events;
    std::vector<double> eventHours;
    std::set<double> setHours;
    void DeleteMemory();
    int GetOrganismPosition(ECOrganism* organism) const;
    bool TestTime(double currentTime, double hour);
};

#endif /* ECLifeSimulator_h */
