#ifndef RESTARTWINDOW_H
#define RESTARTWINDOW_H

#include "SFML/Graphics/RectangleShape.hpp"
#include "SFML/Graphics/RenderWindow.hpp"
#include "SFML/Graphics/Text.hpp"

class RestartWindow
{
private:
    sf::Text *text;
    sf::Font font;
    sf::RectangleShape windowBg;
    bool isVisible = 1;
public:
    RestartWindow();
    void draw(sf::RenderWindow& window);
    void handleEvent(sf::Event& event);
    bool getVisible();
    void setVisible(bool visibility);
    sf::Text* getText();
};

#endif // RESTARTWINDOW_H
