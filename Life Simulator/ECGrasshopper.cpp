//
//  ECGrasshopper.cpp
//  
//

#include "ECGrasshopper.h"

ECGrasshopper::ECGrasshopper(std::string n, ECOrganism* prey): ECArthropod(n, 5, Grasshopper, prey, Arthropod, 25){
}
ECGrasshopper::ECGrasshopper(std::string n): ECGrasshopper(n, NULL){}
ECGrasshopper::~ECGrasshopper(){}


void ECGrasshopper::WorkType0(){ // hop
    LoseVitality(5);
}

void ECGrasshopper::WorkType1(){
    ECOrganism* prey = GetPrey();
    if(prey == NULL) return;
    else if(!prey->IsAlive()) return; // if they're already dead do nothing
    else if(isInterest(*prey)){
        prey->Kill();
    }
    else if(prey->GetSpecies() == Mouse){
        prey->LoseVitality(5);
    }
    LoseVitality(40);
}