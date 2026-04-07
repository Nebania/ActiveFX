all: build

CXX = g++
SRC= shockwave/src/*.cpp linkscript/src/*.cpp
INC = -Iinclude/ -Ishockwave/include/ -Ilinkscript/include
LIB =  -lSDL2 -lpugixml -lSDL2_image
BIN = -o bin/desktop/shockwave  
WBIN = -o bin/web/activefx.js
build:	
	$(CXX) $(SRC) $(INC) $(LIB) $(BIN)
