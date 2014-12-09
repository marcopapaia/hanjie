#include "structures.h"

void affichage (Difficulte diff)
{
    int x,y;
    int tab [x][y];
    int i,j;

if (diff == 0)
{
    x=5;
    y=5;
};

if (diff == 1)
{
    x=10;
    y=10;
};

if (diff == 2)
{
    x=15;
    y=15;
};


    for (j = 0; j < x; j++)
    {
        for(i = 0; i < y; i++)
        {
            if (tab[i][j] == 0)
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
