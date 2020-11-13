#include <stdio.h>
#include <stdlib.h>					// data[i][j][k]
#include <time.h>
#include <string.h>

typedef struct pers
{
	char Name[16];
	char Car[16];
	char ID[9];
}pers;


int main(int NUM)
{	
	char* labels[] = { "Audi", "BMW", "Porsche", "Opel", "Volvo", "Volkswagen", "Mercedes", "Maybach", "Lamborghini", "Ferrari" };
	int count[10] = { 0 }, i, j;
	NUM = 100;
	
	//pers* data = (pers*)calloc(NUM, sizeof(pers));
	pers data[NUM];
	
	FILE* file;
	file = fopen("KeyboardA.txt", "r");
	
	for (i = 0; i < NUM; i++)
	{
		fscanf(file, "%s %s %s", data[i].Name, data[i].Car, data[i].ID);
		for (j = 0; j < 10; j++)
		{
			printf("%s / %s\n", data[i].Car, labels[j]);
			if (strcmp (data[i].Car, labels[j]) == 0)
			{
				count[j]++;
				break;
			}
		}
	}
	fclose(file);
	
	file = fopen("Logfile.txt", "a");
	for (i = 0; i < 10; i++)
	{
		printf("%s: % d\n", labels[i], count[i]);
		fprintf(file, "%s: % d\n", labels[i], count[i]);
	}	
	
	//free(data);
	
	fclose(file);
	return(0);
}
