namespace TerminalUtil{
	void setBackgroundColor(int rgb_values[3]){
		std::cout << "\e[48;2;" << rgb_values[0] << ";" << rgb_values[1] << ";" << rgb_values[2] << "m";
	}

	void setForegroundColor(int rgb_values[3]){
		std::cout << "\e[38;2;" << rgb_values[0] << ";" << rgb_values[1] << ";" << rgb_values[2] << "m";
	}

	void fetchCursorPosition(int *x, int *y){
		*x = WEXITSTATUS(std::system("./fetchCursorPosition.sh ROW"));
		*y = WEXITSTATUS(std::system("./fetchCursorPosition.sh COLUMN"));
	}
}
