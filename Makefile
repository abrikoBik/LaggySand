default:
	g++ -Wall -g main.cpp game.cpp pixel.cpp -I. -IC:/mingw64/include/SDL2 -LC:/mingw64/lib -lmingw32 -lSDL2main -lSDL2 -o main