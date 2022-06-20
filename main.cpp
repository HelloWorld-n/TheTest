#include <iostream>
#include <chrono>
#include <ctime>
#include <thread>
#include <random>
#include <string>
#include <vector>
#include "ShadeThing.cpp"

void setBackroundColor(int rgb_values[3]){
	std::cout << "\e[48;2;" << rgb_values[0] << ";" << rgb_values[1] << ";" << rgb_values[2] << "m";
}

void setForegroundColor(int rgb_values[3]){
	std::cout << "\e[38;2;" << rgb_values[0] << ";" << rgb_values[1] << ";" << rgb_values[2] << "m";
}

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
	std::time_t now;
	srand(time(0));
	std::system("clear");
    std::cout << 
		"\e[" << WEXITSTATUS(std::system("exit `tput cols`")) / 2 << "C" << 
	  	"\e[" << WEXITSTATUS(std::system("exit `tput lines`")) / 2 << "B" <<
	std::flush;
	
	while (true){
		setBackroundColor(gradientalColorThing());
		std::cout << " \e[1D" << std::flush;
		randomlyMove();
		std::this_thread::sleep_for(std::chrono::milliseconds(100));
	}
}
