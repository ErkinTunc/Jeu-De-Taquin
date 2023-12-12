CC=gcc
CFLAGS=-c -Wall -I "Jeu-De-Taquin/src/include/SDL2" 
LDFLAGS=-LJeu-De-Taquin/src/lib -lmingw32 -lSDL2main -lSDL2
SOURCES=Jeu-De-Taquin/main.c
OBJECTS=$(SOURCES:.c=.o)
EXECUTABLE=JeuDeTaquin

.PHONY : all clean

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
    $(CC) $(LDFLAGS) $(OBJECTS) -o $@

.c.o:
    $(CC) $(CFLAGS) $< -o $@

clean :
    rm -f $(OBJECTS) $(EXECUTABLE)
