#include "hanjie.h"

void hanjie (Partie *partie )
{
int posLig,posCol;
do{

if (partie->pattern.grille[posCol][posLig]=='0'){
    partie->pattern.grille[posCol][posLig]='1';
    system("clear");
    affichage(partie);


}

else{
    partie->pattern.grille[posCol][posLig]='0';
    system("clear");
    affichage(partie);

}

printf("Quelle case voulez vous selectionner ? ");
scanf ("%d%d",&posCol ,&posLig);
}
while (posCol<10);
    }







