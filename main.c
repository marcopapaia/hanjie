#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b,c;
    int numDiff,TailleResultats;
    char pseudo[50];

    printf(" Bienvenue pour jouer a une partie de Hanjie \n\n Que voulez vous faire ?\n");
    printf("\t1=Jouer une partie\n\t2=Voir l'historique des parties\n\t3=Quitter " );
    scanf("\n%d",&a);

    if (a==1) {



        system("clear");
        printf(" Menu de partie \n ");
        printf("\t1=Nouvelle partie\n\t2=Charger une partie\n\t3=Revenir au menu \n " );
        scanf("\n%d",&b);

        switch (b) {
            case 1 :{

                system("clear");
                printf("Entrez votre pseudo:\n ");
                scanf("%s",pseudo);
                printf("Quelle difficulté du niveau voulez vous ?\n\t1=FACILE\n\t2=MOYEN\n\t3=DIFFICILE\n");
                scanf ("%d",&numDiff);
                printf("Quelle taille de d'affichage des resultats voulez vous ? \n\t1=5*3\n\t2=7*4\n\t3=9*5\n\t4=11*6\n ");
                scanf ("%d",&TailleResultats);






            }
            break;
            case 2 : {
                system("clear");
            //sauvegarde();
                    }
            case 3: {
            system("clear");
            return main();
            }
            break;




        }

        }
        if (a==2){
            system("clear");

            };
        if (a==3){
            system("clear");
            return 0;
            }
}
