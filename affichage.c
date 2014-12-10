#include "affichage.h"

void affichage (Cases * niveau)
{

    int x,y;
    int i,j;


    printf("\x1b[32m | |               (_|_)            /  _|        (_)| |      \n | |__   __ _ _ __  _ _  ___        | |_ __ _  ___ _| | ___  \n | '_ \\ / _` | '_ \\| | |/ _ \\       |  _/ _` |/ __| | |/ _ \\ \n | | | | (_| | | | | | |  __/       | || (_| | (__| | |  __/ \n |_| |_|\\__,_|_| |_| |_|\\___|       |_| \\__,_|\\___|_|_|\\___|\n                  _/ |                                       \n                 |__/\x1b[0m");


    char nombreLignes[5][15] = {"1 |","2 |","3 |","4 |","5 |"};
    char nombreColonnes[5][80] = {"\n       A B C D E\n   _____________"};
    char indicesLigne[5][15] = {" 1  "," 2  "," 1  "," 1  "," 3  "};
    char indicesColonne[5][80] = {"\n  \x1b[36m|\x1b[0m    0 1 5 1 0\n  \x1b[36m|\x1b[0m      1\n"};
    printf("\x1b[36m%s\x1b[0m", nombreColonnes);
    printf("%s", indicesColonne);

    for (i = 0; i < niveau->y; i++)
    {
            printf("\x1b[36m%s\x1b[0m", nombreLignes[i]);
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

int tableauLigne [6][5] = {{0}};

void score()
{





}
