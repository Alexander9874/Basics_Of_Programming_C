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

List* Create_List()
{
	List *list = (List*)calloc(1, sizeof(List) + 1);
	Item *new = (Item*)calloc(1, sizeof(Item) + 1);
	list->first = new;
	new->letter = 32;
	new->place = 0;
	return list;
}

int Compare(Item *first, Item *second, int place)
{
	int i;
	for (i = 1; i <= place; i++)
	{
		first = first->next;
		second = second->next;

		if (second->place == 0)
		{
			return 1;
		}

		if (first->letter < second->letter)
		{
			return 0;
		}

		if (first->letter > second->letter)
		{
			return 1;
		}
	}
	return 0;
}

Item* Insert(char letter, int place, Item *previous, List *list)
{
	Item *new = (Item*)malloc(sizeof(Item));	//
	new->letter = letter;				// Create new item
	new->place = place;				//

	Item *check;

	if (place == 1)						// This part is TRUE
	{
		Item* space = (Item*)malloc(sizeof(Item));	//
		new->next = space;				//
		new->space = space;				// Create new space after new item
		space->place = 0;				//
		space->letter = 32;				//

		Item* check = list->first;

		while (check->next && check->next->letter < letter)
		{
			check = check->space;
		}

		space->next = check->next;	//
		space->space = check->space;	//
						// Insert new item and new space into list
		check->next = new;		//
		check->space = space;		//

		return check;			// Return space before first letter of new word
	}

	check = previous;

	while (check->next->place)
	{
		check = check->next;
	}

	new->space = check->space;	//
	new->next = check->next;	// Insert letter into word
	check->next = new; 		//

	check = previous->space;
	while (check->space && Compare(previous, check, place))
	{
		check = check->space;
	}

	if (check != previous->space)
	{
		Item buf;				//
		buf.next = previous->space->next;	// Make buffer
		buf.space = previous->space->space;	//

		previous->space->next = check->next;		//
		previous->space->space = check->space;		//
								//  Replace
		check->next = previous->next;			//
		check->space = previous->space;			//   Word
								//
		previous->next = buf.next;			//
		previous->space = buf.space;			//
		
		return check;
	}

	return previous;	
}

void Show_Delete(List *list)
{
	Item *current = list->first->next;
	Item *previous = list->first;
	free(previous);

	while (current)
	{
		previous = current;
		current = current->next;
		printf("%c", previous->letter);
		free(previous);
	}

	printf("\n");
	free(list);
}
