OBJ= GolVS.o Grid.o GameOfLife.o
INC= GridInterface.h
CFLAGS= -std=c++14 -g

all: golvs

golvs: $(OBJ) #(INC)
	g++ $(OBJ) $(CFLAGS) -o golvs

%.o: %.cpp
	g++ -c $(CFLAGS) $< -o $@

clean:
	rm *.o golvs
