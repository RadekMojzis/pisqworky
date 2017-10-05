#include <iostream>
#include "game.hpp"

using namespace std;

int main(void){
	Game game = Game();
	
	while(true){
		int x, y;
		cin >> x >> y;
		if(game.move(x, y)){
			cout << "New game commencing!" << endl;
			game.newgame();
		}
	}
	
	return 0;
}