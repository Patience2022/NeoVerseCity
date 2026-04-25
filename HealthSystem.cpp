#include <iostream>
#include "HealthSystem.h"
using namespace std;


HealthSystem::HealthSystem()
{
}

HealthSystem::HealthSystem(int newHospitalCnt)
{
}

HealthSystem::~HealthSystem() {}
void HealthSystem::setHospitalCnt(int count)
{
    hospitalCnt = count;
}
int HealthSystem::getHospitalCnt() const
{
    return hospitalCnt;
}
void HealthSystem :: provideCare() {}
void HealthSystem::processEvent() const {
    cout << "Health system responding to emergency." << std::endl;
}


