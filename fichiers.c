#include "fichiers.h"

void lectureDb (char listeNiveaux [3][3][100], char addressesSauvegardes [3][100] )
{
    //Cette fonction charge le fichier contenant la base de donnée et trenvoie les addresses des niveaux et des sauvegardes.
    FILE * fichier;

    fichier = fopen("db.bin" , "rb");//On ouvre le fichier db.bin en lecture seule en binaire

    fread( listeNiveaux , sizeof(char)*100 , 3*3 , fichier); //On lit dans le fichier le tableau listeNiveau (tableau de char a 3 dimension)
    fread( addressesSauvegardes , sizeof(char)*100 , 3 , fichier); //On lit dans le fichier le tableau addressesSauvegardes (tableau de char à 2 dimensions)

}
void lectureNiveau (char addresse [100], Cases * niveau)
{
    FILE * fichier;

    fichier = fopen(addresse, "r");

    lectureSautLigne(fichier);
    lectureSautLigne(fichier);

    fscanf(fichier, "%d %d", &(niveau->x), &(niveau->y));

    niveau->grille=initialisationCases(niveau->x,niveau->y);
    lectureSautLigne(fichier);

    int i = 0, j = 0;
    char test;


    for (j = 0; j < 5; j++)
    {
        for (i = 0; i < 5; i++)
        {
            niveau->grille[j][i] = fgetc(fichier);
            test = fgetc(fichier);
        }
        test = fgetc(fichier);
    }

}
void lectureSautLigne( FILE * fichier)
{
    char test =0;
    while(test != '\n')
    {
        test = fgetc(fichier);
    }
}
