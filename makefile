FLAGS = -lsfml-system -lsfml-window -lsfml-graphics -IHeader -Wall -std=c++14

MAIN_FILES = main.o Settings.o Game.o GameField.o Cell.o

main.exe: $(MAIN_FILES)
	g++ $(MAIN_FILES) $(FLAGS) -o main.exe

main.o: Source\main.cpp Source\Game.cpp Header\Game.hpp Source\Settings.cpp Header\Settings.hpp
	g++ $< $(FLAGS) -c 

Settings.o: Source\Settings.cpp Header\Settings.hpp
	g++ $< $(FLAGS) -c

Game.o: Source\Game.cpp Header\Game.hpp Source\GameField.cpp Header\GameField.hpp Source\Settings.cpp Header\Settings.hpp
	g++ $< $(FLAGS) -c

GameField.o: Source\GameField.cpp Header\GameField.hpp
	g++ $< $(FLAGS) -c

Cell.o: Source\Cell.cpp Header\Cell.hpp
	g++ $< $(FLAGS) -c