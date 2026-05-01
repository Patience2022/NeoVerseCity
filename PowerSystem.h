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
	PowerSystem(int id, string name,double level);
	~PowerSystem();
	void setPowerLevel(double level);
	double getPowerLevel() const;
	void supplyPower();
	void processEvent() const override;
};
#endif