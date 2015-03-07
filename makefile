LDFLAGS := -lpthread -lgtest -lgtest_main -lsfml-graphics -lsfml-window -lsfml-system
CFLAGS= -std=c++14 -g

MAIN= bin/GolVS.o
OBJ= bin/Grid.o bin/GameOfLife.o bin/SFMLVisualGrid.o
INC= -I include
TEST= tests/tests.Grid.o tests/tests.Main.o tests/tests.GameOfLife.cpp


all: golvs test

golvs: $(OBJ) $(MAIN)
	g++ $(OBJ) $(MAIN) $(INC) $(LDFLAGS) $(CFLAGS) -o golvs

bin/%.o: src/%.cpp
	g++ -c $(CFLAGS) $(INC) $< -o $@

tests/%.o: tests/%.cpp
	g++ -c $(CFLAGS) $(INC) $< -o $@

clean:
	rm -r bin/*.o tests/*.o golvs test

test: $(TEST) $(OBJ)
	g++ $(TEST) $(OBJ) $(INC) $(CFLAGS) $(LDFLAGS) -o test
   
