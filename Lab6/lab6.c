#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>
#include "header.h"

int Menu()
{
	char num;
	while (1)
	{	
		printf("\n\n\n\n\n\n\n\n\n				Space Invaders\n\n				Exit:0\n				New Game:1\n				Continue:2\n                                Play record:3\n\n\n\n\n\n\n\n\n");
		scanf("%c", &num);
		if(num < 48 || num > 51)
		{
			continue;
		}
		else
		{
			if (num == 48) return (0);
			if (num == 49) return (1);
			if (num == 50) return (2);
			if (num == 51) return (3);
		}
	}
}

int main()
{
	int i;

	while (1)
	{
		i = Menu();
		if (i == 0) return 0;
		
		if (i == 3)
		{
			Play_Record();
			continue;
		}

		remove("record.bin");
		List* list = Create(i);
		Print(list);
		sleep(2);

		Comb(list);
		Delete(list);
	}
}
