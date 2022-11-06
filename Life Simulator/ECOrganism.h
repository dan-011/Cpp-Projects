//
//  ECOrganism.h
//  
//

#ifndef ECOrganism_h
#define ECOrganism_h

#include <string>
#include <set>
#include <iostream>
// ********************************************************
// Generic organism
enum Type 
{
  Nothing = -1,
  Arthropod = 0, 
  Mammal = 1, 
  Spider = 2,
  Grasshopper = 3,
  Caterpillar = 4,
  Mouse = 5,
  Fox = 6,
  Panda = 7
};
class ECOrganism
{
public:
    ECOrganism(std::string n, double v);
    ECOrganism(std::string n, int eatLimit, Type family, Type species, int startSleep, int endSleep, ECOrganism* prey, Type interest, int eatAmount);
    virtual ~ECOrganism();
    // work and consume energy
    virtual void Work(double hour, int type);
    // eat and gain energy
    virtual void Eat(double hour);
    // is sleeping at this hour?
    virtual bool IsSleeping(double hour) const;

    bool IsAlive() const;
    std::string GetName() const;
    double GetVitality() const;
    void Kill();
    Type GetSpecies() const;
    void LoseVitality(double v);

protected:
  virtual void WorkType0() = 0;
  virtual void WorkType1() = 0;
  int GetEatLimit() const;
  void SetEatLimit(int limit);
  void SetVitality(double v);
  void GainVitality(double v);
  void SetSpecies(Type s);
  Type GetFamily() const;
  void SetFamily(Type f);
  void SetSleep(int s, int e);
  int GetStartSleep() const;
  int GetEndSleep() const;
  bool isInterest(ECOrganism& org) const;
  void AddInterest(Type t);
  bool CanEat() const;
  void Consume();
  ECOrganism* GetPrey() const;
private:
  std::string name;
  double vitality;
  int eatLimit;
  Type family;
  Type species;
  int startSleep;
  int endSleep;
  ECOrganism* prey;
  Type interest;
  int eatAmount;
};

#endif /* ECOrganism_h */
