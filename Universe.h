#ifndef UNIVERSE_H
#define UNIVERSE_H

#include <SFML/Graphics.hpp>
#include <vector>

class Universe {
private:
    sf::Texture backgroundTexture; // Texture for the static background
    sf::Sprite backgroundSprite;   // Sprite to display the background
    std::vector<sf::CircleShape> stars; // A collection of stars for decorative effects

public:
    Universe();

    void generateBackground(const std::string& backgroundImagePath); // Loads the background image
    void generateStars(int count); // Randomly generates stars on the screen
    void draw(sf::RenderWindow& window); // Draws the background and stars
};

#endif 
