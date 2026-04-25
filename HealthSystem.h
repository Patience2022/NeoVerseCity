#ifndef HEALTHSYSTEM_H
#define HEALTHSYSTEM_H
#include <iostream>
#include "CityComponent.h"
using namespace std;

class HealthSystem : public CityComponent {
private:
    int hospitalCnt;
public:
    HealthSystem();
    HealthSystem(int newHospitalCnt);
    ~HealthSystem();
    void setHospitalCnt(int count);
    int getHospitalCnt() const;
    void provideCare();
    void processEvent() const override;
};
#endif

