#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include "Code_Taquin.h"

// Pour tout le fonction le numero 0 reperesente CaseVide


// === Fonction Pour Tester Et Affichage ===

void AfficheTab2k(int ** tab,int ligne,int collone){ // utiliser les table qui a le taille moins que 100 pour bien fonctionment
	
	// Test d'existence
	if(tab == NULL){
		 fprintf(stderr, "Error: The input array is NULL.\n");
		return;
	}
	
	int i=0,j=0;
	for(i=0;i<ligne;i++){
		for(j=0;j<collone;j++){			
				if (tab[i][j] == 0){ // '0' represante le case vide
				printf("   X"); // trois fois "space"  // ici a place de 0 nous écrivons 'X'
				}
				else if (tab[i][j]<10){
					printf("  %d ",tab[i][j]); // avant deux fois "space", apres une fois  
				}
				else{
					printf(" %d",tab[i][j]); // une fois "space"  
				}		
		}
		printf("\n");
	}
	printf("\n");
}


void clearScreen(int os) { //operation systems
    // Il efface le terminal
	
	if (os == 0){ 
	system("clear"); // For Unix/Linux
	}
	else if(os == 1){
     system("cls"); // For Windows
	}
}


// === Fonction De Jeu ===

int ** CreationTab(int n){ 
	
	// Creation de tableau (carre) avec le taille n 
	int **tab = (int **)malloc(n*sizeof(int*));
	int i;
	for(i=0;i<n;i++){
		tab[i] = (int *)malloc(n*sizeof(int));
	}
	
	
	// Affectation de table (affectation séquentielle)
	
	int j=0;  // numero de collone
	i=0;      // numero de ligne
	int x = 1; // numero de valeur
	
	for(i=0;i<n;i++){
		for(j=0;j<n;j++){
			tab[i][j] = x;
			x++;
		}
	}
	tab[n-1][n-1] = 0; // on mettre le denier case avec 0.
	// '0' reprensente le case vide dans le tableau	
	
	return tab;
}

/*
int getRandom(int min, int max) {
    return min + rand() % (max - min + 1);
}
*/

void Melange(GameBoard *T){
	//Il melange le tab.     //(le case vide est represante par 0)
	
	// Seed le générateur de nombres aléatoires avec l'heure actuelle
	srand(time(NULL)); 	
	
	// Initialization des variables 
	int Ncol ; // nouveau colonne
	int Nlin ; // nouveau ligne
	int taille = T->size ; // affectation de le taille de tableau
	
	// Algorithme de Shufle(melange)
	for(int i=0;i<taille;i++){
		for(int j=0;j<taille;j++){
			
			Ncol = rand() % taille ;
			Nlin = rand() % taille ;
			
			int valeurGarde = T->board[Nlin][Ncol]; //stocker le valeur1
			
			if(T->board[i][j] == 0){ //le cas '0' est le caseVide
					T->emptyLin = Nlin ;
					T->emptyCol	= Ncol ;
			}
			
			T->board[Nlin][Ncol] = T->board[i][j]; //Affectation de valeur2
			T->board[i][j] = valeurGarde ;	 // Affectation de valeur1
		}	
	}
}



// = Les fonction des Mouvement =

void X_gauche(GameBoard *T){
	// Enchange des valeur de caseVide et le case a gauche de caseVide
	
	//Initialization de location de case vide
	int VideLin = T->emptyLin ; // ligne de case vide
	int VideCol = T->emptyCol ; // colonne de case vide
	
	// Si il n y'a pas une case a gauche de caseVide cette fonction fera rien
	if(VideCol != 0){
		
		//Affectation sur le table
		int valeur = T->board[VideLin][VideCol-1]; //on garde le case gauche de case vide
		T->board[VideLin][VideCol-1] = T->board[VideLin][VideCol]; // Affectation de caseVide
		T->board[VideLin][VideCol] = valeur ; // Affectation de l'autre case
		
		//Affectation de structure T
		T->emptyLin = VideLin ; //nouveau ligne
		T->emptyCol = VideCol-1 ; // nouveau colonne
	}
	else{
		printf("Pas d'espace pour bouger \n");
	}
}


void X_droite(GameBoard *T){
	// Enchange des valeur de caseVide et le case a droite de caseVide
	
	//Initialization de location de case vide
	int VideLin = T->emptyLin ; // ligne de case vide
	int VideCol = T->emptyCol ; // colonne de case vide
	
	// Si il n y'a pas une case a gauche de caseVide cette fonction fera rien
	if(VideCol != (T->size -1) ){
		
		//Affectation sur le table
		int valeur = T->board[VideLin][VideCol+1]; //on garde le case gauche de case vide
		T->board[VideLin][VideCol+1] = T->board[VideLin][VideCol]; // Affectation de caseVide
		T->board[VideLin][VideCol] = valeur ; // Affectation de l'autre case
		
		//Affectation de structure T
		T->emptyLin = VideLin ; //nouveau ligne
		T->emptyCol = VideCol+1 ; // nouveau colonne
	}
	else{
		printf("Pas d'espace pour bouger \n");	
	}
}

