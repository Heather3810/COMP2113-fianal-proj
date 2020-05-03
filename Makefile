FLAGS = -pedantic-errors -std=c++11

item.o: item.cpp
		g++ $(FLAGS) -c item.cpp

roomnew.o: roomnew.cpp
		g++ $(FLAGS) -c roomnew.cpp

game.o: game.cpp
		g++ $(FLAGS) -c game.cpp

game: item.o roomnew.o game.o
		g++ game.o roomnew.o item.o -o game
