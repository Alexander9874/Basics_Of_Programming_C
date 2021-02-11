#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "header.h"

typedef struct Item
{
	char letter;
	struct Item *next;
	struct Item *space;
	int place;
} Item;

typedef struct List
{
	struct Item *first;
} List;
	
int main()
{
	Item *previous = NULL;
	int place = 0, num, rep, i, j, k;
	char letter;
	double duration = 0;
//	List* list = Create_List();

	FILE *file;
	file = fopen("Log.txt", "a");

	printf("Enter number of words and repeats\n>>> ");
	scanf("%d %d", &num, &rep);

	srand(time(NULL));

	for (i = 0; i < rep; i++)
	{
		for (j = 1; j <= num; j++)
		{
			duration = 0;
			List* list = Create_List();
			for (k = 1; k <= j; k++)
			{
				int length = 4 + rand()%12;
				for (place = 1; place <= length; place++)
				{
					letter = 97 + rand()%26;
					clock_t begin = clock();
					previous = Insert(letter, place, previous, list);
					clock_t end = clock();
					duration += (double)(end - begin) / CLOCKS_PER_SEC;
				}
				previous = NULL;
			}
			Show_Delete(list);
			fprintf(file, "%.6lf\n", duration);
		}
		fprintf(file, "\n");
	}
	
	fclose(file);
	return 0;
}
