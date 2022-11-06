//
//  ECPanda.hpp
//  
//

#ifndef ECPanda_h
#define ECPanda_h

#include "ECMammal.h"

class ECPanda: public ECMammal{
public:
    ECPanda(std::string n);
    ~ECPanda();
    virtual bool IsSleeping(double hour)const override;
    virtual void WorkType1() override;
};

#endif /* ECPanda_h */
