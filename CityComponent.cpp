#include <iostream>
#include "CityComponent.h"
using namespace std;

CityComponent::CityComponent()
{
}

CityComponent::CityComponent(int id, std::string name)
{
	componentId = id;
	this->name = name;
}

void CityComponent::setComponentId(int id)
{
	componentId = id;
}

int CityComponent::getComponentId() const
{
	return componentId;
}

void CityComponent::setName(string compName)
{
	name = compName;
}

string CityComponent::getName() const
{
	return name;
}

void CityComponent::activate()
{
	cout << name << " has been activated" << endl;
}

void CityComponent::deactivate()
{
	cout << name << " has been deactivated" << endl;
}

string CityComponent::getStatus()
{
	return "Status of "+name +" is : running";
}

CityComponent::~CityComponent()
{
}
