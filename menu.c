#include "menu.h"

void menuHead(char chaine[80])
{
    printf("\x1b[31m                     .__\x1b[0m          .__                       __.__        \n\x1b[31m         ____ ___  __|__|____ \x1b[0m    |  |__ _____    ____     |__|__| ____  \n\x1b[31m       _/ __ \\\\  \\/  /  \\__  \\\x1b[0m    |  |  \\\\__  \\  /    \\    |  |  |/ __ \\ \n\x1b[31m       \\  ___/ >    <|  |/ __ \\_\x1b[0m  |   Y  \\/ __ \\|   |  \\   |  |  \\  ___/ \n\x1b[31m        \\___  >__/\\_ \\__(____  / /\\\x1b[0m___|  (____  /___|  /\\__|  |__|\\___  >\n\x1b[31m            \\/      \\/       \\/  \\/ \x1b[0m   \\/     \\/     \\/\\______|       \\/ \n");
    printf("\n\n\x1b[0m~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n");
    int i;
    int taille = strlen(chaine);
    for (i = 0; i < (40 - (taille/2)); i++)
    {
        printf(" ");
    }
    printf("%s\n~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n\n", chaine);
}

void menuPrincipal(Partie * partie)
{
    int a;

    do
    {

        system("clear");
        menuHead("Menu Principal");
        printf("\t1=Jouer une partie\n\t2=Voir l'historique des parties\n\t3=Quitter " );
        scanf("\n%d",&a);

        switch (a)
        {
        case 1 :

            menuJeu(partie);

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

    } while (a != 3);
}

void menuJeu(Partie * partie)
{
    int b, i, j;
    char addresse[150];
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
            viderTampon();
            menuHead("Nouvelle Partie");
            printf("Entrez votre pseudo (50 charactéres maximum):\n ");
            scanf("%[^\n]50s", partie->pseudo);
            viderTampon();
            do
            {

                system("clear");
                menuHead("Nouvelle Partie");
                printf("Quelle difficulté du niveau voulez vous ?\n\t1=FACILE\n\t2=MOYEN\n\t3=DIFFICILE\n");
                scanf ("%d",&(partie->difficulte));

            } while (partie->difficulte != 1 && partie->difficulte != 2 && partie->difficulte != 3);
            viderTampon();
            do
            {

                system("clear");
                menuHead("Nouvelle Partie");
                printf("Quelle taille de d'affichage des resultats voulez vous ? \n\t1=5*3\n\t2=7*4\n\t3=9*5\n\t4=11*6\n ");
                scanf ("%1d",&(partie->tailleResultats));

            } while (partie->tailleResultats != 1 && partie->tailleResultats != 2 && partie->tailleResultats != 3 && partie->tailleResultats != 4);

            system("clear");

            //Choix aléatoire du niveau à réaliser
            partie->date = time(NULL);
            lectureNiveau("niveaux/facile/1.pbm", &(partie->pattern));
            partie->actuel.x = partie->pattern.x;
            partie->actuel.y = partie->pattern.y;
            partie->actuel.grille = initialisationGrilleChar(partie->actuel.x, partie->actuel.y);
            calculIndice(partie);


            //Envoie a la fonction de jeu
            system("clear");
            hanjie(partie);

            system("clear");
            menuHead("Sauvegarde");
            printf("Addresse de la save :\n");
            scanf(" %s", addresse);
            sauvegarde(partie, addresse);
            break;

        case 2 :
            system("clear");
            //-----En travaux
            viderTampon();
            menuHead("Chargement partie");
            printf("Addresse de la save :\n");
            scanf(" %s", addresse);
            chargement(partie, addresse);

            hanjie(partie);
            //sauvegarde();
            break;

        case 3:
            system("clear");
            break;
        default :
            break;
        }

    } while (b != 3);

}
