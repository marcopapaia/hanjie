#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a,b;

    do {
    printf(" Bienvenue pour jouer a une partie de Hanjie \n\n Que voulez vous faire ?\n");
    printf("\t1=Jouer une partie\n\t2=Voir l'historique des parties\n\t3=Quitter  " );
    scanf("\n%d",&a);

        if (a==1) {
            system("clear");

            do {
            printf(" Menu de partie \n ");
            printf("\t1=Nouvelle partie\n\t2=Charger une partie\n\t3=Revenir au menu \n " );
            scanf("\n%d",&b);

            switch (b) {
                case 1 :{
                    system("clear");
                    //hanjie();
                }
                case 2 : {
                    system("clear");
                    //sauvegarde();
                }

                }

                }
                while (b>3);
                system("clear");
                return main();


                };
        if (a==2){
            system("clear");

            };

        if (a==3){
            system("clear");
            return 0;
            }

            }

        while (a>3);

    system("PAUSE");
    return 0 ;
}


