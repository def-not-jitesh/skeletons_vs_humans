CC := g++
OBJ := player.o enemy.o main.o fps.o bullets.o math.o map.o
FLAGS := -lsfml-graphics -lsfml-system -lsfml-window 
BINARY := game

all: $(BINARY)

$(BINARY): $(OBJ)
	$(CC) $(FLAGS) $^ -o $(BINARY)

%.o: %.cpp
	$(CC) $^ -c -o $@ 

clean: 
	rm $(BINARY) $(OBJ)
