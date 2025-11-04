# Jeu-De-Taquin (Sliding Puzzle Game)

## Overview

_Jeu de Taquin_ (15-puzzle) is a classic sliding tile game implemented in **C**.  
Your goal: slide the numbered tiles into the empty space until the board is solved.

Features:

- Multiple board sizes (**4×4, 5×5, 6×6**)
- Randomly shuffled puzzles
- Load saved puzzles (`facile.txt`, `moyenne.txt`, `difficile.txt`)
- Interactive terminal interface with dynamic updates (clear screen, board rendering).

---

## Project Structure

```
Jeu-De-Taquin/
├── bin/                 # Compiled executable
├── build/               # Object files
├── data/                # Puzzle states
│   ├── facile.txt       # Easy (4×4)
│   ├── moyenne.txt      # Medium (5×5)
│   └── difficile.txt    # Hard (6×6)
├── docs/                # Documentation & report
├── include/             # Header files
├── src/                 # Source code
├── Makefile             # Build automation
└── README.md            # Project info
```

---

## Installation & Run

### Linux / macOS

```sh
git clone <repository_url>
cd Jeu-De-Taquin
make
./bin/Jeu_de_Taquin
```

### Windows (MSYS2 / MinGW)

```powershell
git clone <repository_url>
cd Jeu-De-Taquin
make
.bin\Jeu_de_Taquin.exe
```

> ⚠ Requires `gcc` and `make`. On Windows, install [MSYS2](https://www.msys2.org/) or MinGW.

---

## Gameplay

### Menu

```
1. Play new game
2. Load saved game
3. Options (choose board size)
4. Quit
```

### Controls

- **G** → (Gauche = Left)
- **D** → (Droite = Right)
- **H** → (Haut = Up)
- **B** → (Bas = Down)
- **Q** → Quit

### 🖼️ Example Board

```
   +----+----+----+----+
   |  1 |  5 |  X |  3 |
   +----+----+----+----+
   |  2 |  4 |  6 |  8 |
   +----+----+----+----+
   |  9 | 10 |  7 | 11 |
   +----+----+----+----+
   | 13 | 14 | 15 | 12 |
   +----+----+----+----+
```

---

## Troubleshooting

- **`make: command not found`**

  - Ubuntu/Debian → `sudo apt install build-essential`
  - macOS → `xcode-select --install`
  - Windows → Install MSYS2/MinGW

- **Executable won’t run**
  - Linux/macOS → `./bin/Jeu_de_Taquin`
  - Windows → `.bin\Jeu_de_Taquin.exe`

---

## Roadmap

- [x] Add victory detection & score tracking  
- [x] Improve shuffle → always solvable puzzles  
- [ ] Undo/redo functionality  
- [ ] Ncurses UI for colorful display  
- [ ] Automated solver (A*) 

---

## License

This project is licensed under the **MIT License**.

---

## Contributing

Contributions, issues, and suggestions are welcome!  
Fork this repo, create a branch, and submit a PR.
