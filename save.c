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
		fputs("Can't open file \"empl.dat\"\n", stderr);
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
		fprintf(stderr, "Can't open file \"empl.dat\"\n");
		return NULL;
	}
	rewind(pfile);
	long unsigned a;
	while(fread(&a, sizeof(unsigned long), 1, pfile))
	{
		pempl = malloc(sizeof(struct employee)+a*(int)sizeof(char));
		fread(pempl, sizeof(struct employee) + sizeof(char)*a, 1, pfile);
		preturn = addEmployee(pempl->fname);
	}
	fclose(pfile);
	preturn = getFirst();
	return preturn;
}

void logAddEmpl(char *name)
{
	fprintf(stderr, "Employee \"%s\" was added successfully\n", name);
	FILE *pfile;
	if((pfile = fopen("log.txt", "a")) == NULL)
	{
		fprintf(stderr, "Can't open file \"log.txt\"\n");
		exit(2);
	}
	fprintf(pfile, "Employee \"%s\" was added\n", name);
	fclose(pfile);
}
