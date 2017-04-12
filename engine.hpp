#ifndef ENGINE_HPP
#define ENGINE_HPP

class Map;

class Object
{
public:
	char icon;
	unsigned int x ,y;
};

class Floor : public Object
{
public:
	static const char icon = '.';
};


class Wall : public Object
{
public:
	static const char icon = '#';
};


class Player : public Object
{
public:
	static const char icon = '@';
};


void clear();
void intro();
void playerInput(Player& player, Map& map);

#endif