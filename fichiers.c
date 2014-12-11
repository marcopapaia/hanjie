#include "fichiers.h"


void lectureDb (char listeNiveaux [3][3][100], char addressesSauvegardes [3][100] )
{
    //Cette fonction charge le fichier contenant la base de donnée et trenvoie les addresses des niveaux et des sauvegardes.
    FILE * fichier;

    fichier = fopen("db.bin" , "rb");//On ouvre le fichier db.bin en lecture seule en binaire

    fread( listeNiveaux , sizeof(char)*100 , 3*3 , fichier); //On lit dans le fichier le tableau listeNiveau (tableau de char a 3 dimension)
    fread( addressesSauvegardes , sizeof(char)*100 , 3 , fichier); //On lit dans le fichier le tableau addressesSauvegardes (tableau de char à 2 dimensions)

}
// lectureNiveau charge un hanjie contenu dans le fichier situé a "adresse" dans "niveau"
void lectureNiveau (char addresse [100], Cases * niveau)
{
    FILE * fichier;//On crée un FILE

    fichier = fopen(addresse, "r");//On Ouvre en lecture seule le fichier .pbm
    //Penser a verifier si l'ouverture s'est bien passé

    //----Lecture du fichier
    int i = 0, j = 0, etat = 0;//Etat permet de savoir quelle information a déja été lu
                                // 0 = Rien, 1 = Le numéro magique, 2 = Les dimensions
    char test = 0;
    while (etat < 3)
    {//On lit le premier caractére de chaque ligne
        do
        {
            test = fgetc(fichier);
        }while(test == '\n' || test == ' ');//Si on lit un retour a la ligne ou un espace, la ligne lu est respectivemnt vide ou commence par une série d'espace
                                            //donc, on relit un caractére

        fseek(fichier, -1, SEEK_CUR);//On revient avant le carac actuel, pour permetre son traitement


        if(test != '#')//On vérifie qu'il ne s'agit pas d'un commentaire
        {
            switch(etat)//On regarde ce qui a déja été lu
            {
                case 0 : //Rien n'a été lu
                    //On ne récupére pas le numéro magique, le type du fichier est déja connu
                    etat++;//On passe a l'état suivant
                    lectureSautLigne(fichier);//On passe a la ligne suivante
                    break;
                case 1 : //On a lu le numéro magique

                    fscanf(fichier, "%d %d", &(niveau->x), &(niveau->y));//On récuppére les dimensions de l'hanjie
                    niveau->grille=initialisationGrilleChar(niveau->x,niveau->y);//On initialise la grille selon les dimensions récupéré ci-dessus    lectureSautLigne(fichier);
                    etat++;//On passe a l'état suivant
                    lectureSautLigne(fichier);//On passe a la ligne suivante
                    break;
                case 2 : //On a lu les dimensions
                    //------lecture de la grille--------
                    if( j < niveau->y)//On vérifie qu'il reste des lignes a récupéré
                    {
                        for (i = 0; i < niveau->x ; i++)//Cette boucle dait défiler les caractéres de chaques lignes
                        {
                            test  = fgetc(fichier);//On récupére le caractére
                            niveau->grille[j][i] = test;


                            fseek(fichier, 1, SEEK_CUR);//On passe le caractére blanc

                        }
                        //On passe à la ligne suivante
                        fseek(fichier, -1, SEEK_CUR);//Avec certains éditeur de texte, le pbm avait des retours a la ligne en
                                        // 2 caractéres, on prévoit les deux cas en revenant un caractére en arriére
                                    // à chaque ligne puis en utilisant la fonction lectureSautligne
                        lectureSautLigne(fichier);//On passe a la ligne suivante
                        j++;//On incremente l'index des lignes
                    }
                    else etat++;//On passe a l'état suivant

                    break;
            }
        }
        else//Si il s'agit d'un commentaire, on passe a la ligne suivante
            lectureSautLigne(fichier);
    }



}
//Cette fonction permet de se déplacer dans un fichier lu, a la ligne suivante
void lectureSautLigne( FILE * fichier)
{
    //On lit le fichier caractére par caractére jusque trouver le caractére de retour a la ligne
    char test = 0;
    while(test != '\n')
    {
        test = fgetc(fichier);
    }//Le curseur du FILE est donc juste avant le premier caractére de la ligne suivante
}

void sauvegarde(Partie * partie)
{
        FILE * fichier;//On crée un FILE

    char format[50];
    time_t temps;
    struct tm date;
    // On récupère la date et l'heure actuelles.
    time(&temps);
    date=*localtime(&temps);
    strftime(format, 50, "%d/%m/%y à %X", &date);

    fichier = fopen("test.bin", "w");
    fprintf(fichier, "# Fichier de sauvegarde du jeu exia.hanjie, générée le %s\n", format);
    fprintf(fichier, "# Toute modification peut mener à la corruption de la sauvegarde\n");
    fprintf(fichier, "#--------------------------------------------------------------------\n\n");

    fprintf(fichier, "t_debut : %f\n",  partie->date);//Date de début
    fprintf(fichier, "t_save : %f\n",  (double) temps);//Date de sauvegarde
    fprintf(fichier, "pseudo : %s\n",  partie->pseudo);//pseudo
    fprintf(fichier, "type : %d\n",  partie->type);//Type de niveau
    fprintf(fichier, "taille_score : %d\n",  partie->tailleResultats);//Taille des resultats
    fprintf(fichier, "difficultee : %d\n",  partie->difficulte);//Difficulté
    fprintf(fichier, "nbMaxIndiceColonne : %d\n",  partie->nbIndiceMaxColonne);
    fprintf(fichier, "nbMaxIndiceLigne : %d\n\n",  partie->nbIndiceMaxLigne);

    sauvegardeGrilleChar(fichier, partie->pattern.grille, partie->pattern.x, partie->pattern.y, "grille_pattern");

    sauvegardeGrilleChar(fichier, partie->actuel.grille, partie->actuel.x, partie->actuel.y, "grille_actuel");

    sauvegardeGrilleInt(fichier, partie->indiceLigne, partie->nbIndiceMaxLigne, partie->pattern.y, "indices_lignes");

    sauvegardeGrilleInt(fichier, partie->indiceColonne, partie->nbIndiceMaxColonne, partie->pattern.x, "indices_colonnes");

    fprintf(fichier, "# Fin du fichier");
}
void sauvegardeGrilleInt(FILE * fichier, int **grille, int x, int y, char nom[50])
{
    fprintf(fichier, "#---------------\n\n");
    fprintf(fichier, "%s\n", nom);
    fprintf(fichier, "%d %d\n", y, x);
    int i, j;
    for (i = 0; i < y; i++)
    {
        for (j = 0; j < x; j++)
        {
            fprintf(fichier, "%d ", grille[i][j]);
        }
        fprintf(fichier, "\n");
    }
    fprintf(fichier, "#---------------\n\n");
}
void sauvegardeGrilleChar(FILE * fichier, char **grille, int x, int y, char nom[50])
{
    fprintf(fichier, "#---------------\n\n");
    fprintf(fichier, "%s\n", nom);
    fprintf(fichier, "%d %d\n", y, x);
    int i, j;
    for (i = 0; i < y; i++)
    {
        for (j = 0; j < x; j++)
        {
            fprintf(fichier, "%c ", grille[i][j]);
        }
        fprintf(fichier, "\n");
    }
    fprintf(fichier, "#---------------\n\n");
}
