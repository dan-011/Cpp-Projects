//
//  ECGrasshopper.h
//  
//

#ifndef ECGrasshopper_h
#define ECGrasshopper_h

#include "ECArthropod.h"
class ECGrasshopper: public ECArthropod{
public:
    ECGrasshopper(std::string n, ECOrganism* prey);
    ECGrasshopper(std::string n);
    ~ECGrasshopper();
    virtual void WorkType0() override;
    virtual void WorkType1() override;
};

#endif /* ECGrasshopper_h */
