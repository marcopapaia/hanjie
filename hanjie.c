#include "hanjie.h"

void hanjie (Partie *partie )
{
int posLig,posCol;
do{
    system("clear");
    affichage(partie);

    printf("Quelle case voulez vous selectionner ? ");
    scanf ("%d%d",&posCol ,&posLig);

if (partie->pattern.grille[posCol][posLig]=='0'){
    partie->pattern.grille[posCol][posLig]='1';



}

else{
    partie->pattern.grille[posCol][posLig]='0';
    system("clear");
    affichage(partie);

}


}
while (posCol<10);
    }