void X_VersLeHaut(GameBoard *T){
	// Enchange des valeur de caseVide et le case a l'haut de caseVide
	
	//Initialization de location de case vide
	int VideLin = T->emptyLin ; // ligne de case vide
	int VideCol = T->emptyCol ; // colonne de case vide
	
	// Si il n y'a pas une case a gauche de caseVide cette fonction fera rien
	if(VideLin != 0 ){
		
		//Affectation sur le table
		int valeur = T->board[VideLin -1][VideCol]; //on garde le case gauche de case vide
		T->board[VideLin -1][VideCol] = T->board[VideLin][VideCol]; // Affectation de caseVide
		T->board[VideLin][VideCol] = valeur ; // Affectation de l'autre case
		
		//Affectation de structure T
		T->emptyLin = VideLin -1 ; //nouveau ligne
		T->emptyCol = VideCol ; // nouveau colonne
	}
	else{
		printf("Pas d'espace pour bouger \n");
	}
}


void X_VersLeBas(GameBoard *T){
	// Enchange des valeur de caseVide et le case en bas de caseVide
	
	//Initialization de location de case vide
	int VideLin = T->emptyLin ; // ligne de case vide
	int VideCol = T->emptyCol ; // colonne de case vide
	
	// Si il n y'a pas une case a gauche de caseVide cette fonction fera rien
	if(VideLin != (T->size -1) ){
		
		//Affectation sur le table
		int valeur = T->board[VideLin +1][VideCol]; //on garde le case gauche de case vide
		T->board[VideLin +1][VideCol] = T->board[VideLin][VideCol]; // Affectation de caseVide
		T->board[VideLin][VideCol] = valeur ; // Affectation de l'autre case
		
		//Affectation de structure T
		T->emptyLin = VideLin +1 ; //nouveau ligne
		T->emptyCol = VideCol ; // nouveau colonne
	}
	else{
		printf("Pas d'espace pour bouger \n");
	}
}


void mouve(char lettre, GameBoard *T){
	
	//Declaration de Pointeur de fonction
	void (*fun_ptr)(GameBoard*);
	
	// Affectation de pointeur de fonction
	if(lettre == 'g' || lettre == 'G'){
		fun_ptr = &X_gauche ;
	}
	else if(lettre == 'd' || lettre == 'D'){
		fun_ptr = &X_droite ;
	}
	else if(lettre == 'h' || lettre == 'H'){
		fun_ptr = &X_VersLeHaut ;
	}
	else if(lettre == 'b' || lettre == 'B'){
		fun_ptr = &X_VersLeBas ;
	}
	else{
		printf("Probleme de lettre \n");
		return ;
	}
	
	// Utilisation de pointeur de fonction
	fun_ptr(T);  // Passe le pointeur vers GameBoard à la fonction
}


// = Les fonction de Fichier = 

void AffectFichier(GameBoard *T,const char *nomFichier){
	// Il lire un fichier ensuite faire une affectation a la tableau
	// une fonction qui prend de valeurs sur un fichier.
	
	// Initialization de fichier
	FILE *file = fopen(nomFichier,"r");
	
	// Verification de fichier
	if (file == NULL){
		perror("Probleme de fichier");
		exit(-1);
	}
	
	// Lisage de fichier
    int lineNumber = 0;
    char line[100];  // la taille max de chaque ligne (cela peut etre modfier pour besoin) 
    
	while ( fgets(line, sizeof(line), file) != NULL && lineNumber < T->size) {
        
		// Attributeur des valeurs d'une ligne à tableau
        for (int j = 0; j < T->size; j++) {
            sscanf(line, "%d", &T->board[lineNumber][j]); // il fait une scanf et une affectation a la T (en meme temps)
			
			// Affectation de location de caseVide
			if(T->board[lineNumber][j] == 0){ //le cas '0' est le caseVide
					T->emptyLin = lineNumber ;
					T->emptyCol	= j ;
			}
        }
        lineNumber++;
    }
	
	fclose(file);
}


void EcrireFichier(GameBoard *T,const char *nomFichier){
	// cette fonction ecrire le contenu de table a la fichier. 
	
	// Ouverture de fichier
    FILE *file = fopen(nomFichier, "w+");

    // Verification de d'existance
    if (file == NULL) {
        perror("Probleme d'ouverture du fichier");
        exit(-1);
    }

    // Ecriture de GameBoard sur le fichier
    for (int i = 0; i < T->size; i++) {
        for (int j = 0; j < T->size; j++) {
            fprintf(file, "%d ", T->board[i][j]); // il y a une espace apres chaque nombre
        }
        fprintf(file, "\n");
    }

    fclose(file);
}	




