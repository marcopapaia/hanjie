#include "fichiers.h"

void lectureDb (char listeNiveaux [3][3][100], char addressesSauvegardes [3][100] )
{
    //Cette fonction charge le fichier contenant la base de donnée et trenvoie les addresses des niveaux et des sauvegardes.
    FILE * fichier;

    fichier = fopen("db.bin" , "rb");//On ouvre le fichier db.bin en lecture seule en binaire

    fread( listeNiveaux , sizeof(char)*100 , 3*3 , fichier); //On lit dans le fichier le tableau listeNiveau (tableau de char a 3 dimension)
    fread( addressesSauvegardes , sizeof(char)*100 , 3 , fichier); //On lit dans le fichier le tableau addressesSauvegardes (tableau de char à 2 dimensions)

}
Cases* lectureNiveau (char addresse [100])
{

}
