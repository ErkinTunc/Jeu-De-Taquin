#include<stdio.h>
#include "Code_Taquin.h"

int main(){

    // Affichage de Salutation
    printf("Bonjour a la jeu de Taquin \n");

    // Les Variables 
    int taille_tableau = 4; 
    int var = 1; //le variable de premeir boucle(le plus grande)

    // Le Structure de GameBoard
    GameBoard T;
    T.size = taille_tableau ;
    T.board = CreationTab(taille_tableau) ;
    T.emptyLin = taille_tableau - 1 ;
    T.emptyCol = taille_tableau - 1 ;


    
    // Le Menu
    while (var != 0){
        printf("Le Menu \n");

        printf("1. Jouer\n"
               "2. Jouer le jeu sauvegarder\n"
               "3. Les options\n"
               "4. Quitter \n");
        
        printf("Faitez vous votre choix (1 ou 2 ou 3 ou 4) :\n");
        int choix_menu ; 
        scanf("%d",&choix_menu);

        // Executable
        while (choix_menu != 4){
            
            // Le partie Jeu
            if(choix_menu == 1){
                
                char choix_mouvement = "G" ;
                while(choix_mouvement != 'Q' ){
                
                
                    // Melange le tableau
                    Melange(&T); 

                    // Affichage et mouvement 
                    AfficheTab2k(T.board,T.size,T.size);

                    printf("Tapez G, D, H, B pour deplacer \n "
                        "Ou tapez \"S\" pour le Sauvegarder \n"
                        "Ou tapez \"Q\" pour le Menu \n"
                        "Votre choix : \n" );
                    
                    int lettre;
                    scanf("%c",&lettre);

                    // Sauvegarde le jeu
                    if (lettre == 'S'){
                        
                        // Affichage de page Sauvegarder
                        printf("Sauvegarder votre jeu \n"
                               "Save1 \n"
                               "Save2 \n"
                               "Save3 \n"
                               "Votre choix peut etre 1, 2, 3 \n"
                               "Tapez Q pour retourne a la jeu \n"
                               "Votre choix :");
                        
                        // Le choix d'utilisateur
                        char choix_sauvegarder = "Q";
                        scanf("%c",&choix_sauvegarder);

                        // Selection de fichier
                        char * fileName = "save1" ;
                        if(choix_sauvegarder == '1'){
                            fileName = "save1" ;
                        }
                        else if(choix_sauvegarder == '2'){
                            fileName = "save2" ;
                        }
                        else if(choix_sauvegarder == '3'){
                            fileName = "save3" ;
                        }
                        
                        // Ecriture a la fichier
                        EcrireFichier(&T,&fileName);

                    }
                    else if(lettre == "Q"){
                        choix_mouvement = lettre ;
                    }
                    else{
                    mouve(lettre,&T);
                    }

                }

            }
            // Le jeu sauvegarder
            else if(choix_menu == 2){

            }
            // Les options
            else if(choix_menu == 3){
                
            }
            // Quitter le programme
            else if(choix_menu == 4){
                exit(0);
            }
        
        }
        
    }
    



    return 0 ;
}