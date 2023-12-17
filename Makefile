CC=gcc
FLAGS= -Wall
OBJECTS= Code_Taquin.o main.o
TARGET=Jeu_de_Taquin

all: $(TARGET)

$(TARGET): $(OBJECTS)
	$(CC) $(FLAGS) -o $@ $(OBJECTS)

Code_Taquin.o: Code_Taquin.c Code_taquin.h
	$(CC) $(FLAGS) -c $<

main.o: main.c Code_taquin.h
	$(CC) $(FLAGS) -c $<

