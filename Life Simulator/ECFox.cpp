//
//  ECFox.cpp
//  
//

#include "ECFox.h"

ECFox::ECFox(std::string n, ECOrganism* prey): ECMammal(n, 8, Fox, 7, 14, prey, Mouse){
}
ECFox::ECFox(std::string n): ECFox(n, NULL){}
ECFox::~ECFox(){}

void ECFox::WorkType1(){
    ECOrganism* prey = GetPrey();
    if(prey == NULL) return;
    else if(isInterest(*prey)){
        if(!(*prey).IsAlive()) return;
        (*prey).Kill();
    }
    LoseVitality(40);
}