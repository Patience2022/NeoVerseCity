#include "EngineerManager.h"
#include <iostream>
#include <functional>
#include <vector>
#include <fstream>
#include <algorithm>
#include <sstream>
using namespace std;

Engineer EngineerManager::createEngineer()
{
    string id;
    string name;
    string password;
    string clearance;

    cout << "Enter Engineer ID: ";
    cin >> id;
    cout << "Enter Name: ";
    cin>> name;
    cout << "Enter Password: ";
    cin >> password;
    cout << "Enter Clearance Level: ";
    cin >> clearance;

    return Engineer(id, name, password, clearance);
}

void EngineerManager::addEngineer(Engineer& eng)
{
	hash<string> hasher;
    string encryptedPassword = to_string(hasher(eng.getPassword()));
	eng.setPassword(encryptedPassword);
	engineers.push_back(eng);
    ofstream engFile("engineers.dat", ios::app);
    engFile << eng.getId() << ", " << eng.getName() << ", " << encryptedPassword << ", " << eng.getClearanceLevel() <<endl;
}

Engineer* EngineerManager::searchEngineer(string id)
{
	return nullptr;
}

void EngineerManager::deleteEngineer(string id)
{
}

void EngineerManager::displayAll() const
{
}

Engineer* EngineerManager::logIn()
{
    string id;
    string password;
    cout << "Enter Engineer ID: ";
    cin >> id;
    cout << "Enter Password: ";
    cin >> password;
    hash<string> hasher;
    string encryptedPassword = to_string(hasher(password));
    auto it = find_if(engineers.begin(), engineers.end(), [&](const Engineer& eng) {
        return eng.getId() == id && eng.getPassword() == encryptedPassword;
        });
    if (it !=engineers.end()) {
        cout << "Logged in successfully";
        return &(*it);
    }
    else
    {
        cout << "You have supplied invalid credentials";
    }

    return nullptr;
}

void EngineerManager::loadEngineers()
{
    ifstream engFile("engineers.dat");
    if (!engFile) {
        cout << " File does not exist";
    }
    else {
        string line;
        while (getline(engFile, line)) {
            stringstream ss(line);
            string id;
            string name;
            string password;
            string clearance;

            getline(ss, id, ',');
            getline(ss, name, ',');
            getline(ss, password, ',');
            getline(ss, clearance,',');

            Engineer engineer(id, name, password, clearance);
            engineers.push_back(engineer);
            cout << engineer.getId()<<" " << engineer.getName() << " " << engineer.getPassword() << " " << engineer.getClearanceLevel() << endl;
        }
        engFile.close();
        cout<<engineers.size();
    }
}
