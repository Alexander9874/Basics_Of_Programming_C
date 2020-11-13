#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "headers.h"

void main()
{
    FILE* file;
    file = fopen("Logfile.txt", "w");
    fprintf(file, "File name		Time\n");
    fclose(file);
    
    int choice = 0; 
    char gen = 65, key = 65, bub = 65, qui = 65;

    while ((choice = Menu()) != 0)
    {
        switch (choice)
        {
        case 1:
            gen += Generate(gen);
            break;
        case 2:
            key += Keyboard(key);
            break;
        case 3:
            bub += Sort_Bouble((int)key, (int)gen, bub);	//I've changed from INT to CHAR for BUB
            break;
        case 4:
            qui += Sort_Quick((int)key, (int)gen, qui);
            break;
        case 5:
            printf("\nCount\n");
            break;
        case 6:
            Show((int)key, (int)gen, (int)bub, (int)qui);
            break;
        }
    }
}
