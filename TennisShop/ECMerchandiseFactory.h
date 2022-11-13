//
//  ECMerchandiseFactory.hpp
//

#ifndef ECMerchandiseFactory_hpp
#define ECMerchandiseFactory_hpp

#include "ECMerchandise.h"

// *********************************************************
// List of vendors
/*typedef enum
{
    TENNIS_ADIDAS = 1,
    TENNIS_NIKE = 2,
    TENNIS_HEAD = 3
} TENNIS_VENDOR;*/

// *********************************************************
// merchandise factory

class ECAbstractMerchandiseFactory{
public:
    virtual ECTennisItem* OrderProduct(TENNIS_VENDOR vendor) = 0;
};

class ECTennisShoeMerchandiseFactory: public ECAbstractMerchandiseFactory{
public:
    virtual ~ECTennisShoeMerchandiseFactory();
    ECTennisItem* OrderProduct(TENNIS_VENDOR vendor) override;
    ECTennisItem* OrderProduct(TENNIS_VENDOR vendor, int size);
};

class ECTennisBallCanMerchandiseFactory: public ECAbstractMerchandiseFactory{
public:
    virtual ~ECTennisBallCanMerchandiseFactory();
    ECTennisItem* OrderProduct(TENNIS_VENDOR vendor) override;
};

class ECTennisBagMerchandiseFactory: public ECAbstractMerchandiseFactory{
public:
    virtual ~ECTennisBagMerchandiseFactory();
    ECTennisItem* OrderProduct(TENNIS_VENDOR vendor) override;
};

// *********************************************************
// Merchandise creation: singleton pattern

class ECMerchandiseTennisShop
{
public:
    virtual ~ECMerchandiseTennisShop();
    static ECMerchandiseTennisShop &Instance();
    ECTennisShoe *OrderTennisShoe(int sz);
    ECTennisBallCan *OrderTennisBallCan();
    ECTennisBag *OrderTennisBag();
    void ChooseVendor(TENNIS_VENDOR vendor);
    int GetNumShoesSold() const;
    int GetNumBallcansSold() const;
    int GetNumBagsSold() const;
    int GetTotNumBallsSold() const;
    int GetTotRacquetBagCapaictySold() const;
    int GetTotRevenue() const;
    

    void testinc();
private:
    ECMerchandiseTennisShop();
    void SetBaseVars();
    //static ECMerchandiseTennisShop* singleton;
    int shoesSold;
    int tennisBallCansSold;
    int tennisBagsSold;
    int totalBallsSold;
    int totalCapacityRaquetsSold;
    int totalRevenue;
    TENNIS_VENDOR _vendor;
};

#endif /* ECMerchandiseFactory_hpp */
