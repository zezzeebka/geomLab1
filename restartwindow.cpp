#include "restartwindow.h"
#include "SFML/Graphics/RectangleShape.hpp"
#include "SFML/Window/Event.hpp"
#include <SFML/Graphics/Rect.hpp>
RestartWindow::RestartWindow()
{

    if (!font.loadFromFile("arial.ttf"))
    {
        // Error...
    }
    text = new sf::Text();
    text->setFont(font);
    text->setPosition(230, 288);
    text->setCharacterSize(24);
    text->setFillColor(sf::Color::Red);
    windowBg = sf::RectangleShape(sf::Vector2f(300, 300));
    windowBg.setFillColor(sf::Color::Black);
    windowBg.setPosition(150,150);
}


void RestartWindow::draw(sf::RenderWindow& window)
{
    if(isVisible)
    {
        window.draw(windowBg);
        window.draw(*text);
    }
}

void RestartWindow::handleEvent(sf::Event& event)
{
    if(isVisible){
        if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
            int mouseX = event.mouseButton.x;
            int mouseY = event.mouseButton.y;

            if (mouseX >= windowBg.getPosition().x && mouseX < windowBg.getPosition().x + windowBg.getSize().x && mouseY >= windowBg.getPosition().y && mouseY < windowBg.getPosition().y + windowBg.getSize().y) {
                isVisible = 0;
            }
        }
    }
}

bool RestartWindow::getVisible()
{
    return isVisible;
}

void RestartWindow::setVisible(bool visibility)
{
    isVisible = visibility;
}

sf::Text* RestartWindow::getText()
{
    return text;
}
