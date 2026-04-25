#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "HealthSystem.h"
#include "PowerSystem.h"
#include "TransportSystem.h"
#include "SecuritySystem.h"
#include "Engineer.h"
#include "EngineerManager.h"
using namespace std;

int main()
{
    HealthSystem health;
    PowerSystem power;
    TransportSystem transport;
    SecuritySystem security;
    Engineer enginer;
    EngineerManager engManager;

    //Adding or creating engineer. Done by admin
     enginer = engManager.createEngineer();
     engManager.addEngineer(enginer);
     
    //Login Functionality
     engManager.logIn();
    
    //engManager.loadEngineers();
    
  

    return 0;
}

