#include <iostream>
#include <chrono>
#include <ctime>
#include <thread>
#include <random>
#include <string>
#include <vector>
#include "ShadeThing.cpp"
#include "AppUtil.cpp"
#include "TerminalUtil.cpp"

void randomlyMove(){
	const char dirs[4] = {'A', 'B', 'C', 'D'};
	static short int dir;
	if (random() % 10 < 1){
		dir = (dir + (2 * (random() % 2)) + 1) % 4;
	}
	std::cout << "\e[1" << dirs[dir];
}

int *gradientalColorThing(){
	static ShadeThing shadeThing[3] = {
		/* red */ * new ShadeThing((int[2]){128, 255}, 0, 10),
		/* green */ * new ShadeThing((int[2]){128, 255}, 0, 10),
		/* blue */ * new ShadeThing((int[2]){128, 255}, 0, 10),
	};
	static int values[3];
	for (int i = 0; i < 3; i++){
		values[i] = shadeThing[i].iterate();
	}
	return values;
}

int main(int argc, char **argv) {
	int terminalSize[2] = {
		WEXITSTATUS(std::system("exit `tput lines`")), 
		WEXITSTATUS(std::system("exit `tput cols`"))
	};
	std::vector<std::string> args;
    for(int i = 1; i < argc; i++){
        args.push_back(argv[i]);   
    };
	AppSettings::apply(args);
	
	std::time_t now;
	srand(time(0));
	std::system("clear");
    std::cout << 
	  	"\e[" << terminalSize[0] / 2 << "B" <<
		"\e[" << terminalSize[1] / 2 << "C" << 
	std::flush;
	
	if (!AppSettings::ant){
		while (true){
			randomlyMove();
			TerminalUtil::setBackgroundColor(gradientalColorThing());
			std::cout << " \e[1D" << std::flush;
			std::this_thread::sleep_for(std::chrono::milliseconds(100));
		}
	} else {
		bool board[terminalSize[0]][terminalSize[1]];
		for (int i = 0; i < terminalSize[0]; i++){
			for (int j = 0; j < terminalSize[1]; j++){
				board[i][j] = false;
			}
		}
		while (true){
			int x, y;
			randomlyMove();
			TerminalUtil::fetchCursorPosition(&x, &y);
			board[x][y] = !board[x][y];
			if (board[x][y]){
				TerminalUtil::setBackgroundColor(gradientalColorThing());
			} else {
				TerminalUtil::setBackgroundColor((int[3]){0, 0, 0});
			}
			std::cout << " \e[1D" << std::flush;
			std::this_thread::sleep_for(std::chrono::milliseconds(100));
		}
	}
}
