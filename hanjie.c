#include "hanjie.h"

void hanjie (Partie *partie )
{
int posLig,posCol,p,i,j;
do{

printf("Quelle case voulez vous selectionner ? ");
scanf ("%d%d",&posCol ,&posLig);



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
}
while (posCol<10);
    }







