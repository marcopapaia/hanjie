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
typedef enum TypeNiveau TypeNiveau;
struct Cases
{
	int **grille;
	int y;
	int x;
};
typedef struct Cases Cases;

struct Partie
{
	Cases pattern; //Solution du niveau
	Cases actuel; //Tableau remplis par l'utilisateur
	char pseudo [50];
	TailleResultats tailleResultats;
	long temp;
	long date;
    TypeNiveau type;
	Difficulte difficulte;
};
typedef struct Partie Partie;
struct ElementHistorique
{
	long date;
	char pseudo [50];
	TypeNiveau type;
	Difficulte difficulte;
	long temp;
	struct ElementHistorique *suivant;
};
typedef struct ElementHistorique ElementHistorique;
#endif // STRUCTURES_H_INCLUDED
