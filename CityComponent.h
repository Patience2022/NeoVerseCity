#ifndef CITYCOMPONENT_H
#define CITYCOMPONENT_H
#include <string>
#include <iostream>


class CityComponent {
private:
    int componentId;
    std::string name;

public:
    CityComponent();
    CityComponent(int id, std::string name);
    void setComponentId(int id);
    int getComponentId() const;

    void setName(std::string compName);
    std:: string getName();

    void activate();
    void deactivate();

    std::string getStatus();

    virtual void processEvent() const;
    virtual ~CityComponent();
};

#endif
