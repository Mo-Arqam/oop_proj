#include <SFML/Graphics.hpp>
#include "Universe.h"
#include "Ship.h"
#include "PlanetBase.h"

enum GameState {
    Menu,
    Game
};

int main() {
    sf::RenderWindow window(sf::VideoMode(512, 512), "SPACE ADVENTURE");
    window.setFramerateLimit(60);

    // Load Background
    sf::Texture backgroundTexture;
    if (!backgroundTexture.loadFromFile("space_background.png")) {
        return -1;  // Error handling
    }
    sf::Sprite background(backgroundTexture);

    // Load Font
    sf::Font font;
    if (!font.loadFromFile("arial.ttf")) {
        return -1;  // Error handling
    }

    // Title Text
    sf::Text title("SPACE ADVENTURE", font, 40);
    title.setPosition(50, 50);  // Adjust position as needed
    title.setFillColor(sf::Color::White);  // Text color

    // Main Menu Button setup
    sf::RectangleShape button(sf::Vector2f(300.f, 100.f));
    button.setFillColor(sf::Color(255, 255, 0, 200));  // Yellow button
    button.setPosition((512 - 300) / 2, (512 - 100) / 2);  // Centered

    // Main Menu Button Text
    sf::Text buttonText("Click to Play", font, 30);
    float textWidth = buttonText.getLocalBounds().width;
    float textHeight = buttonText.getLocalBounds().height;
    buttonText.setPosition(((512 - textWidth) / 2), ((512 - 100) / 2 + (100 - textHeight) / 2 - textHeight / 4));
    buttonText.setFillColor(sf::Color::Black);

    // Initialize game components
    Universe gameUniverse;
    gameUniverse.generateBackground("space_background.png");
    gameUniverse.generateStars(100); // Generating stars

    Ship playerShip; // Initialize ship
    PlanetBase homePlanet("Ore", 50); // Example planet
    homePlanet.spawn(256, 256); // Spawning the planet at the center

    // Game state
    GameState currentState = Menu;

    // Main loop
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();

            if (currentState == Game) {
                playerShip.update(); // Update ship based on user input
            }
            

            // Handle mouse click for menu and game screen
            if (event.type == sf::Event::MouseButtonPressed) {
                if (event.mouseButton.button == sf::Mouse::Left) {
                    sf::Vector2f mousePos = static_cast<sf::Vector2f>(sf::Mouse::getPosition(window));
                    if (currentState == Menu && button.getGlobalBounds().contains(mousePos)) {
                        currentState = Game;  // Change state when main menu button is clicked
                    }
                }
            }
        }

        window.clear(); // Clear the screen

        if (currentState == Menu) {
            window.draw(background); // Draw the background
            window.draw(title); // Draw the title
            window.draw(button); // Draw the button
            window.draw(buttonText); // Draw the button text
        } else if (currentState == Game) {
            gameUniverse.draw(window); // Draw universe
            playerShip.draw(window); // Draw ship
            homePlanet.draw(window); // Draw home planet
        }

        window.display(); // Update the window
    }

    return 0;
}