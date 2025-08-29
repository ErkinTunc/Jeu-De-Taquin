# ---- Compiler & Flags ----
CC      := gcc
CFLAGS  := -Wall -Wextra -O2 -Iinclude
LDFLAGS :=

# ---- Paths ----
SRCDIR  := src
INCDIR  := include
BUILDDIR:= build
BINDIR  := bin
DATADIR := data

# ---- App ----
TARGET  := $(BINDIR)/Jeu_de_Taquin

# ---- Sources & Objects ----
SRC     := $(wildcard $(SRCDIR)/*.c)
OBJ     := $(patsubst $(SRCDIR)/%.c,$(BUILDDIR)/%.o,$(SRC))

# ---- Default ----
all: $(TARGET)

# ---- Link ----
$(TARGET): $(OBJ) | $(BINDIR)
	$(CC) $(OBJ) -o $@ $(LDFLAGS)

# ---- Compile ----
$(BUILDDIR)/%.o: $(SRCDIR)/%.c | $(BUILDDIR)
	$(CC) $(CFLAGS) -c $< -o $@

# ---- Dirs ----
$(BUILDDIR):
	mkdir -p $(BUILDDIR)

$(BINDIR):
	mkdir -p $(BINDIR)

# ---- Dev helpers ----
run: $(TARGET)
	./$(TARGET)

# If your program needs to read files from data/, it will find them via relative path "data/..."
# If you prefer to run from bin/, you can do: (cd $(BINDIR) && ./Jeu_de_Taquin)
run-in-bin: $(TARGET)
	cd $(BINDIR) && ./Jeu_de_Taquin

clean:
	rm -rf $(BUILDDIR) $(BINDIR)

.PHONY: all run run-in-bin clean
