#include "structures.h"

int** initialisationGrilleInt(int x, int y)
{

    int **tableau;
    tableau = malloc(y*sizeof(int*));

    int i,j;
    for(i = 0; i < y; i++)
    {
        tableau[i] = malloc(x*sizeof(int));
        for(j = 0; j < x; j++)
        {
            tableau[i][j] = 0;
        }
    }

    return tableau;
}
char** initialisationGrilleChar(int x, int y)
{

    char **tableau;
    tableau = malloc(y*sizeof(char*));

    int i, j;
    for(i = 0; i < y; i++)
    {
        tableau[i] = malloc(x*sizeof(char));
        for(j = 0; j < x; j++)
        {
            tableau[i][j] = '0';
        }
    }

    return tableau;
}
