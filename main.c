#include<stdio.h>
#include<stdlib.h>
#include "Code_Taquin.h"

// Ajout de bibliotheque pour fonction sleep()
#ifdef _WIN32
	#include <unistd.h> 
#elif __linux__
	#include<unistd.h> 
#endif //si system n'est pas Linux ou Windows le fonction sleep va creer de problems

// Variable Global
int os ; // os => operating systems

int main(void){
	
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
	sleep(2);

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
               "2. jouer a une partie sauvegardee \n"
               "3. Les options \n"
               "4. Quitter \n");
        
        printf("Faitez vous votre choix (1 ou 2 ou 3 ou 4) :");
        int choix_menu = 0 ; 
        scanf(" %d",&choix_menu);
            
        // Le partie Jeu
        if(choix_menu == 1){
                
				// Variable de melange
				int nouveauJeu = 1 ; 
				
				
                // Boucle de mouvement
                char choix_mouvement = 'A' ; // la lettre A n'a pas un effect sur le code
                while(choix_mouvement != 'Q'){
                
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
                    if(lettre == 'Q' || lettre == 'q'){
                        choix_mouvement = 'Q' ;
						choix_menu = 0 ;
                    }
                    else if(lettre == 'G' || lettre == 'D' || lettre == 'H' || lettre == 'B' || lettre == 'g' || lettre == 'd' || lettre == 'h' || lettre == 'b'){
                    mouve(lettre,&T);
                    }


                }

            }
        // Le jeu sauvegardées
        else if(choix_menu == 2){
                
                // Boucle de choix difficulte
                char choixDifficulte = 'A'; // la lettre A n'a pas un effect sur le code
                while (choixDifficulte != 'Q'){
					
					// Efface de terminale
					clearScreen(os);
					
                    printf("Choissiez vous un jeu sauvegarder \n\n"
                        "1.Facile(par hazard) (4x4)    \n"
                        "2.Moyenne (5x5)   \n"
                        "3.Difficile (6x6) \n \n"
                        "Tapez 1 ou 2 ou 3 et Q pour le retoruner \n "
                        "Votre choix :");
                    
                    
                    scanf("%c",&choixDifficulte);
					
					// Retourne a la menu
					if(choixDifficulte == 'Q' || choixDifficulte == 'q'){
						choixDifficulte = 'Q';
						choix_menu = 0 ; // Le plus grand boucle apres le boucle de jeu
					}
					// Affectation
                    else if(choixDifficulte == '1'){
						
                        T.size = 4 ;
						T.board = CreationTab(T.size);
                        AffectFichier(&T,"facile.txt"); // nom de fichier est "facile"
						
						//Modification de variable de boucle
						choixDifficulte = 'Q';
						choix_menu = 0 ; //Plus grand boucle (apres le boucle de jeu)
						
						// Condition de melange de tableau dans le partie jeu
						jeuSauvegarde = 0;// on melange ici(donc jeuSauvegarde = 0) car dans le fichier les nombres sont ordonne
                    }
                    else if(choixDifficulte == '2'){

                        T.size = 5 ;
						T.board = CreationTab(T.size);
                        AffectFichier(&T,"moyenne.txt"); // nom de fichier est "moyenne"
						
						//Modification de variable de boucle
						choixDifficulte = 'Q';
						choix_menu = 0 ; //Plus grand boucle
						
						// Condition de melange de tableau dans le partie jeu
						jeuSauvegarde = 1;
						
                    }
                    else if(choixDifficulte == '3'){

                        T.size = 6 ;
						T.board = CreationTab(T.size);
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
                
				// Boucle de choix de taille
				char choix_taille = 'A';
                while(choix_taille != 'Q'){
				
					// Efface de terminale
					clearScreen(os);

					// Affichage d'ecriture et le choix
					printf("Le taille de tableau est %d \n",T.size);
					printf("Le jeu peut commoncer avec un tableau 4x4 ou 5x5 ou 6x6 \n"
						   "Tapez 4 ou 5 ou 6 pour ces tailles \n"
						   "Ou tapez Q pour le menu \n"
						   "votre choix :");

					
					scanf("%c",&choix_taille);

					// Modification de variable de boucle
					if(choix_taille == 'Q' ){
						choix_taille == 'Q' ;
						choix_menu = 0; // Plus grand boucle (après le boucle de jeu)
					}
					// Changement du taille de la tableau
					else if (choix_taille == '4' || choix_taille == '5' || choix_taille == '6'){
						T.size = choix_taille - '0';  // Convertir char en int en utilisant les valeurs ASCII
						T.board = CreationTab(T.size);
						T.emptyLin = T.size - 1;
						T.emptyCol = T.size - 1;
						
						// Variable globale
						jeuSauvegarde = 0;
					} 
					
                }
            }
        // Quitter le programme
        else if(choix_menu == 4){
				// Efface de terminale
				clearScreen(os);
				
				// EXIT
                var = 0;
                exit(0);
            }
    }
 
return 0 ;	
}