#include <string>
#include <iostream>
#include <fstream>
#include "map.hpp"
#include "engine.hpp"

using namespace std;

const char wallTile = '#';
const char objectiveTile = 'X';
const char floorTile = '.';

int Map::loadMap(Player& player, string mapName)
{
	bool playerFound = false;

	// Read and store map
	ifstream file(mapName);

	file >> boardSizeX;
	file >> boardSizeY;

	if(file.is_open())
	{
		for(unsigned int x = 0; x < boardSizeX; ++x)
		{
			for(unsigned int y = 0; y < boardSizeY; ++y)
			{
				file >> board[x][y].icon;
				if(board[x][y].icon == player.icon)
				{
					if(playerFound == true)
						return -1;
					playerFound = true;

					player.x = x;
					player.y = y;
				}
			}
		}
	}

	return 0;
}

void Map::move(Player& player, char movement)
{
	if (movement == 'L' && player.y > 0)
	{
		if(board[player.x][player.y-1].icon == wallTile)
			return;
		else if(board[player.x][player.y-1].icon == objectiveTile)
			gameStatus = win;
		board[player.x][player.y-1].icon= player.icon;
		board[player.x][player.y].icon= floorTile;
		player.y--;
	}
	else if (movement == 'U' && player.x > 0)
	{
		if(board[player.x-1][player.y].icon== wallTile)
			return;
		else if(board[player.x-1][player.y].icon== objectiveTile)
			gameStatus = win;
		board[player.x-1][player.y].icon= player.icon;
		board[player.x][player.y].icon= floorTile;
		player.x--;
	}
	else if (movement == 'R' && player.y < boardSizeY-1)
	{
		if(board[player.x][player.y+1].icon== wallTile)
			return;
		else if(board[player.x][player.y+1].icon== objectiveTile)
			gameStatus = win;
		board[player.x][player.y+1].icon= player.icon;
		board[player.x][player.y].icon= floorTile;
		player.y++;
	}
	else if (movement == 'D' && player.x < boardSizeX-1)
	{
		if(board[player.x+1][player.y].icon== wallTile)
			return;
		if(board[player.x+1][player.y].icon== objectiveTile)
			gameStatus = win;
		board[player.x+1][player.y].icon= player.icon;
		board[player.x][player.y].icon= floorTile;
		player.x++;
	}
}

void Map::printControls()
{
	cout << endl;
	cout << "╔═══════════════════════╗" << endl;
	cout << "║   Movement controls   ║" << endl;
	cout << "╠═══════════════════════╣" << endl;
	cout << "║     W           ▲     ║" << endl;
	cout << "║   A + D   =   ◀ + ▶   ║" << endl;
	cout << "║     S           ▼     ║" << endl;
	cout << "╚═══════════════════════╝" << endl;
	cout << endl;
	cout << "Next move: ";
}

void Map::printBoard()
{
	clear();

	// Prints upper outer wall
	for (unsigned int i = 0; i <= boardSizeY; ++i)
		cout << "██";
	cout << "██" << endl;

	// Pints board and side outer walls
	for(unsigned int x = 0; x < boardSizeX; ++x)
	{
		cout << "██";
		for (unsigned int y = 0; y < boardSizeY; ++y)
		{
			cout << board[x][y].icon<< " ";
		}

		cout << "██" << endl;
	}

	// Prints bottom outer walls
	for (unsigned int i = 0; i <= boardSizeY; ++i)
		cout << "██";
	cout << "██" << endl;

	printControls();
}

int Map::getStatus()
{
	return gameStatus;
}