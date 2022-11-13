//
//  ECMerchandise.cpp
//  

#include "ECMerchandise.h"
using namespace std;

ECTennisItem::~ECTennisItem(){}
void ECTennisItem::SetVendor(TENNIS_VENDOR v){
    vendor = v;
}

TENNIS_VENDOR ECTennisItem::GetVendor() const{
    return vendor;
}

ECTennisShoe::ECTennisShoe(TENNIS_VENDOR vendor, int s): size(s){
    SetVendor(vendor);
}
ECTennisShoe::~ECTennisShoe(){}
int ECTennisShoe::GetPrice() const{
    switch(GetVendor()){
        case TENNIS_ADIDAS:
            return 20;
        case TENNIS_NIKE:
            return 15;
        case TENNIS_HEAD:
            return 10;
        default:
            throw string("Invalid vendor (Shoe GetPrice)");
    }
}

ECTennisBallCan::ECTennisBallCan(TENNIS_VENDOR vendor){
    SetVendor(vendor);
}
ECTennisBallCan::~ECTennisBallCan(){}
int ECTennisBallCan::GetPrice() const{
    switch(GetVendor()){
        case TENNIS_ADIDAS:
            return 5;
        case TENNIS_NIKE:
            return 6;
        case TENNIS_HEAD:
            return 4;
        default:
            throw string("Invalid vendor (BallCan GetPrice)");
    }
}
int ECTennisBallCan::GetNumBalls() const{
    switch(GetVendor()){
        case TENNIS_ADIDAS:
            return 3;
        case TENNIS_NIKE:
            return 4;
        case TENNIS_HEAD:
            return 3;
        default:
            throw string("Invalid vendor (GetNumBalls)");
    }
}

ECTennisBag::ECTennisBag(TENNIS_VENDOR vendor){
    SetVendor(vendor);
}
ECTennisBag::~ECTennisBag(){}
int ECTennisBag::GetPrice() const{
    switch(GetVendor()){
        case TENNIS_ADIDAS:
            return 18;
        case TENNIS_NIKE:
            return 12;
        case TENNIS_HEAD:
            return 10;
        default:
            throw string("Invalid vendor (Tennis Bag GetPrice)");
    }
}
int ECTennisBag::GetRaquetCapacity() const{
    switch(GetVendor()){
        case TENNIS_ADIDAS:
            return 6;
        case TENNIS_NIKE:
            return 4;
        case TENNIS_HEAD:
            return 3;
        default:
            throw string("Invalid vendor (GetRaquetCapcity)");
    }
}