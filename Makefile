CC=gcc
CFLAGS=-c -Wall -I "Jeu-De-Taquin/src/include/SDL2"
LDFLAGS=-L "Jeu-De-Taquin/src/lib" -lmingw32 -lSDL2main -lSDL2
SOURCES= main.c Code_Taquin.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=JeuDeTaquin

.PHONY : all clean

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
    $(CC) $(OBJECTS) -o $@ $(LDFLAGS)

*.o: *.c
    $(CC) $(CFLAGS) $< -o $@

clean :
    rm -f $(OBJECTS) $(EXECUTABLE)