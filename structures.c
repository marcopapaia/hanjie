#include "structures.h"

int** initialisationGrilleInt(int x, int y)
{

    int **tableau;
    tableau = malloc(y*sizeof(int*));

    int i;
    for(i = 0; i < y; i++)
    {
        tableau[i] = malloc(x*sizeof(int));
    }

    return tableau;
}
char** initialisationGrilleChar(int x, int y)
{

    char **tableau;
    tableau = malloc(y*sizeof(char*));

    int i;
    for(i = 0; i < y; i++)
    {
        tableau[i] = malloc(x*sizeof(char));
    }

    return tableau;
}
