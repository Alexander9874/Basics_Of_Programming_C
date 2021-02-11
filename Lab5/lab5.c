#include <stdio.h>
#include <stdlib.h>
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
	int place = 0;
	char letter;
	List* list = Create_List();

	printf("Enter your string\n");

	while (1)
	{
		letter = getchar();

		if (letter == 32 || letter == 9)
		{
			place = 0;
			previous = NULL;
			continue;
		}

		if (letter == 10)
		{
			Show_Delete(list);
			list = Create_List();
			place = 0;
			previous = NULL;
			continue;
		}

		if (letter == 27)
		{
			Show_Delete(list);
			break;
		}

		place++;
		previous = Insert(letter, place, previous, list);
	}
	return 0;
}
