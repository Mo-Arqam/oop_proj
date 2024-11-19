#include "PlanetBase.h"
#include <iostream>


PlanetBase::PlanetBase(const std::string& resource, int price)
    : tradeResource(resource), tradePrice(price), isActive(false) {
    planetShape.setRadius(40.0f);                // Radius of the planet
    planetShape.setFillColor(sf::Color::Blue);  // Default color
    planetShape.setOrigin(40.0f, 40.0f);        // Center the origin
}


void PlanetBase::spawn(float x, float y) {
    planetShape.setPosition(x, y);
    isActive = true;
}


void PlanetBase::deactivate() {
    isActive = false;
}


bool PlanetBase::checkCollision(const sf::Sprite& shipSprite) const {
    if (!isActive) return false;

    // Check bounding box collision between the ship and the planet
    return planetShape.getGlobalBounds().intersects(shipSprite.getGlobalBounds());
}


void PlanetBase::trade(int& playerResources, int& fuel) {
    if (playerResources >= tradePrice) {
        playerResources -= tradePrice;  // Deduct resources from the player
        fuel += 50;                    // Example: Add fuel to the ship
        std::cout << "Traded " << tradePrice << " resources for 50 fuel!" << std::endl;
    } else {
        std::cout << "Not enough resources to trade!" << std::endl;
    }
}


void PlanetBase::draw(sf::RenderWindow& window) {
    if (isActive) {
        window.draw(planetShape);
    }
}


bool PlanetBase::isPlanetActive() const {
    return isActive;
}
