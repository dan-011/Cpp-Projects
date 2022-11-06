#ifndef __ECMammal_h
#define __ECMammal_h
#include "ECOrganism.h"

class ECMammal: public ECOrganism{
public:
  ECMammal(std::string n, int eatLimit, Type species, int startSleep, int endSleep, ECOrganism* prey, Type interest);
  ~ECMammal();
  virtual void WorkType0() override;
};

#endif