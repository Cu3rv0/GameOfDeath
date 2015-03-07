LDFLAGS := -lpthread -lgtest -lgtest_main
CFLAGS= -std=c++14 -g

MAIN= bin/GolVS.o
OBJ= bin/Grid.o bin/GameOfLife.o
INC= -I include/
TEST= tests/tests.Grid.o tests/tests.Main.o tests/tests.GameOfLife.cpp


all: golvs test

golvs: $(OBJ) $(MAIN)
	g++ $(OBJ) $(MAIN) $(INC) $(CFLAGS) -o golvs

bin/%.o: src/%.cpp
	g++ -c $(CFLAGS) $(INC) $< -o $@

tests/%.o: tests/%.cpp
	g++ -c $(CFLAGS) $(INC) $< -o $@

clean:
	rm -r bin/*.o tests/*.o golvs test

test: $(TEST) $(OBJ)
	g++ $(TEST) $(OBJ) $(INC) $(CFLAGS) $(LDFLAGS) -o test
   
