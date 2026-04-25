#ifndef ENGINEERMANAGER_H
#define ENGINEERMANAGER_H

#include <vector>
#include "Engineer.h"

class EngineerManager {

private:
    std::vector<Engineer> engineers;

public:
    Engineer createEngineer();
    void addEngineer(Engineer& eng);
    Engineer* searchEngineer(std::string id);
    void deleteEngineer(std::string id);
    void displayAll() const;
    Engineer* logIn();
    void loadEngineers();
};

#endif