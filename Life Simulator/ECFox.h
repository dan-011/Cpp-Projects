//
//  ECFox.h
//  
//

#ifndef ECFox_h
#define ECFox_h

#include "ECMammal.h"

class ECFox: public ECMammal{
public:
    ECFox(std::string n, ECOrganism* prey);
    ECFox(std::string n);
    ~ECFox();
    virtual void WorkType1() override;
};

#endif /* ECFox_h */
