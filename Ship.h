#ifndef SHIP_H
#define SHIP_H

#include "Entity.h"
#include <string>

class Ship : public Entity {
private:
    int health;
    int fuel;
    int resources;

public:
    Ship(int health = 100, int fuel = 100, int resources = 0);

    void update() override; // Update method for player input and movement
    void gatherResources(int amount); // Collect resources
    void upgradePart(const std::string& part); // Upgrade ship parts

    // Accessors
    int getHealth() const;
    int getFuel() const;
    int getResources() const;

    // Mutators
    void setHealth(int h);
    void setFuel(int f);
    void setResources(int r);
};

#endif // SHIP_H
