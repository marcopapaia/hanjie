#include "affichage.h"

void affichage (Partie * niveau)
{

    int i,j,k;

    system("clear");
    menuHead("Hanjie n°1");

    printf("           ");
for (i = 0; i < niveau->actuel.x; i++)
{

        printf("\x1b[36m%c\x1b[0m   ",i+65);

}

    printf("\n");

    for (i = 0; i < niveau->nbIndiceMaxColonne; i++)
    {
                printf("    ");

        for (j = 0; j < niveau->nbIndiceMaxLigne; j++)
        {
                printf("  ");
        }
            for (j = 0; j < niveau->actuel.x; j++)
            {
            if(niveau->indiceColonne[j][i] == 0)
            {
                printf("    ");
            }
            else
            {
                printf(" %d  ", niveau->indiceColonne[j][i]);
            }
        }
        printf("\n");
    }

    for (i = 0; i < niveau->actuel.y; i++)
    {

        printf("\x1b[36m%2d |\x1b[0m ",i+1);

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
        for(j = 0; j < niveau->actuel.x; j++)
        {
            if (niveau->actuel.grille[i][j] == '1')
            {
                printf("%c%c%c | ", 0xE2, 0x96, 0xA9);
            }

            else
            {
                printf("%c%c%c | ", 0xE2, 0x96, 0xA1);
            }
        }
        printf("\n");
        for(j = 0; j < niveau->nbIndiceMaxLigne; j++)
        {
            printf("  ");
        }

        printf("    ");

        for(j = 0; j < niveau->actuel.x; j++)
        {
            printf("%c%c%c", 0xE2, 0x94, 0x80);
            printf("%c%c%c", 0xE2, 0x94, 0x80);
            printf("%c%c%c", 0xE2, 0x94, 0x80);
            printf("%c%c%c", 0xE2, 0x94, 0xBC);
        }
        printf("\n");
    }

}

void score()
{





}
