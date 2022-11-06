//
//  ECMouse.cpp
//  
//

#include "ECMouse.h"

ECMouse::ECMouse(std::string n, ECOrganism* prey): ECMammal(n, 10, Mouse, 10, 18, prey, Grasshopper){
}

ECMouse::ECMouse(std::string n): ECMouse(n, NULL){}

ECMouse::~ECMouse(){}
void ECMouse::WorkType1(){
    using namespace std;
    ECOrganism* prey = GetPrey();
    if(prey == NULL) return;
    else if(isInterest(*prey)){
        if(!prey->IsAlive()) return;
        prey->Kill();
    }
    LoseVitality(20);
}