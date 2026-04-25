#ifndef ENGINEER_H
#define ENGINEER_H

#include <string>

class Engineer {

private:
    std::string id;
    std::string name;
    std::string password;
    std::string clearanceLevel;

public:
    // Constructors
    Engineer();  // Default constructor
    Engineer(std::string newId,
        const std::string& newName,
        const std::string& newPassword,
        const std::string& newClearanceLevel);  // Parameterized constructor

    // Destructor
    ~Engineer();

    // Setters
    void setId(std::string newId);
    void setName(const std::string& newName);
    void setPassword(const std::string& pass);
    void setClearanceLevel(const std::string& clearance);

    // Getters
    std::string getId() const;
    std::string getName() const;
    std::string getPassword() const;
    std::string getClearanceLevel() const;
};

#endif