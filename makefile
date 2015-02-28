OBJ= GolVS.o Grid.o
CFLAGS= -std=c++14 -g

all: golvs

golvs: $(OBJ)
	g++ $(OBJ) $(CFLAGS) -o golvs

%.o: %.cpp
	g++ -c $(CFLAGS) $< -o $@
