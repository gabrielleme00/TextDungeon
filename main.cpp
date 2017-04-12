#include <iostream>
#include <stdlib.h>
#include <string>
#include "map.hpp"
#include "engine.hpp"

using namespace std;

int main()
{
	Player player;
	Map map;

	if(map.loadMap(player, "prologue.map") != 0)
	{
		cout << "Map loading error..." << endl;
		return -1;
	}

	intro();

	// Main game loop
	while(map.getStatus() == none)
	{
		map.printBoard();
		playerInput(player, map);
	}
	map.printBoard();

	if(map.getStatus() == win)
		cout << "You win!" << endl;
	else if(map.getStatus() == lose)
		cout << "You lose..." << endl;
	else
	{
		cout << "WTF?!" << endl;
		return -1;
	}

	return 0;
}