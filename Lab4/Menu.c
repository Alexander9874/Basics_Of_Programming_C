#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "headers.h"

int Menu()
{
    int num;
    printf("\nExit: 0\n"
        "Generate: 1\n"
        "KeyBoard: 2\n"
        "Sort Bouble: 3\n"
        "Sort Quick: 4\n"
        "Count: 5\n"
        "Show: 6\n");
    while (1)
    {
        printf("\n>>> ");
        scanf("%d", &num);
        if (num >= 0 && num < 7)
        {
            return num;
        }

        printf("Try again\n");
    }
}
