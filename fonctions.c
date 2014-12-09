#include "fonctions.h"


void SystemPause()
{
   char magickey;
   fflush(stdin);
   printf("Appuyez sur une touche pour continuer...");
   scanf("%c", &magickey);
   magickey = getc(stdin);
}
