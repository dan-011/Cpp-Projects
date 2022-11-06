//
//  ECMouse.h
//  
//

#ifndef ECMouse_h
#define ECMouse_h

#include "ECMammal.h"

class ECMouse: public ECMammal{
public:
    ECMouse(std::string n, ECOrganism* prey);
    ECMouse(std::string n);
    ~ECMouse();
    virtual void WorkType1() override;
};

#endif /* ECMouse_h */
