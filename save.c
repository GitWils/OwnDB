#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "employees.h"
#include "save.h"

void saveList(struct employee *empl)
{
	FILE *pfile;
	if((pfile = fopen("empl.dat", "a+b")) == NULL)
	{
		fputs("Can't open file empl.dat\n", stderr);
		exit(1);
	}
	rewind(pfile);
	for(int i = 0; i < getCount(); i++)
	{
		fwrite(empl, sizeof(struct employee) + 
				strlen(empl->fname + 1)*(int)sizeof(char), 1, pfile);
		//printf("%s\n", empl->fname);
		empl = getNext(empl); 
	}

	fclose(pfile);
	printf("\nsave.c file was here\n");
}
