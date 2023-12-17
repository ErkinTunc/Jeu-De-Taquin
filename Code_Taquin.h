typedef struct {
    int size;  // Taille du côté du plateau (4 dans votre exemple)
    int **board;  // Tableau 2D de cases (pour chaque etape)
    int emptyLin;  // Ligne de la case vide
    int emptyCol;  // Colonne de la case vide
} GameBoard;


void AfficheTab2k(int ** tab,int ligne,int collone);

int ** CreationTab(int n);

void AffectFichier(GameBoard *T,const char *nomFichier);

void Melange(GameBoard *T);

void X_gauche(GameBoard *T);

void X_droite(GameBoard *T);

void X_VersLeHaut(GameBoard *T);

void X_VersLeBas(GameBoard *T);

void mouve(char lettre, GameBoard *T);

void AffectFichier(GameBoard *T,const char *nomFichier);

void EcrireFichier(GameBoard *table,const char *nomFichier);