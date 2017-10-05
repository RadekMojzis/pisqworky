#include "game.hpp"
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

void Game::draw(){
	cout << " ";
	for(int i = 0; i < 15; i++)
		cout << setw(3) << i;
	cout << endl;
	
	for(int i = 0; i < 15; i++){
		cout << setw(2) << i;
		for(int j = 0; j < 15; j++){
			if(playfield[i][j]){
				cout << "[" << (char) playfield[i][j] << "]";
			}
			else{
				cout << "[ ]";
			}
		}
		cout << std::endl;
	}
}

bool Game::count_symbol(int in){
	static int count = 0;
	static int symbol;
	if(in == 0){
		count = 0;
		return false;
	}
	if(count){
		if(symbol == in){
			count ++;
			if(count == 5){
				return true;
			}
		}
		else{
			symbol = in;
			count = 1;
		}
	}
	else{
		symbol = in;
		count = 1;
	}
	return false;
}

bool Game::victory(int x, int y){
	int symbol;
	for(int i = 0; i < 15; i++){
		if(count_symbol(playfield[i][y]))
			return true;
	}

	count_symbol(0);
	for(int i = 0; i < 15; i++){
		if(count_symbol(playfield[x][i]))
			return true;
	}
	
	// rising diagonal
	int d_num = x+y;
	count_symbol(0);
	
	if(d_num < 15){
		for(int i = d_num, j = 0; i >= 0; i--, j++){
			if(count_symbol(playfield[i][j]))
				return true;
		}
	}
	else{
		for(int i = 14, j = d_num - 15; j < 15; i--, j++){
			if(count_symbol(playfield[i][j]))
				return true;
		}
	}
	
	d_num = x-y;
	count_symbol(0);
	if(d_num < 0){
		for(int j = -d_num, i = 0; j >15; i++, j++){
			if(count_symbol(playfield[i][j]))
				return true;
		}
	}
	else{
		for(int i = d_num, j = 0; i < 15; i++, j++){
			if(count_symbol(playfield[i][j]))
				return true;
		}
	}
	
	return false;
}

int Game::move(int y, int x){
	if(x > 14 || y > 14)
		return 0;
	if(!playfield[x][y]){
		playfield[x][y] = player ? 'X' : 'O';
		player = !player;
	}
	draw();
	if(victory(x, y)){
		cout << "Player: " << (player ? 'X' : 'O') << " won!" << endl;
		return 1;
	}
	return 0;
}

int Game::newgame(){
	player = false;
	playfield = std::vector<std::vector<int>>(15, std::vector<int>(15, 0));
	draw();
}