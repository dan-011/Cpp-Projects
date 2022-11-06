//
//  ECOrganism.cpp
//  
//

#include "ECOrganism.h"

using namespace std;

ECOrganism::ECOrganism(std::string n, double v): name(n), vitality(v), prey(NULL){
}
ECOrganism::ECOrganism(std::string n, int eatLimit, Type family, Type species, int startSleep, int endSleep, ECOrganism* prey, Type interest, int eatAmount): name(n), vitality(100), eatLimit(eatLimit), family(family), species(species), startSleep(startSleep), endSleep(endSleep), prey(prey), interest(interest), eatAmount(eatAmount){}
ECOrganism::~ECOrganism(){
}
// work and consume energy
void ECOrganism::Work(double hour, int type){
    if(IsSleeping(hour) || !IsAlive()){
        return;
    }
    switch (type)
    {
        case 0:
            WorkType0();
            break;
        
        case 1:
            WorkType1();
            break;
    }
}
// eat and gain energy
bool ECOrganism::IsAlive() const{
    return vitality > 0;
}
std::string ECOrganism::GetName() const{
    return name;
}
double ECOrganism::GetVitality() const{
    return vitality;
}
void ECOrganism::SetVitality(double v){
    vitality = v;
}
int ECOrganism::GetEatLimit() const{
    return eatLimit;
}
void ECOrganism::GainVitality(double v){
    double vitality = GetVitality();
    if(vitality + v > 100){
        SetVitality(100);
    }
    else{
        SetVitality(vitality + v);
    }
}
void ECOrganism::LoseVitality(double v){
    if(vitality - v < 0){
        SetVitality(0);
    }
    else{
        SetVitality(vitality - v);
    }
}

void ECOrganism::Kill(){
    vitality = 0;
}

Type ECOrganism::GetSpecies() const{
    return species;
}
void ECOrganism::SetSpecies(Type s){
    species = s;
}
Type ECOrganism::GetFamily() const{
    return family;
}
void ECOrganism::SetFamily(Type f){
    family = f;
}
void ECOrganism::SetEatLimit(int limit){
    eatLimit = limit;
}
void ECOrganism::SetSleep(int s, int e){
    startSleep = s;
    endSleep = e;
}
int ECOrganism::GetStartSleep() const{
    return startSleep;
}
int ECOrganism::GetEndSleep() const{
    return endSleep;
}
bool ECOrganism::isInterest(ECOrganism& org) const{
    return org.GetSpecies() == interest || org.GetFamily() == interest;
}

ECOrganism* ECOrganism::GetPrey() const{
    return prey;
}

bool ECOrganism::IsSleeping(double hour) const{
    return hour >= startSleep && hour <= endSleep;
}

bool ECOrganism::CanEat() const{
    return eatLimit > 0 && IsAlive();
}

void ECOrganism::Consume(){
    eatLimit--;
}

void ECOrganism::AddInterest(Type t){
    interest = t;
}

void ECOrganism::Eat(double hour){
    if(IsSleeping(hour) || !CanEat()) return;
    Consume();
    GainVitality(eatAmount);
}

#include "ECArthropod.h"
ECArthropod::ECArthropod(std::string n, int eatLimit, Type species, ECOrganism* prey, Type interest, int eatAmount): ECOrganism(n, eatLimit, Arthropod, species, 9, 17, prey, interest, eatAmount){
}
ECArthropod::~ECArthropod(){}

#include "ECMammal.h"
ECMammal::ECMammal(std::string n, int eatLimit, Type species, int startSleep, int endSleep, ECOrganism* prey, Type interest): ECOrganism(n, eatLimit, Mammal, species, startSleep, endSleep, prey, interest, 50){
}
ECMammal::~ECMammal(){}
void ECMammal::WorkType0(){ // running
    LoseVitality(10);
}