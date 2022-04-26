#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "employees.h"
#include "save.h"

void saveList(struct employee *empl)
{
	FILE *pfile;
	if((pfile = fopen("empl.dat", "wb")) == NULL)
	{
		fputs("Can't open file \"empl.dat\"\n", stderr);
		return;
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
		return;
	}

	char strTime[30];
	getTimeStamp(strTime);
	fprintf(pfile, "Employee \"%s\" was added %s\n", 
			name, strTime);
	fclose(pfile);
}

void getTimeStamp(char *str)
{
	struct tm *pobjTime;
	time_t t;
	t = time(NULL);
	pobjTime = localtime(&t);
	sprintf(str, "%d.%d.%d %d:%d:%d",
			pobjTime->tm_mday, pobjTime->tm_mon,pobjTime->tm_year + 1900, 
			pobjTime->tm_hour, pobjTime->tm_min, pobjTime->tm_sec);
}
