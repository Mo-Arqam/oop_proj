#ifndef ENTITY_H
#define ENTITY_H

#include <SFML/Graphics.hpp>

class Entity {
protected:
    sf::Sprite sprite;
    sf::Texture texture;

public:
    virtual ~Entity();

    virtual void update() = 0;   // Pure virtual function for updating behavior
    virtual void draw(sf::RenderWindow& window) const; // Draws the entity

    sf::FloatRect getBounds() const;      // Returns the bounding box of the entity
    sf::Vector2f getPosition() const;     // Returns the entity's position
    void setPosition(float x, float y);   // Sets the entity's position

    bool isCollidingWith(const Entity& other) const; // Checks for collision with another entity
};

#endif // ENTITY_H
