//
//  ECMerchandiseFactory.cpp
//

#include "ECMerchandiseFactory.h"
#include <iostream>

using namespace  std;

// *********************************************************
// Merchandise creation: singleton pattern
ECTennisShoeMerchandiseFactory::~ECTennisShoeMerchandiseFactory(){}
ECTennisItem* ECTennisShoeMerchandiseFactory::OrderProduct(TENNIS_VENDOR vendor){
    if((int)vendor != -1){
        return NULL;
    }
    return NULL;
}
ECTennisItem* ECTennisShoeMerchandiseFactory::OrderProduct(TENNIS_VENDOR vendor, int size){
    return new ECTennisShoe(vendor, size);
}
ECTennisBallCanMerchandiseFactory::~ECTennisBallCanMerchandiseFactory(){}
ECTennisItem* ECTennisBallCanMerchandiseFactory::OrderProduct(TENNIS_VENDOR vendor){
    return new ECTennisBallCan(vendor);
}
ECTennisBagMerchandiseFactory::~ECTennisBagMerchandiseFactory(){}
ECTennisItem* ECTennisBagMerchandiseFactory::OrderProduct(TENNIS_VENDOR vendor){
    return new ECTennisBag(vendor);
}

ECMerchandiseTennisShop::ECMerchandiseTennisShop(){
    SetBaseVars();
}
ECMerchandiseTennisShop::~ECMerchandiseTennisShop(){
}
void ECMerchandiseTennisShop::testinc(){
    totalRevenue++;
}
ECMerchandiseTennisShop& ECMerchandiseTennisShop::Instance(){
    static ECMerchandiseTennisShop instance;
    return instance;
}
ECTennisShoe* ECMerchandiseTennisShop::OrderTennisShoe(int sz){
    ECTennisShoeMerchandiseFactory factory;
    ECTennisShoe* tennisShoe = dynamic_cast<ECTennisShoe*>(factory.OrderProduct(_vendor, sz));
    shoesSold++;
    totalRevenue += tennisShoe->GetPrice();
    return tennisShoe;
}
ECTennisBallCan* ECMerchandiseTennisShop::OrderTennisBallCan(){
    ECTennisBallCanMerchandiseFactory factory;
    ECTennisBallCan* can = dynamic_cast<ECTennisBallCan*>(factory.OrderProduct(_vendor));
    tennisBallCansSold++;
    totalRevenue += can->GetPrice();
    totalBallsSold += can->GetNumBalls();
    return can;
}
ECTennisBag* ECMerchandiseTennisShop::OrderTennisBag(){
    ECTennisBagMerchandiseFactory factory;
    ECTennisBag* bag = dynamic_cast<ECTennisBag*>(factory.OrderProduct(_vendor));
    tennisBagsSold++;
    totalRevenue += bag->GetPrice();
    totalCapacityRaquetsSold += bag->GetRaquetCapacity();
    return bag;
}
void ECMerchandiseTennisShop::ChooseVendor(TENNIS_VENDOR vendor){
    _vendor = vendor;
}
int ECMerchandiseTennisShop::GetNumShoesSold() const{
    return shoesSold;
}
int ECMerchandiseTennisShop::GetNumBallcansSold() const{
    return tennisBallCansSold;
}
int ECMerchandiseTennisShop::GetNumBagsSold() const{
    return tennisBagsSold;
}
int ECMerchandiseTennisShop::GetTotNumBallsSold() const{
    return totalBallsSold;
}
int ECMerchandiseTennisShop::GetTotRacquetBagCapaictySold() const{
    return totalCapacityRaquetsSold;
}
int ECMerchandiseTennisShop::GetTotRevenue() const{
    return totalRevenue;
}
void ECMerchandiseTennisShop::SetBaseVars(){
    _vendor = TENNIS_ADIDAS;
    shoesSold = 0;
    tennisBallCansSold = 0;
    tennisBagsSold = 0;
    totalBallsSold = 0;
    totalCapacityRaquetsSold = 0;
    totalRevenue = 0;
}