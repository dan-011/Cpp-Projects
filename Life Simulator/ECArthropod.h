#ifndef __ECArthropod_h
#define __ECArthropod_h
#include "ECOrganism.h"

class ECArthropod: public ECOrganism{
protected:
  

public:
  ECArthropod(std::string n, int eatLimit, Type species, ECOrganism* prey, Type interest, int eatAmount);
  ~ECArthropod();
  int GetStartSleep() const;
  int GetEndSleep() const;  
};

#endif