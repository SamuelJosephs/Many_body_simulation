

cc := g++

make: main.cpp main.h Vector.cpp Star.cpp
	$(cc) main.cpp main.h Vector.cpp Star.cpp -O3 -Wall -lSDL2main -lSDL2 -o Galaxy