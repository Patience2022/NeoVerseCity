#ifndef SECURITYSYSTEM_H
#define SECURITYSYSTEM_H
#include <iostream>
using namespace std;
#include "CityComponent.h"
class SecuritySystem : public CityComponent {
private:
	int threatLevel;
public:
	SecuritySystem();
	SecuritySystem(int id, string name,int newThreatLevel);
	~SecuritySystem();
	void setThreatLevel(int level);
	int getThreatLevel() const;
	void monitorCity();
	void processEvent() const override;
};
#endif