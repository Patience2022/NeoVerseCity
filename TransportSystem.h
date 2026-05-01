#ifndef TRANSPORTSYSTEM_H
#define TRANSPORTSYSTEM_H

#include <string>
#include "CityComponent.h"

class TransportSystem : public CityComponent {
private:
    int trafficFlow;

public:
    // Constructors
    TransportSystem();
    TransportSystem(int id, string name,int newTrafficFlow);

    // Destructor
    ~TransportSystem();

    // Setter
    void setTrafficFlow(int flow);

    // Getter
    int getTrafficFlow() const;

    // Other methods
    void manageTraffic();
    void processEvent() const override;
};

#endif
