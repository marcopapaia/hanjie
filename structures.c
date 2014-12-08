#include "structures.h"

int** initialisationCases(int x, int y)
{

    int **tableau;
    tableau = malloc(x*sizeof(int*));
    tableau[i] = malloc(y*sizeof(int));

    return tableau;
}
