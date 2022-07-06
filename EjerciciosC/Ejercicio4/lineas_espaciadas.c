#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{

	FILE *fp;
	int length_line = 80;
	char line[length_line];
	int len;

	fp = fopen(argv[1], "r");

	// error archivo entrada
	if (fp == NULL || argc < 2)
	{
		printf("ERROR\n");
		return 1;
	}

	while (fgets(line, length_line, fp) != NULL)
	{
		len = strlen(line);
		// new line
		if (line[len - 1] == '\n')
		{
			printf("%s\n", line);
		}
	}
	fclose(fp);
	return 0;
}
