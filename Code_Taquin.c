#include<stdio.h>
#include<stdlib.h>

// === Fonction Pour Tester


// === Fonction De Jeu ===

double ** CreationTab(){
	//Il cree une table 4x4 
	int **tab = malloc(4*sizeof(int));
	int i;
	for(i=0;i<4;i++){
		tab[i] = malloc(4*sizeof(int));
	}
	
	return tab;
}


int main(){


return 0;
}