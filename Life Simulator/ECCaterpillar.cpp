//
//  ECCaterpillar.cpp
//  
//

#include "ECCaterpillar.h"

ECCaterpillar::ECCaterpillar(std::string n): ECArthropod(n, 5, Caterpillar, NULL, Nothing, 15){
}
ECCaterpillar::~ECCaterpillar(){}
void ECCaterpillar::WorkType0(){
    LoseVitality(10);
}
void ECCaterpillar::WorkType1(){
    throw std::string("Caterpillar has no work type 1");
}