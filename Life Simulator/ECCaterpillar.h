//
//  ECCaterpillar.h
//  
//

#ifndef ECCaterpillar_h
#define ECCaterpillar_h

#include "ECArthropod.h"
class ECCaterpillar: public ECArthropod{
private:
    std::set<Type> interests;
public:
    ECCaterpillar(std::string n);
    ~ECCaterpillar();
    virtual void WorkType0() override;
    virtual void WorkType1() override;
};

#endif /* ECCaterpillar_h */
