#include "structures.h"

int** initialisationCases(int x, int y)
{

    int **tableau;
    tableau = malloc(y*sizeof(int*));

    int i;
    for(i = 0; i < y; i++)
    {
        tableau[i] = malloc(y*sizeof(int));
    }

    return tableau;
}
