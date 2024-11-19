#include "Ship.h"
#include <iostream>
#include <stdexcept>

// Constructor
Ship::Ship(int health, int fuel, int resources)
    : health(health), fuel(fuel), resources(resources) {
    if (!texture.loadFromFile("ship.png")) {
        throw std::runtime_error("Failed to load ship texture");
    }
    sprite.setTexture(texture);
    sprite.setOrigin(sprite.getLocalBounds().width / 2, sprite.getLocalBounds().height / 2);
    sprite.setPosition(256, 512 - sprite.getLocalBounds().height / 2); // Position at the center of the bottom edge
}

// Update method: Handle player input for movement
void Ship::update() {
    float moveSpeed = 5.0f; // Speed at which the ship moves
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
        // Move left if not at the left edge
        if (sprite.getPosition().x > sprite.getLocalBounds().width / 2) {
            sprite.move(-moveSpeed, 0); // Move left
            if (fuel > 0) fuel--; // Decrease fuel on movement
        }
    }
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
        // Move right if not at the right edge
        if (sprite.getPosition().x < 512 - sprite.getLocalBounds().width / 2) {
            sprite.move(moveSpeed, 0); // Move right
            if (fuel > 0) fuel--; // Decrease fuel on movement
        }
    }
}

// Gathers resources
void Ship::gatherResources(int amount) {
    resources += amount;
    std::cout << "Gathered " << amount << " resources. Total: " << resources << std::endl;
}

// Upgrades ship parts
void Ship::upgradePart(const std::string& part) {
    if (resources >= 50) { // Example: Each upgrade costs 50 resources
        resources -= 50;
        if (part == "health") {
            health += 20;
            std::cout << "Health upgraded! New health: " << health << std::endl;
        } else if (part == "fuel") {
            fuel += 30;
            std::cout << "Fuel capacity increased! New fuel: " << fuel << std::endl;
        } else {
            std::cout << "Unknown upgrade part: " << part << std::endl;
        }
    } else {
        std::cout << "Not enough resources to upgrade!" << std::endl;
    }
}

// Accessors
int Ship::getHealth() const {
    return health;
}

int Ship::getFuel() const {
    return fuel;
}

int Ship::getResources() const {
    return resources;
}

// Mutators
void Ship::setHealth(int h) {
    health = h;
}

void Ship::setFuel(int f) {
    fuel = f;
}

void Ship::setResources(int r) {
    resources = r;
}
