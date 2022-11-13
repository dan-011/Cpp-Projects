//
//  ECMerchandise.h
//

#ifndef ECMerchandise_hpp
#define ECMerchandise_hpp

#include <string>

typedef enum
{
    TENNIS_ADIDAS = 1,
    TENNIS_NIKE = 2,
    TENNIS_HEAD = 3
} TENNIS_VENDOR;

class ECTennisItem{
public:
    virtual ~ECTennisItem();
    virtual int GetPrice() const = 0;
    void SetVendor(TENNIS_VENDOR v);
    TENNIS_VENDOR GetVendor() const;
protected:
    TENNIS_VENDOR vendor;
};

class ECTennisShoe: public ECTennisItem{
public:
    ECTennisShoe(TENNIS_VENDOR vendor, int s);
    ~ECTennisShoe();
    int GetPrice() const override;
private:
    int size;
};

class ECTennisBallCan: public ECTennisItem{
public:
    ECTennisBallCan(TENNIS_VENDOR vendor);
    ~ECTennisBallCan();
    int GetPrice() const override;
    int GetNumBalls() const;
};

class ECTennisBag: public ECTennisItem{
public:
    ECTennisBag(TENNIS_VENDOR vendor);
    ~ECTennisBag();
    int GetPrice() const override;
    int GetRaquetCapacity() const;
};

#endif /* ECMerchandise_hpp */
