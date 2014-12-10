#include "affichage.h"

void affichage (Partie * niveau)
{

    int x,y;
    int i,j,k;

    printf("\x1b[32m | |               (_|_)            /  _|        (_)| |      \n | |__   __ _ _ __  _ _  ___        | |_ __ _  ___ _| | ___  \n | '_ \\ / _` | '_ \\| | |/ _ \\       |  _/ _` |/ __| | |/ _ \\ \n | | | | (_| | | | | | |  __/       | || (_| | (__| | |  __/ \n |_| |_|\\__,_|_| |_| |_|\\___|       |_| \\__,_|\\___|_|_|\\___|\n                  _/ |                                       \n                 |__/\x1b[0m\n\n");

    for (i = 0; i < niveau->nbIndiceMaxColonne; i++)
    {
        for (j = 0; j < niveau->nbIndiceMaxLigne; j++)
        {
            printf("  ");
        }
        for (j = 0; j < niveau->pattern.x; j++)
        {
            if(niveau->indiceColonne[j][i] == 0)
            {
                printf("  ");
            }
            else
            {
                printf("%d ", niveau->indiceColonne[j][i]);
            }
        }
        printf("\n");
    }

    for (i = 0; i < niveau->pattern.y; i++)
    {

        //test a partir d'ici
        for(k = 0; k < niveau->nbIndiceMaxLigne; k++)
        {
            if(niveau->indiceLigne[i][k] == 0)
            {
                printf("  ");
            }
            else
            {
                printf("%d ", niveau->indiceLigne[i][k]);
            }
        }
        //fin de test
        for(j = 0; j < niveau->pattern.x; j++)
        {

            if (niveau->pattern.grille[i][j] == '1')
            {
                printf("%c%c%c ", 0xE2, 0x96, 0xA9);
            }

            else
            {
                printf("%c%c%c ", 0xE2, 0x96, 0xA1);
            }
        }
        printf("\n");
    }

}

int tableauLigne [6][5] = {{0}};

void score()
{





}
