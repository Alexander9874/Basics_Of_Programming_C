//#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headers.h"

char* get_str() 
{
    char buf[81] = { 0 };
    char* res = NULL;
    int len = 0;
    int n = 0;
    do 
    {
        n = scanf("%80[^\n]", buf);
        if (n < 0) 
        {
            if (!res) 
            {
                return NULL;
            }
        }
        else if (n > 0) 
        {
            int chunk_len = strlen(buf);
            int str_len = len + chunk_len;
            res = realloc(res, str_len + 1);
            memcpy(res + len, buf, chunk_len);
            len = str_len;
        }
        else 
        {
            scanf("%*c");
        }
    } while (n > 0);

    if (len > 0) 
    {
        res[len] = '\0';
    }
    else 
    {
        res = calloc(1, sizeof(char));
    }

    return res;
}

int Keyboard(char letter) 
{
    char name[] ="Keyboard .txt";
    
    name[8] = letter;    

    FILE* file;
    file = fopen(name, "w");

    printf("To set EOF Esc\n\n");

    char* s = NULL;
    do 
    {
        s = get_str(); 
        if (s && (int)s[0] != 27) 
        {
            fprintf(file, "%s\n", s);
            free(s);
        }
        else
        {
        free(s);
        break;
        }
    } while (s);
    fclose(file);
    return 1;
}
