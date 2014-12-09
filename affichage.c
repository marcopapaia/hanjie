#include "affichage.h"

void affichage (Cases * niveau)
{

    int x,y;
    int i,j;

    char indicesLigne[5][15] = {"\n 4  ","1 2 "," 1  ","2 1 "," 2  "};
    char indicesColonne[5][25] = {"\n    1 2 1 4 2\n      2 1 "};
    printf("%s", indicesColonne);

    for (i = 0; i < niveau->y; i++)
    {
                printf("%s", indicesLigne[i]);
        for(j = 0; j < niveau->x; j++)
        {

            if (niveau->grille[i][j] == '1')
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

void score()
{





}
