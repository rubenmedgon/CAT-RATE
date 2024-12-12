# Variables
SRC = ./src/Main.cpp ./src/Ventana.cpp ./src/Ficha.cpp ./src/Interfaz.cpp ./src/Arma.cpp ./src/Onomatopeya.cpp 
INCLUDE = -I./include
LIBS = -lsfml-graphics -lsfml-system -lsfml-window
EXEC = Game

# Reglas
all: $(EXEC)

$(EXEC): $(SRC)
	g++ $(SRC) $(INCLUDE) $(LIBS) -o $(EXEC)

run: all
	./$(EXEC)

clean:
	rm -f $(EXEC)