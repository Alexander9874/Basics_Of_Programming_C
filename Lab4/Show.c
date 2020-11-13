#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "headers.h"

char *fget_str(FILE* file) {
    char buf[81] = {0};
    char *res = NULL;
    int len = 0;
    int n = 0;
    do {
        n = fscanf(file, "%80[^\n]", buf);
        if (n < 0) {
            if (!res) {
                return NULL;
            }
        } else if (n > 0) {
            int chunk_len = strlen(buf);
            int str_len = len + chunk_len;
            res = realloc(res, str_len + 1);
            memcpy(res + len, buf, chunk_len);
            len = str_len;
        } else {
            fscanf(file, "%*c");
        }
    } while (n > 0);

    if (len > 0) {
        res[len] = '\0';
    } else {
        res = calloc(1, sizeof(char));
    }

    return res;
}

int Function(char* name) {
    FILE* file;
    file = fopen(name, "r");
    
    char *s = NULL;
    do {
        s = fget_str(file);
        if (s) {
            printf("%s\n", s);
            free(s);
        }
    } while (s);
    fclose(file);
    return 0;
}
int Show(int ikey, int igen, int ibub, int iqui)
{
    char gen, key, bub, qui, com[100];
    if (!(ikey > 65 || igen > 65 || ibub > 65 || iqui > 65))
    {
    	printf("\n	No files\n\n	Inpute Name	Cancel\n");
    	printf("\n	N		C\n");
    }
    else
    {
        if ((int)igen > 65) 
        {
            gen = 'G';
        }
        else
        { 
            gen = '\0';
        }
            if ((int)ikey > 65) 
        {
            key = 'K';
        }
        else
        {
            key = '\0';
        }
        if ((int)ibub > 65) 
        {
            bub = 'B';
        }
        else
        { 
            bub = '\0';
        }
        if ((int)iqui > 65) 
        {
            qui = 'Q';
        }
        else
        { 
            qui = '\0';
        }
    
        printf("	Chose file\n\n	Keyboard	Generated	Bouble		Quick		Inpute Name	Logfile		Cancel\n\nInput:");
        printf("	%c 		%c		%c		%c		N		L		C\n\nAnd:", key, gen, bub, qui);    
    
        int i = 65, j = 65, k = 65, q = 65;
    
        while (ikey > i || igen > j || ibub > k || iqui > q)
        {
            key = '\0';
            gen = '\0';
            bub = '\0';
            qui = '\0';
    	    if(ikey > i)
    	    {
    		    key = (char)i;
      	    }
    	    if(igen > j)
            {
    		    gen = (char)j;
    	    }
    	    if(ibub > k)
            {
    		    bub = (char)k;
    	    }
    	    if(iqui > q)
            {
    		    qui = (char)q;
    	    }
            printf("	%c		%c		%c		%c\n", key, gen, bub, qui);
      	    i++;
    	    j++;
    	    k++;
    	    q++;
        }
    }
    while (1)
    {
        printf(">>> ");
        scanf("%s", com);
    
        if (com[0] == 'C')
        {
            printf("\nCanceling\n");
            return 0;
        }
        else if (com[0] == 'K' && (int)com[1] > 64 && (int)com[1] < ikey)
        {
            char nick[] = "Keyboard .txt";
            nick[8] = com[1];
            Function(nick);
            break;
        }
        else if (com[0] == 'G' && (int)com[1] > 64 && (int)com[1] < igen)
        {
            char nick[] = "Generated .txt";
            nick[9] = com[1];
            Function(nick);
            break;
        }
        else if (com[0] == 'B' && (int)com[1] > 64 && (int)com[1] < ibub)
        {
            char nick[] = "Bouble .txt";
            nick[6] = com[1];
            Function(nick);
            break;
        }
        else if (com[0] == 'Q' && (int)com[1] > 64 && (int)com[1] < iqui)
        {
            char nick[] = "Quick .txt";
            nick[5] = com[1];
            Function(nick);
            break;
        }
        else if (com[0] == 'N')
        {
            printf("\n\nEnter file name\n\n>>> ");
            scanf("%s", com);
            Function(com);
            break;
        }
        else if (com[0] == 'L')
        {
            char nick[] = "Logfile.txxt";
            Function(nick);
            break;
        }
        else
        {
            printf("\nTry again\n");
        }
    }
    return(0);
}
