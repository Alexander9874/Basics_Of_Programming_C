#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <unistd.h>

int main()
{
	char simbol = 32;
	int i;
	FILE *file;
	file = fopen("record.bin", "rb");

	while (1)
	{
		for (i = 0; i < 1920; i++)
		{
			if (!fread(&simbol, sizeof(char), 1, file))
			{
				fclose(file);
				return 0;
			}
			printf("%c", simbol);
		}
		sleep(1);
	}
}
