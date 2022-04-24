#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "employees.h"
#include "save.h"

void saveList(struct employee *empl)
{
	FILE *pfile;
	if((pfile = fopen("empl.dat", "wb")) == NULL)
	{
		fputs("Can't open file empl.dat\n", stderr);
		exit(1);
	}
	rewind(pfile);
	empl = getFirst();
	for(int i = 0; i < getCount(); i++)
	{
		long unsigned a;
		a = strlen(empl->fname) + 1;
		fwrite(&a, sizeof(long unsigned), 1, pfile);
		fwrite(empl, sizeof(struct employee) + 
				sizeof(char)*(int)(strlen(empl->fname)+1), 1, pfile);
		empl = getNext(empl); 
	}

	fclose(pfile);
	//printf("\nsave.c file was here\n");
}

struct employee * loadList(void)
{
	struct employee *pempl, *preturn;
	FILE *pfile;
	if((pfile = fopen("empl.dat", "rb")) == NULL)
	{
		return NULL;
	}
	rewind(pfile);
	long unsigned a;
	while(fread(&a, sizeof(unsigned long), 1, pfile))
	{
		pempl = malloc(sizeof(struct employee)+a*(int)sizeof(char));
		fread(pempl, sizeof(struct employee) + sizeof(char)*a, 1, pfile);
		preturn = addEmployee(pempl->fname);
		//free(pempl);
	}
	preturn = getFirst();
	return preturn;
}
