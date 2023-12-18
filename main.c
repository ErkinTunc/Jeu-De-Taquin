#include<stdio.h>
#include<stdlib.h>
#include "Code_Taquin.h"

// Variable Global
int os ; // os => operating systems

int main(){
	
	// Verification de System d'operation
	#ifdef _WIN32
    os = 1; // Windows
	#elif __linux__
		os = 0; // Linux
	#else
		os = -1; // Unknown
	#endif
	
    
	
    // Efface de terminale
    clearScreen(os);

    // Affichage de Salutation
    printf("Bonjour a la jeu de Taquin \n");

    // Les Variables 
    int taille_tableau = 4; 
    int var = 1; //le variable de premeir boucle(le plus grande)
	int jeuSauvegarde = 0;

    // Le Structure de GameBoard
    GameBoard T ;
    T.size = taille_tableau ;
    T.board = CreationTab(taille_tableau) ;
    T.emptyLin = taille_tableau - 1 ;
    T.emptyCol = taille_tableau - 1 ;


    
    // Le Menu
    while (var != 0){

        // Efface de terminale
        clearScreen(os);

        printf("Le Menu \n");

        printf("1. Jouer \n"
               "2. Jouer le jeu sauvegarder \n"
               "3. Les options \n"
               "4. Quitter \n");
        
        printf("Faitez vous votre choix (1 ou 2 ou 3 ou 4) :");
        int choix_menu ; 
        scanf("% d",&choix_menu);

        // Executable
        while (choix_menu != 4){
            
            // Le partie Jeu
            if(choix_menu == 1){
                
				// Variable de melange
				int nouveauJeu = 1 ; 
				
				
                // Boucle de mouvement
                char choix_mouvement = 'A' ; // la lettre A n'a pas un effect sur le code
                while(choix_mouvement != 'Q' ){
                
                    // Efface de terminale
                    clearScreen(os);
                    
                    // Melange le tableau
                    if(nouveauJeu && !(jeuSauvegarde) ){ // nouveauJeu = 1||0 // 
						Melange(&T); 
						nouveauJeu = 0;
					}

                    // Affichage et mouvement 
                    AfficheTab2k(T.board,T.size,T.size);
					
					// Choix du joueur
                    printf("Tapez G, D, H, B pour deplacer \n "
                        "Ou tapez \'Q\' pour le Menu \n"
                        "Votre choix : " );
                    
                    char lettre ; // choix lettre
                    scanf(" %c",&lettre);
					
					// Consume the newline character
					getchar();

                    // Retourne a la menu
                    if(lettre == 'Q'){
                        choix_mouvement = lettre ;
						choix_menu = 0 ;
                    }
                    else if(lettre == 'G' || lettre == 'D' || lettre == 'H' || lettre == 'B'){
                    mouve(lettre,&T);
                    }


                }

            }
            // Le jeu sauvegardées
            else if(choix_menu == 2){
                
                // Efface de terminale
                clearScreen(os);

                // Boucle de choix difficulte
                char choixDifficulte = 'A'; // la lettre A n'a pas un effect sur le code
                while (choixDifficulte != 'Q'){

                    printf("Choissiez vous un jeu sauvegarder \n"
                        "1.Facile(par hazard) (4x4)    \n"
                        "2.Moyenne (5x5)   \n"
                        "3.Difficile (6x6) \n"
                        "Tapez 1 ou 2 ou 3 et Q pour le retoruner \n"
                        "Votre choix :");
                    
                    
                    scanf("%c",&choixDifficulte);
					
					// Retourne a la menu
					if(choixDifficulte == 'Q'){
						choix_menu = 0 ; // Le plus grand boucle apres le boucle de jeu
					}

					// Affectation
                    if (choixDifficulte == '1'){
						
                        T.size = 4 ;
                        AffectFichier(&T,"facile.txt"); // nom de fichier est "facile"
                        Melange(&T);  // on melange ici car dans le fichier les nombres sont ordonne
						
						//Modification de variable de boucle
						choixDifficulte = 'Q';
						choix_menu = 0 ; //Plus grand boucle (apres le boucle de jeu)
						
						// Condition de melange de tableau dans le partie jeu
						jeuSauvegarde = 1;
                    }
                    else if(choixDifficulte == '2'){

                        T.size = 5 ;
                        AffectFichier(&T,"moyenne.txt"); // nom de fichier est "moyenne"
						
						//Modification de variable de boucle
						choixDifficulte = 'Q';
						choix_menu = 0 ; //Plus grand boucle
						
						// Condition de melange de tableau dans le partie jeu
						jeuSauvegarde = 1;
						
                    }
                    else if(choixDifficulte == '3'){

                        T.size = 6 ;
                        AffectFichier(&T,"difficile.txt"); // nom de fichier est "difficile"
						
						//Modification de variable des boucles
						choixDifficulte = 'Q';
						choix_menu = 0 ; //Plus grand boucle
						
						// Condition de melange de tableau dans le partie jeu
						jeuSauvegarde = 1;
                    }
					
					
                }
                
            }
            // Les options
            else if(choix_menu == 3){
                
                // Efface de terminale
                clearScreen(os);

                // Affichage d'ecriture et le choix
                printf("Le taille de tableau est %d \n",T.size);
                printf("Le jeu peut commoncer avec un tableau 4x4 ou 5x5 ou 6x6 \n"
                       "Tapez 4 ou 5 ou 6 pour ces tailles \n"
					   "Ou tapez Q pour le menu \n"
                       "votre choix :");

                char choix_taille;
                scanf("%c",&choix_taille);

                // Changement du taille de la tableau
				if (choix_taille == '4' || choix_taille == '5' || choix_taille == '6') {
					T.size = choix_taille - '0';  // Convertir char en int en utilisant les valeurs ASCII
					T.board = CreationTab(T.size);
					T.emptyLin = T.size - 1;
					T.emptyCol = T.size - 1;
				} else if (choix_taille == 'Q') {
					// Modification de variable de boucle
					choix_menu = 0; // Plus grand boucle (après le boucle de jeu)
				}
                
            }
            // Quitter le programme
            else if(choix_menu == 4){
                var = 0;
                exit(0);
            }
        }
    }
    
return 0 ;
}