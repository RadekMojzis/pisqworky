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

bool Game::victory(){
	return false;
}

int Game::move(int x, int y){
	if(!playfield[x][y]){
		playfield[x][y] = player ? 'X' : 'O';
		player = !player;
	}
	draw();
	if(victory()){
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