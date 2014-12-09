#include <stdio.h>
#include <stdlib.h>
#include "structures.h"

int main()
{
    Partie partie;

    lectureNiveau("niveaux/facile/hanjie1.pbm", &(partie.pattern));
    int i = 0, j = 0;
    for (j = 0; j < 5; j++)
    {
        for (i = 0; i < 5; i++)
        {
            printf("%c", partie.pattern.grille[j][i]);
        }
        printf("\n");
    }

    return 0;
}


