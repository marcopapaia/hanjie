#include "includes.h"

void menuHead(char chaine[80])
{
    printf("                     .__          .__                       __.__        \n         ____ ___  __|__|____     |  |__ _____    ____     |__|__| ____  \n       _/ __ \\\\  \\/  /  \\__  \\    |  |  \\\\__  \\  /    \\    |  |  |/ __ \\ \n       \\  ___/ >    <|  |/ __ \\_  |   Y  \\/ __ \\|   |  \\   |  |  \\  ___/ \n        \\___  >__/\\_ \\__(____  / /\\___|  (____  /___|  /\\__|  |__|\\___  >\n            \\/      \\/       \\/  \\/    \\/     \\/     \\/\\______|       \\/ \n");
    printf("\n\n<------------------------------------------------------------------------------>\n");
    int i;
    int taille = strlen(chaine);
    for (i = 0; i < (40 - (taille/2)); i++)
    {
        printf(" ");
    }
    printf("%s\n<------------------------------------------------------------------------------>\n\n", chaine);
}

int main()
{
    int a,b,c;
    int numDiff,TailleResultats;
    char pseudo[50];

    do
    {

        system("clear");
        menuHead("Menu Principal");
        printf("\t1=Jouer une partie\n\t2=Voir l'historique des parties\n\t3=Quitter " );
        scanf("\n%d",&a);

        switch (a)
        {
            case 1 :

                do
                {

                    system("clear");
                    menuHead("Menu de partie");
                    printf("\t1=Nouvelle partie\n\t2=Charger une partie\n\t3=Revenir au menu \n " );
                    scanf("\n%d",&b);

                    switch (b)
                    {

                        case 1 :
                            system("clear");
                            Partie partie;
                            printf("Entrez votre pseudo:\n ");
                            scanf("%s", partie.pseudo);
                            printf("Quelle difficulté du niveau voulez vous ?\n\t1=FACILE\n\t2=MOYEN\n\t3=DIFFICILE\n");
                            scanf ("%d",&(partie.difficulte));
                            printf("Quelle taille de d'affichage des resultats voulez vous ? \n\t1=5*3\n\t2=7*4\n\t3=9*5\n\t4=11*6\n ");
                            scanf ("%d",&(partie.tailleResultats));

                            //Choix aléatoire du niveau
                            lectureNiveau("niveaux/facile/1.pbm", &(partie.pattern));
                            partie.actuel.x = partie.pattern.x;
                            partie.actuel.y = partie.pattern.y;
                            partie.actuel.grille = initialisationCases(partie.actuel.x, partie.actuel.y);

                            //Envoie a la fonction de jeu
                            affichage(&(partie.pattern));
                            return 0;

                            break;

                        case 2 :
                            system("clear");
                        //sauvegarde();
                            break;

                        case 3:
                            system("clear");
                            break;
                    }

                }while (b != 3);

                break;

                case 2 :
                    system("clear");
                    break;

                case 3 :
                    system("clear");
                    break;
                default :
                    system("clear");
                    break;
        }

    }while (a != 3);
    return 0;

}
