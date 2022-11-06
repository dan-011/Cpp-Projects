#include "ECSpider.h"
#include "ECGrasshopper.h"
#include "ECCaterpillar.h"
#include "ECMouse.h"
#include "ECFox.h"
#include "ECPanda.h"
#include "ECOrganism.h"
#include "ECLifeSimulator.h"
#include <iostream>
#include <cassert>
using namespace std;

/*
popo the Grasshopper is Working with subtype 0 at time 1 (pos 0) and vitality 100
popo the Grasshopper is Working with subtype 0 at time 2 (pos 0) and vitality 100
fofo the Mouse is Working with subtype 1 at time 1 (pos 1) and vitality 100
fofo the Mouse hunts popo the Grasshopper
fofo the Mouse is Working with subtype 0 at time 9 (pos 1) and vitality 100
fofo the Mouse is Eating with subtype 0 at time 10 (pos 1) and vitality 100
start: 2 :: limit: 20
*/

int main(){
    ECLifeSimulator sim;
    ECGrasshopper popo("popo");
    ECMouse fofo("fofo", &popo);

    int indexP = sim.AddOrganism(&popo);
    int indexF = sim.AddOrganism(&fofo);
    sim.AddDailyEvent(1, indexP, 1, 0);
    sim.AddDailyEvent(2, indexP, 1, 0);
    sim.AddDailyEvent(1, indexF, 1, 1);
    sim.AddDailyEvent(9, indexF, 1, 0);
    sim.AddDailyEvent(10, indexF, 0, 0);

    double dur = sim.Simulate(2, 20);
    cout << "duration :: " << dur << endl;
    cout << "popo V (should be 60) :: " << sim.GetVitalityFor("popo") << endl;
    cout << "fofo V (should be 60) :: " << sim.GetVitalityFor("fofo") << endl;
}





/*int main(){
    ECOrganism* caterpillar = new ECCaterpillar("caterpillar");
    ECOrganism* grasshopper = new ECGrasshopper("grasshopper", caterpillar);
    ECOrganism* spider = new ECSpider("Spider", caterpillar); // caterpillar will already be dead
    ECOrganism* mouse = new ECMouse("Mouse", grasshopper);
    ECOrganism* grasshopper2 = new ECGrasshopper("Grasshopper 2", mouse); // should reduce health by 5
    ECOrganism* fox = new ECFox("Fox", mouse);
    ECOrganism* panda = new ECPanda("Panda");

    caterpillar->Eat(8);
    assert(caterpillar->GetVitality() == 100);
    caterpillar->Work(10, -1);
    assert(caterpillar->GetVitality() == 100);
    caterpillar->Work(8, -1);
    assert(caterpillar->GetVitality() == 90);
    caterpillar->Eat(9);
    assert(caterpillar->GetVitality() == 90);
    for(int i = 0; i < 10; i++) caterpillar->Eat(7);
    assert(caterpillar->GetVitality() == 100);
    caterpillar->Work(24, -1);
    caterpillar->Eat(24);
    assert(caterpillar->GetVitality() == 90);

    grasshopper->Work(9, 1);
    assert(caterpillar->IsAlive());
    grasshopper->Work(5, 1);
    assert(!caterpillar->IsAlive());
    assert(grasshopper->GetVitality() == 60);
    grasshopper->Work(5, 1);
    assert(!caterpillar->IsAlive());
    assert(grasshopper->GetVitality() == 60);
    grasshopper->Work(7, 0);
    assert(grasshopper->GetVitality() == 55);

    spider->Work(7, 1);
    assert(spider->GetVitality() == 100);
    spider->Work(7, 0);
    assert(spider->GetVitality() == 90);
    for(int i = 0; i < 5; i++) spider->Eat(i);
    assert(spider->GetVitality() == 100);
    for(int i = 0; i < 10; i++) spider->Work(7, 0);
    assert(!spider->IsAlive());

    mouse->Work(9, 0);
    assert(mouse->GetVitality() == 90);
    mouse->Work(9, 1);
    assert(!grasshopper->IsAlive());
    assert(mouse->GetVitality() == 70);
    mouse->Work(9, 1);
    assert(mouse->GetVitality() == 70);
    mouse->Eat(18);
    assert(mouse->GetVitality() == 70);
    mouse->Eat(19);
    assert(mouse->GetVitality() == 100);
    
    grasshopper2->Work(0, 1);
    assert(grasshopper2->GetVitality() == 60);
    assert(mouse->GetVitality() == 95);

    fox->Work(0, 1);
    assert(fox->GetVitality() == 60);
    assert(!mouse->IsAlive());
    fox->Work(0, 1);
    assert(fox->GetVitality() == 60);
    assert(!mouse->IsAlive());
    for(int i = 0; i < 8; i++) fox->Eat(0);
    assert(fox->GetVitality() == 100);
    fox->Work(0, 0);
    fox->Eat(0);
    assert(fox->GetVitality() == 90);

    panda->Work(0, 0);
    assert(panda->GetVitality() == 100);
    panda->Work(11, 0);
    panda->Work(14, 0);
    assert(panda->GetVitality() == 80);
    for(int i = 0; i < 12; i++) panda->Eat(11);
    panda->Work(11, 0);
    assert(panda->GetVitality() == 90);
    for(int i = 0; i < 10; i++) panda->Work(11, 0);
    assert(!panda->IsAlive());
    assert(panda->GetVitality() == 0);

    delete spider;
    delete grasshopper;
    delete grasshopper2;
    delete caterpillar;
    delete mouse;
    delete fox;
    delete panda;
}*/