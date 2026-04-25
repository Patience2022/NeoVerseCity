#include <iostream>
#include "Engineer.h"
using namespace std;

Engineer::Engineer()
{
}

Engineer::Engineer(string newId, const string& newName, const string& newPassword, const string& newClearanceLevel)
{	
	id = newId;
	name = newName;
	password = newPassword;
	clearanceLevel = newClearanceLevel;
}

Engineer::~Engineer()
{
}

void Engineer::setId(string newId)
{
	id = newId;
}

void Engineer::setName(const string& newName)
{
	name = newName;
}

void Engineer::setPassword(const string& pass)
{
	password = pass;
}

void Engineer::setClearanceLevel(const string& clearance)
{
	clearanceLevel = clearance;
}

string Engineer::getId() const {
	return id;
}

string Engineer:: getName() const { 
	return name;
}

string Engineer::getPassword() const {
	return password; 
}

string Engineer::getClearanceLevel() const {
	return clearanceLevel; 
}
