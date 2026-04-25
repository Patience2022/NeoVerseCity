#ifndef POWERSYSTEM_H
#define POWERSYSTEM_H
#include <iostream>
using namespace std;
#include "CityComponent.h"

class PowerSystem : public CityComponent {
private:
	double powerLevel;
public:
	PowerSystem();
	PowerSystem(double);
	~PowerSystem();
	void setPowerLevel(double level);
	double getPowerLevel();
	void supplyPower();
	void processEvent() const override;
};
#endif