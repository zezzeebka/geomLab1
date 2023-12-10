#include "tictactoe.h"
#include "SFML/Graphics/CircleShape.hpp"
#include "SFML/Graphics/RectangleShape.hpp"
#include "SFML/Window/Event.hpp"

TicTacToe::TicTacToe() : player(Player::Cross)
{
    board.resize(SIZE, std::vector<Player>(SIZE, Player::None));
    restartWindow = std::make_shared<RestartWindow>();
}

void TicTacToe::draw(sf::RenderWindow& window)
{
    window.clear();
    for(int i = 0; i < SIZE; i++)
    {
        for(int j = 0; j < SIZE; j++)
        {
            sf::RectangleShape cell(sf::Vector2f(CELL_SIZE, CELL_SIZE));
            cell.setPosition(j * CELL_SIZE, i * CELL_SIZE);
            cell.setOutlineThickness(2);
            cell.setOutlineColor(sf::Color::Black);
            window.draw(cell);
            if (board[j][i] == Player::Cross) {
                //sf::RectangleShape line1(sf::Vector2f(150, 5));
                //sf::RectangleShape line2(sf::Vector2f(150, 5));
                //line1.rotate(45);
                //line2.rotate(135);
                sf::VertexArray cross(sf::Lines, 4);
                cross[0].position = sf::Vector2f(j * CELL_SIZE + 10, i * CELL_SIZE + 10);
                cross[1].position = sf::Vector2f((j + 1) * CELL_SIZE - 10, (i + 1) * CELL_SIZE - 10);
                cross[2].position = sf::Vector2f((j + 1) * CELL_SIZE - 10, i * CELL_SIZE + 10);
                cross[3].position = sf::Vector2f(j * CELL_SIZE + 10, (i + 1) * CELL_SIZE - 10);
                cross[0].color = sf::Color::Black;
                cross[1].color = sf::Color::Black;
                cross[2].color = sf::Color::Black;
                cross[3].color = sf::Color::Black;
                window.draw(cross);
            } else if (board[j][i] == Player::Circle) {
                sf::CircleShape circle(CELL_SIZE / 2 - 10);
                circle.setPosition(j * CELL_SIZE + 10, i * CELL_SIZE + 10);
                circle.setOutlineThickness(2);
                circle.setOutlineColor(sf::Color::Black);
                circle.setFillColor(sf::Color::Transparent);
                window.draw(circle);
            }

            //window.draw(cell);
        }
    }
    restartWindow->draw(window);

}
void TicTacToe::handleEvent(sf::Event& event)
{
    if(restartWindow->getVisible() == false){
        if (event.type == sf::Event::MouseButtonPressed && event.mouseButton.button == sf::Mouse::Left) {
            int mouseX = event.mouseButton.x / CELL_SIZE;
            int mouseY = event.mouseButton.y / CELL_SIZE;

            if (mouseX >= 0 && mouseX < SIZE && mouseY >= 0 && mouseY < SIZE && board[mouseX][mouseY] == Player::None) {

                board[mouseX][mouseY] = player;
                if(checkWin(mouseX, mouseY) != Player::None)
                {
                    restart();
                    restartWindow->setVisible(true);
                    restartWindow->getText()->setString((player == Player::Cross) ? "CROSS WINS" : "CIRCLE WINS");
                    player = Player::Circle;
                }
                player = (player == Player::Cross) ? Player::Circle : Player::Cross;

            }
        }
    }
     restartWindow->handleEvent(event);
}

void TicTacToe::restart()
{
    for(int i = 0; i < SIZE; i++)
    {
        for(int j = 0; j < SIZE; j++)
        {
            board[i][j] = Player::None;

        }
    }

}

Player TicTacToe::checkWin(int row, int col) {
    // Проверка по горизонтали
    for (int j = 0; j < SIZE; ++j) {
        if (board[row][j] != player) {
            break;
        }
        if (j == SIZE - 1) {
            return player;
        }
    }

    for (int i = 0; i < SIZE; ++i) {
        if (board[i][col] != player) {
            break;
        }
        if (i == SIZE - 1) {
            return player;
        }
    }

    if (row == col) {
        for (int i = 0; i < SIZE; ++i) {
            if (board[i][i] != player) {
                break;
            }
            if (i == SIZE - 1) {
                return player;
            }
        }
    }

    if (row + col == SIZE - 1) {
        for (int i = 0; i < SIZE; ++i) {
            if (board[i][SIZE - 1 - i] != player) {
                break;
            }
            if (i == SIZE - 1) {
                return player;
            }
        }
    }

    return Player::None;
}
