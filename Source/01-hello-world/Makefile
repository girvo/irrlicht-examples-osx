all: hello

hello: main.cpp
	c++ -o hello -std=c++11 main.cpp -framework Cocoa -framework IOKit -framework OpenGL -lirrlicht -ljsoncpp

run: hello
	@./hello

.PHONY: all run
