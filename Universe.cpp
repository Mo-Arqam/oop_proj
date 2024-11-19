#include "Universe.h"
#include <cstdlib>
#include <ctime>
using namespace std;

// Constructor
Universe::Universe() {
        srand(time(nullptr)); // Seed for random number generation
}


// Load Background image
void Universe::generateBackground(const string& backgroundImagePath) {
    if (!backgroundTexture.loadFromFile(backgroundImagePath)) {
            throw std::runtime_error("Failed to load background image: " + backgroundImagePath);
        }
        backgroundSprite.setTexture(backgroundTexture);
    }


// Star Set up
void Universe::generateStars(int count){
    stars.clear();
    for (int i = 0; i < count; ++i){
        sf::CircleShape star(2.0f);
        star.setFillColor(sf::Color::White);
        star.setPosition(static_cast<float>(std::rand() % 800), static_cast<float>(std::rand() % 600));
        stars.push_back(star);
    }
}

// Draw Universe
void Universe::draw(sf::RenderWindow& window){
    window.draw(backgroundSprite);
    for (const auto& star : stars) { // range based loop idea from Chatgpt 4o
        window.draw(star);
    }
}
