#include <iostream>
#include "HealthSystem.h"
using namespace std;


HealthSystem::HealthSystem(): hospitalCnt(0)
{
}

HealthSystem::HealthSystem(int id, string name,int newHospitalCnt) :CityComponent(id, name), hospitalCnt(newHospitalCnt)
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
void HealthSystem :: provideCare() {
    cout << "Providing health services to patients " << endl;
}
void HealthSystem::processEvent() const {
    cout << "Processing health system event." << std::endl;
}


