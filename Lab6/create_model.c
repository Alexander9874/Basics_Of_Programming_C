#include <stdlib.h>
#include <stdio.h>

void main()
{
	FILE *file;
	file = fopen("model.bin", "wb");

	int i;
	char letter;

	for(i = 0; i < 1920; i++)
	{
		letter = getchar();
//		fprintf(file, (char)letter);
		fwrite(&letter, sizeof(char), 1, file);
	}

	fclose(file);
}
