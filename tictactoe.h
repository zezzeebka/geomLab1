#ifndef TICTACTOE_H
#define TICTACTOE_H

#include "restartwindow.h"
#include <memory>
static int SIZE = 3;
static int CELL_SIZE = 200;
enum class Player { None, Cross, Circle };

#include "SFML/Graphics/RenderWindow.hpp"
class TicTacToe
{
private:
    std::vector<std::vector<Player>> board;
    Player player;
    std::shared_ptr<RestartWindow> restartWindow;
    Player checkWin(int row, int col);
public:
    TicTacToe();
    void draw(sf::RenderWindow& window);
    void handleEvent(sf::Event& event);
    void restart();

};

#endif // TICTACTOE_H
