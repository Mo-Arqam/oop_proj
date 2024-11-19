#ifndef PLANETBASE_H
#define PLANETBASE_H

#include <SFML/Graphics.hpp>
#include <string>
using namespace std;

class PlanetBase {
private:
    sf::CircleShape planetShape;
    string tradeResource;
    int tradePrice;
    bool isActive;
    
    
public:
    PlanetBase(const string& resource, int price);
    
    void spawn(float x,float y);
    void deactivate();
    bool checkCollision(const sf::Sprite& shipSprite) const;
    
    void trade(int& playerResources, int& fuel);
    void draw(sf::RenderWindow& window);
    
    bool isPlanetActive() const;
    
};
#endif
