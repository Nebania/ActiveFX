all: build

CXX = g++
SRC= src/*.cpp ../linkscript/src/*.cpp
INC = -Iinclude/ -I../linkscript/include
LIB =  -lSDL2 -lpugixml -lSDL2_image
BIN = -o bin/desktop/shockwave  

build:	
	$(CXX) $(SRC) $(INC) $(LIB) $(BIN)
run:
	cd bin/desktop
	./shockwave app.xml