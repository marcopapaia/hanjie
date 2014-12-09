#include "affichage.h"

void affichage (Cases * niveau)
{

    int x,y;
    int i,j;

    for (i = 0; i < niveau->y; i++)
    {
        for(j = 0; j < niveau->x; j++)
        {
            if (niveau->grille[i][j] == '0')
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
