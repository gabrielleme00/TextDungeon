#ifndef MAP_HPP
#define MAP_HPP

#include <string>
#include "engine.hpp"

enum GameSatus {none, win, lose};

class Map
{
private:
	unsigned int boardSizeX;
	unsigned int boardSizeY;
	GameSatus gameStatus = none;

public:
	Object board[255][255];

	int loadMap(Player& player, std::string mapName);
	void move(Player& player, char movement);
	void printControls();
	void printBoard();
	int getStatus();
};

#endif