#include <iostream>
#include <iomanip>
#include <cstring>
#include <algorithm>
#include <vector>

namespace AppSettings {
	bool ant = false;
	void apply(std::vector<std::string> args){
		for (std::string arg: args){
			std::vector<std::string> option_ant = {
				"--ant",
			};
			if (
				std::any_of(
					std::begin(option_ant),
					std::end(option_ant), 
					[arg](std::string thing){return arg.compare(thing) == 0;}
				)
			){
				ant = true;
			}

		}
	}
}
