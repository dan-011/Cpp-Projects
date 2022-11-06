//
//  ECSpider.h
//  
//

#ifndef ECSpider_h
#define ECSpider_h

#include "ECArthropod.h"

class ECSpider: public ECArthropod{

public:
    ECSpider(std::string n, ECOrganism* prey);
    ECSpider(std::string n);
    ~ECSpider();
    virtual void WorkType0() override;
    virtual void WorkType1() override;
};

#endif /* ECSpider_h */
