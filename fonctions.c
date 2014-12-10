#include "fonctions.h"


void SystemPause()
{
   char magickey;
   fflush(stdin);
   printf("Appuyez sur une touche pour continuer...");
   scanf("%c", &magickey);
   magickey = getc(stdin);
}

void calculIndice(Partie * partie)
{

    partie->nbIndiceMaxLigne = ceil((double)partie->pattern.x / 2);
    partie->nbIndiceMaxColonne = ceil((double)partie->pattern.y / 2);

    partie->indiceLigne = initialisationGrilleInt(partie->nbIndiceMaxLigne, partie->pattern.y);
    partie->indiceColonne = initialisationGrilleInt(partie->nbIndiceMaxColonne, partie->pattern.x);

    int i, j, k, etat;

    for (i = 0; i < partie->pattern.y; i++)
    {
        k = 0; etat = 0;
        for( j = 0; j < partie->pattern.x; j++)
        {
            if(partie->pattern.grille[i][j] == '1')
            {
                partie->indiceLigne[i][k]++;
                etat = 1;
            }
            else if(etat == 1)
            {
                k++;
                etat = 0;
            }
        }

    }

    for (i = 0; i < partie->pattern.x; i++)
    {
        k = 0; etat = 0;
        for( j = 0; j < partie->pattern.y; j++)
        {
            if(partie->pattern.grille[j][i] == '1')
            {
                partie->indiceColonne[i][k]++;
                etat = 1;
            }
            else if(etat == 1)
            {
                k++;
                etat = 0;
            }
        }

    }

}
