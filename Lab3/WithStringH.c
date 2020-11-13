// Find words in a string that consist of the same letters,
// but differ in their order in the word record

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

// Compare two words for the same words
// Return -1 if fail, 0 if success
int CheckUp(int Efirst, int Elast, int Cfirst, int Clast, char* pointer)
{
	if ((Elast - Efirst) == (Clast - Cfirst))
	{
		int length = Elast - Efirst, i, j;
		char* new = calloc(length + 1, sizeof(char));

		for (i = 0; i < length; i++)
		{
			*(new + i) = *(pointer + i + Cfirst);
		}

		*(new + length) = '\n';
		short int value = 1;

		for (i = Efirst; i < Elast && value == 1; i++)
		{
			value = 0;
			for (j = 0; j < length && value == 0; j++)
			{
				if (*(pointer + i) == *(new + j))
				{
					value = 1;
					*(new + j) = '\0';
				}
			}
		}
		if (value == 1)
		{
			free(new);
			return (0);
		}
		free(new);
	}
	return (-1);
}

// Find and set the start of the word
// Return the pointer's index of the space after the last symbol of the word
int Make(int* beginning, char* string)
{
	if (*(string + *beginning) == '\n')
	{
		return -1;
	}

	while (*(string + *beginning) == ' ')
	{
		*beginning += 1;
	}

	int ending = *beginning;

	while (*(string + ending) != ' ')
	{
		if (*(string + ending) == '\n')
		{
			break;
		}
		ending++;
	}

	return ending;
}

// Output the word 
// If argument is 1 the word is the first in the line
// If argument is 0 the word is not the first
void Output(int start, int finish, int num, char* string)
{
	int i;
	if (num == 1)
	{
		printf("\nCombination: ");
		for (i = start; i < finish; i++)
		{
			printf("%c", *(string + i));
		}
	}
	else
	{
		for (i = start; i < finish; i++)
		{
			printf("%c", *(string + i));
			*(string + i) = ' ';
		}
	}
	printf(" ");
}

int main()
{
	char* words = calloc(2000, sizeof(char));
	int Estart = 0, i, j, count;
	int Eend = 0, Cstart = 0, Cend = 0;

	printf("Please, enter your string.\n");

	scanf("%1999[^\n]", words);
	
	clock_t begin = clock();

	*(words + strlen(words)) = '\n';

	while (1)
	{
		count = 0;
		Eend = Make(&Estart, words);

		if (Eend == -1)
		{
			break;
		}

		Cstart = Eend;

		while (1)
		{
			Cend = Make(&Cstart, words);

			if (Cend == -1)
			{
				break;
			}

			if (CheckUp(Estart, Eend, Cstart, Cend, words) == 0)
			{
				count++;

				if (count == 1)
				{
					Output(Estart, Eend, 1, words);
				}

				Output(Cstart, Cend, 0, words);
			}
			Cstart = Cend;
		}
		Estart = Eend;
	}
	printf("\n\n");
	free(words);
	
	clock_t end = clock();
	double time = (double)(end - begin) / CLOCKS_PER_SEC;
	printf("Time: %.8lf seconds", time);
		
	return(0);
}
