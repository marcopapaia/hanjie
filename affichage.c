void affichage()
{

int tab[8][4];
int i;
int j;

    for (i = 0; i <= 8; i++)
        {
            for (j = 0; j <= 4; j++)
                {
                    printf(" ");
                    printf("%c%c%c", 0xE2, 0x96, 0x81);
                    printf(" \n");
                    printf("%c%c%c", 0xE2, 0x96, 0x95);
                    printf("%c%c%c", 0xE2, 0x96, 0x88);
                    printf("%c%c%c\n", 0xE2, 0x96, 0x8f);
                    printf(" ");
                    printf("%c%c%c", 0xE2, 0x96, 0x94);
                }
        }

}
