#ifndef STRUCTURES_H_INCLUDED
#define STRUCTURES_H_INCLUDED

enum TailleResultats
{
	_5x3,
	_7x4,
	_9x5,
	_11x6
};
typedef enum TailleResultats TailleResultats;
enum Difficulte
{
	FACILE,
	NORMAL,
	DIFFICILE
};
typedef enum Difficulte Difficulte;
enum TypeNiveau
{
	HANJIE
};
typedef enum Difficulte Difficulte;
struct Cases
{
	int grille [5][5];
	int hauteur;
	int largeur;
};
typedef struct Cases Cases;
struct Niveau
{
	char *addresse;
	char *nom;
	TypeNiveau type;
	Difficulte difficulte;
};
typedef struct Niveau Niveau;
struct Partie
{
	Cases pattern; //Solution du niveau
	Cases actuel; //Tableau remplis par l'utilisateur
	char pseudo [50];
	TailleResultats tailleResultats;
	Niveau niveau;
	long temp;
	long date;
};
typedef struct Partie Partie;
struct ElementHistorique
{
	long date;
	char pseudo [50];
	TypeNiveau type;
	Difficulte difficulte;
	long temp;
	ElementHistorique *suivant;
};
typedef struct ElementHistorique ElementHistorique;
#endif // STRUCTURES_H_INCLUDED
