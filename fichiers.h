#ifndef FICHIERS_H_INCLUDED
#define FICHIERS_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include "structures.h"

void lectureDb (Niveau listeNiveaux [], char addressesSauvegardes [3][50] ); // charge la base de niveaux
Cases lectureNiveau (Niveau niveau); //Charge le niveau
void sauvegarde (Partie *partie);
void chargement (Partie *partie);
void enregistrerHistorique (Partie *partie);
void lireHistorique (ElementHistorique actuel);

#endif // FICHIERS_H_INCLUDED
