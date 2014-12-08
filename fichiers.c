#include "fichiers.h"

void lectureDb (Niveau listeNiveaux [], char addressesSauvegardes [3][50] )
{
    FILE * fichier;

fichier = fopen("db.dat" , "w");

printf("%s", addressesSauvegardes[0]);
system("pause");

fprintf(fichier, "%s:%s:%s\n", addressesSauvegardes[0], addressesSauvegardes[1], addressesSauvegardes[2]);
}
