#include <iostream>
#include "game.hpp"

using namespace std;

int main(void){
	Game game = Game();
	
	while(true){
		int x, y;
		cin >> x >> y;
		game.move(x, y);
	}
	
	return 0;
}