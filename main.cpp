#include <SFML/Graphics.hpp>
#include <memory>
#include "restartwindow.h"
#include "tictactoe.h"

int main() {

    sf::RenderWindow window(sf::VideoMode(SIZE * CELL_SIZE, SIZE * CELL_SIZE), "Tic Tac Toe", sf::Style::Titlebar | sf::Style::Close);

    std::unique_ptr<TicTacToe> game = std::make_unique<TicTacToe>();
    std::shared_ptr<RestartWindow> restart = std::make_shared<RestartWindow>();
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed) {
                window.close();
            }

            game->handleEvent(event);
            //restart->handleEvent(event);
        }

        game->draw(window);
        //restart->draw(window);
        window.display();
    }

    return 0;
}
