SRC = src/*.cpp ActiveForms/src/*.cpp
LIB = -lGL -lGLU -lSDL2
INC = -Iinclude -IActiveForms/include
build:
	g++ $(SRC) $(LIB) $(INC) -o bin/desktop/shockwaveplayer
	./bin/desktop/shockwaveplayer
build_web:
	em++ $(SRC) $(LIB) $(INC) -sUSE_SDL=2 -o bin/web/activefx_full.js
	