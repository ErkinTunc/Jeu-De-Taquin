#include<stdio.h>
#include<stdlib.h>
#include<time.h>



// === Structure De Données ===

//structure répresentante une case sur le plateu
typedef struct{
	int value;
}Case; 	// Case(fr) <=> tile(ang) <=> kutu(tr)


// Structure représentant le plateau de jeu
typedef struct {
    int size;  // Taille du côté du plateau (4 dans votre exemple)
    Case **board;  // Tableau 2D de cases
    int emptyRow;  // Ligne de la case vide
    int emptyCol;  // Colonne de la case vide
} GameBoard;



// === Fonction Pour Tester ===

void AfficheTab2k(int ** tab,int ligne,int collone){ // utiliser les table qui a le taille moins que 100 pour bien fonctionment
	
	// Test d'existence
	if(tab == NULL){
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


// === Fonction De Jeu ===

int ** CreationTab(int n){ 
	
	// Creation de tableau (carre) avec le taille n 
	int **tab = malloc(n*sizeof(int*));
	int i;
	for(i=0;i<n;i++){
		tab[i] = malloc(n*sizeof(int));
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
void ** Melange(double **tab){
	//Il melange le tab.  
	//(le case vide est represante par -1)
	
	
	int i=0;
	for (i=0;i<4;i++){
		int j=0;
		for(j=0;j<4;j++){
			
		}
	}
	
	
	
	return;
}
*/


// ecrire une fonction qui prend de valeurs sur un fichier.


int main(){

	// Le taille de tableau(carre)
	int n = 4;

	// Initialization de tab2k
	int **tab = CreationTab(n);
	AfficheTab2k(tab,n,n);
	

return 0;
}