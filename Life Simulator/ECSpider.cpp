//
//  ECSpider.cpp
//  
//

#include "ECSpider.h"

ECSpider::ECSpider(std::string n, ECOrganism* prey): ECArthropod(n, 5, Spider, prey, Arthropod, 20){
}
ECSpider::ECSpider(std::string n): ECSpider(n, NULL){

}
ECSpider::~ECSpider(){}

void ECSpider::WorkType0(){ // weave web
    LoseVitality(10);
}

void ECSpider::WorkType1(){
    ECOrganism* prey = GetPrey();
    if(prey == NULL){ // if no prey do nothing
        return;
    }
    else if(isInterest(*prey)){ // if prey is an interest, kill them
        if(!(*prey).IsAlive()){ // if prey is already dead, do nothing
            return;
        }
        (*prey).Kill();
    }
    LoseVitality(30); // lose 30 vitality
}