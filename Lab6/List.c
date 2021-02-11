#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include "header.h"

List* Create(int num)
{
	List *list = (List*)calloc(1, sizeof(List));
	int i;
	FILE *file;

	if (num == 2) file = fopen("save.bin", "rb");
	if (num == 1 || file == NULL) file = fopen("model.bin", "rb");

	Item* prev = (Item*)calloc(1, sizeof(Item));
	list->first = prev;
	fread(&(prev->data), sizeof(char), 1, file);

	for (i = 0; i < 1919; i++)
	{
		Item *new = (Item*)calloc(1, sizeof(Item));
		fread(&(new->data), sizeof(char), 1, file);
		prev->right = new;
		new->left = prev;
		prev = new;
	}
	fclose(file);
	list->last = prev;

	prev = list->first;

	for(i = 0; i < 80; i++)
	{
		prev = prev->right;
	}

	Item *new = list->first;
	new->down = prev;
	prev->up = new;

	for(i = 0; i < 1839; i++)
	{
		new = new->right;
		prev = prev->right;

		new->down = prev;
		prev->up = new;	
	}

	return list;
}

int Time(List *list)
{
	Item *ptr = list->first;

	while (ptr->right->right->data != 115)
	{
		ptr = ptr->right;
	}

	if (--ptr->data < 48)
	{
		if(--ptr->left->data < 48)
		{
			if(--ptr->left->left->data < 48) return 1;
			ptr->left->data = 57;
		}
		ptr->data = 57;
	}
	return 0;
}

int Print(List *list)
{
	if(Time(list))
	{
		printf("\n\n\n\n\n\n\n\n\n\n\n					Time\n					out\n\n\n\n\n\n\n\n\n\n\n");
		sleep(4);
		return 1;
	}

	Item *cur = list->first;
	FILE *save, *record;
	save = fopen("save.bin", "wb");
	record = fopen("record.bin", "ab");

	while (cur)
	{
		fwrite(&(cur->data), sizeof(char), 1, save);
		fwrite(&(cur->data), sizeof(char), 1, record);
		printf("%c", cur->data);
		cur = cur->right;
	}
	fclose(save);
	fclose(record);
	return 0;
}


void Delete(List *list)
{
	Item *ptr = list->first, *prev;
	while(ptr)
	{
		prev = ptr;
		ptr = ptr->right;
		free(prev);	
	}
	free(list);
}

int Play_Record()
{
	char simbol;
	int i;
	FILE *file;
	file = fopen("record.bin", "rb");

	while (1)
	{
		for (i = 0; i < 1920; i++)
		{
			if(!fread(&simbol, sizeof(char), 1, file))
			{
				fclose(file);
				return 0;
			}
			printf("%c", simbol);
		}
		sleep(1);
	}
}
