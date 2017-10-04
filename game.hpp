#pragma once
#include <vector>
/**
 * \class Card represents the game field.
 * \var 
 */

class Game{
		void draw();
		bool victory();
		std::vector<std::vector<int>> playfield;
		bool player;
	public:
		Game():player{true}, playfield{std::vector<std::vector<int>>(15, std::vector<int>(15, 0))}{};
		int move(int x, int y);
		int newgame();
		
};
