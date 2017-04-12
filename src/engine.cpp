#include <iostream>
#include <string>
#include "engine.hpp"
#include "map.hpp"

using namespace std;

void clear()
{
	
	system("clear");
}

void intro()
{
	clear();

	cout << "╔══════════════════════════════════════╗" << endl;
	cout << "║     Welcome to the Text Dungeon!     ║" << endl;
	cout << "╠══════════════════════════════════════╣" << endl;
	cout << "║                       /^\\            ║" << endl;
	cout << "║                       | |            ║" << endl;
	cout << "║                       |-|            ║" << endl;
	cout << "║                  /^\\  | |            ║" << endl;
	cout << "║           /^\\  / [_] \\+-+            ║" << endl;
	cout << "║          |---||-------| |            ║" << endl;
	cout << "║ _/^\\_    _/^\\_|  [_]  |_/^\\_   _/^\\_ ║" << endl;
	cout << "║ |___|    |___||_______||___|   |___| ║" << endl;
	cout << "║  | |======| |===========| |=====| |  ║" << endl;
	cout << "║  | |      | |    /^\\    | |     | |  ║" << endl;
	cout << "║  | |      | |   |   |   | |     | |  ║" << endl;
	cout << "║  |_|______|_|__ |   |___|_|_____|_|  ║" << endl;
	cout << "║                                      ║" << endl;
	cout << "║                             ZetaMek  ║" << endl;
	cout << "╚══════════════════════════════════════╝" << endl;

	system("read");
	clear();
}

void playerInput(Player& player, Map& map)
{
	string input;

	cin >> input;

	switch(input[0])
	{
		case 'a':
		case 'A':
			map.move(player, 'L');
			break;
		case 'w':
		case 'W':
			map.move(player, 'U');
			break;
		case 'd':
		case 'D':
			map.move(player, 'R');
			break;
		case 's':
		case 'S':
			map.move(player, 'D');
			break;
		default:
			break;
	}
}