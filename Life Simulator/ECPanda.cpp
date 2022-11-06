//
//  ECPanda.cpp
//  
//

#include "ECPanda.h"

ECPanda::ECPanda(std::string n): ECMammal(n, 12, Panda, 15, 10, NULL, Nothing){}
ECPanda::~ECPanda(){}
bool ECPanda::IsSleeping(double hour) const{
    return hour >= GetStartSleep() || hour <= GetEndSleep();
}
void ECPanda::WorkType1(){
    throw std::string("Panda has no work type 1");
}