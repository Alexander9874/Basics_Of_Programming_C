#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include "header.h"

void Player(List *list)
{
	Item *ptr = list->last;
	srand(time(NULL));

	while (ptr->data != 86)
	{
		ptr = ptr->left;
	}

	int num = rand();

	if(!ptr->right->down)
	{
		ptr->left->data = 86;
		ptr->data = 32;
	}
	if(num % 5 == 0)
	{
		ptr->up->data = 94;
	}
	else if (num % 2 == 0)
	{
		ptr->right->data = 86;
		ptr->data = 32;
	}
	else
	{
		ptr->left->data = 86;
		ptr->data = 32;
	}
	if (num % 3 == 0)
	{
		ptr->up->data = 94;
	}
}

int Check(List *list)
{
	Item *ptr = list->first;
	
	while (ptr && ptr->data != 77)
	{
		ptr = ptr->right;
	}
	
	if (!ptr) 
	{
		remove("save.bin");
		printf("\n\n\n\n\n\n\n\n\n\n\n		The\n		Victory!\n\n\n\n\n\n\n\n\n\n\n\n");
		sleep(4);
		return 1;
	}
	else return 0;
}

void Game_Over(List *list)
{
	remove("save.bin");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n				Game\n				Over\n\n\n\n\n\n\n\n\n\n\n");
	sleep(4);
}

int Die(List *list, Item *ptr)
{
	Item *life = list->last;
	while (life->left->data != 58)
	{
		life = life->left;
	}

	if (life->data != 48)
	{
		life->data--;
		ptr->data = 32;
		sleep(1);
		return 0;
	}
	else
	{
		Game_Over(list);
		return 1;
	}
}

void Score(List *list)
{
	Item *ptr = list->first->right;
	while (ptr->left->data != 58)
	{
		ptr = ptr->right;
	}
	ptr = ptr->right->right;
	ptr->data++;
	
	if(ptr->data == 58)
	{
		ptr->data -= 10;
		ptr->left->data++;

		if(ptr->left->data == 58)
		{
			ptr->left->data -= 10;
			ptr->left->left->data++;
		}
	}
}

void Down(List *list)
{
	Item *ptr = list->last;

	while (ptr)
	{
		if (ptr->data == 77)
		{
			if (ptr->down->data == 32)
			{
				ptr->down->data = 77;
				ptr->data = 32;
			}
			if (ptr->down->data == 42)
			{
				ptr->down->data = 35;
				ptr->data = 32;
			}
		}
		ptr = ptr->left;
	}
}

void Right(List* list)
{
	Item *ptr = list->last;

	while (ptr)
	{
		if (ptr->data == 77)
		{
			if (ptr->right->data == 32 || ptr->right->data == 94)
			{
				ptr->right->data = 77;
				ptr->data = 32;
			}
			if (ptr->right->data == 42)
			{
				ptr->right->data = 35;
				ptr->data = 32;
			}
		}
		ptr = ptr->left;
	}
}

void Left(List* list)
{
        Item *ptr = list->first;

        while (ptr)
        {
                if (ptr->data == 77)
                {
                        if (ptr->left->data == 32 || ptr->left->data == 94)
                        {
                                ptr->left->data = 77;
                                ptr->data = 32;
                        }
                        if (ptr->left->data == 42)
                        {
                                ptr->left->data = 35;
                                ptr->data = 32;
                        }
                }
		ptr = ptr->right;
        }
}


void Bomb(List *list)
{
	srand(time(NULL));
	Item *ptr = list->last;

	while (ptr)
	{
		if (ptr->data == 77 && ptr->down->down->down->data != 77 && rand()%4 == 0)
		{
			ptr->down->data = 42;
		}

		ptr = ptr->left;
	}
}

int Bomb_Move(List* list)
{
	Item *ptr = list->first;
	while(ptr)
	{
		if (ptr->data == 35)
		{
			ptr->data = 32;
		}
		ptr = ptr->right;
	}

	ptr = list->last;
	while (ptr)
	{
		if (ptr->data == 42)		// *
		{
			if(!ptr->down)
			{
				ptr->data = 35;
			}
			else if (ptr->down->data == 32)
			{
				ptr->down->data = 42;
				ptr->data = 32;
			}
			else if (ptr->down->data == 94)
			{
				ptr->data = 32;
				ptr->down->data = 35;
			}
			else if (ptr->down->data == 86)
			{
				if (Die(list, ptr)) return 1;
			}
		}
		ptr = ptr->left;
	}

	ptr = list->first;
	while (ptr)
	{
		if (ptr->data == 94)		// ^
		{
			if (!ptr->up)
			{
				ptr->data = 32;
			}
			else if (ptr->up->data == 32)
			{
				ptr->data = 32;
				ptr->up->data = 94;
			}
			else if (ptr->up->data == 77)
			{
				ptr->up->data = 35;
				ptr->data = 32;
				Score(list);
				if (Check(list)) return 1;
			}
			else if (ptr->up->data == 42)
			{
				ptr->data = 32;
				ptr->up->data = 35;
			}
			else
			{
				ptr->data = 32;
			}
		}
		ptr = ptr->right;
	}
	return 0;
}
