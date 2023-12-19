all:
	g++ -Wall -std=c++11 -Iinclude -o tictactoe main.cpp tictactoefunctions.cpp -lncurses


clean:
	rm tictactoe
