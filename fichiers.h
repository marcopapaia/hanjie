#ifndef FICHIERS_H_INCLUDED
#define FICHIERS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "structures.h"

void lectureDb (char listeNiveaux [3][3][100], char addressesSauvegardes [3][100] ); // charge la base de niveaux
Cases* lectureNiveau (char addresse [100]); //Charge le niveau
void sauvegarde (Partie *partie);
void chargement (Partie *partie);
void enregistrerHistorique (Partie *partie);
void lireHistorique (ElementHistorique actuel);

#endif // FICHIERS_H_INCLUDED
