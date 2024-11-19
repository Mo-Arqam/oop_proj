#include "Entity.h"

// Default destructor (provided explicitly for clarity)
Entity::~Entity() {}

// Common draw logic
void Entity::draw(sf::RenderWindow& window) const {
    window.draw(sprite); // Draw the sprite
}

// Returns the bounding box of the entity
sf::FloatRect Entity::getBounds() const {
    return sprite.getGlobalBounds();
}

// Returns the position of the entity
sf::Vector2f Entity::getPosition() const {
    return sprite.getPosition();
}

// Sets the position of the entity
void Entity::setPosition(float x, float y) {
    sprite.setPosition(x, y);
}

// Collision detection with another entity
bool Entity::isCollidingWith(const Entity& other) const {
    return this->getBounds().intersects(other.getBounds());
}
