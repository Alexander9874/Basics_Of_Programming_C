#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "headers.h"

typedef struct pers
{
	char Name[16];
	char* Car;
	char ID[9];
}pers;

int main(char letter)
{
	char* labels[] = { "Audi", "BMW", "Porsche", "Opel", "Volvo", "Volkswagen", "Mercedes", "Maybach", "Lamborghini", "Ferrari" };
	
	char name[] = "Generated .txt";
	//name[9] = letter;
	FILE* file;
	file = fopen(name, "w");
    
	int i, j, lim, var, NUM = 100;
	pers data[NUM];

	srand(time(NULL));
	clock_t begin = clock();
	
	for(i = 0; i < NUM; i++)
	{
		lim = 4 + rand() % 13;
		for (j = 0; j < lim; j++)
		{
			var = (rand() % 26) + 65 + 32;
			if (j == 0)
			{
				var -= 32;
			}
			data[i].Name[j] = (char)var; 
		}
		lim = rand() % 10;
		data[i].Car = labels[lim];
		for (j = 0; j < 10; j++)
		{
			data[i].ID[j] = 48 + rand() % 10 + (rand() % 2) * (rand() % 18 + 16);	
		}
	fprintf(file, "%s %s %s\n", data[i].Name, data[i].Car, data[i].ID);
	}
	fclose(file);
	
	clock_t end = clock();
	double time = (double)(end - begin) / CLOCKS_PER_SEC;
	
	file = fopen("Logfile.txt", "a");
	fprintf(file, "%s:	%.8lf seconds\n", name, time);
	fclose(file);
    
	printf("\nGenerated successfully, saved into %s\n", name);
	return(1);
}
