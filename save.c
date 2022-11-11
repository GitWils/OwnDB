#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "employees.h"
#include "save.h"

void SaveList(struct employee *empl)
{
	FILE *pfile;
	if((pfile = fopen("empl.dat", "wb")) == NULL)
	{
		fputs("Can't open file \"empl.dat\"\n", stderr);
		return;
	}
	rewind(pfile);
	empl = GetLast();
	for(int i = 0; i < GetCount(); i++)
	{
		fwrite(empl, sizeof(struct employee), 1, pfile);
		empl = GetPrev(empl); 
	}

	fclose(pfile);
}

struct employee * LoadList(void)
{
	struct employee *preturn;	
	struct employee empl;
	FILE *pfile;
	if((pfile = fopen("empl.dat", "rb")) == NULL)
	{
		fprintf(stderr, "Can't open file \"empl.dat\"\n");
		return NULL;
	}
	rewind(pfile);
	while(fread(&empl, sizeof(struct employee), 1, pfile))
	{
		preturn = AddEmployee(empl.fname, empl.form);
	}
	fclose(pfile);
	preturn = GetFirst();
	return preturn;
}

void LogAddEmpl(char *name)
{
	char msg[200];
	char strTime[30];
	GetTimeStamp(strTime);
	sprintf(msg, "Employee \"%s\" was added %s\n", name, strTime);
	SaveToLog(msg);
}

void LogDelEmpl(char *name)
{
	char msg[200];
	char strTime[30];
	GetTimeStamp(strTime);
	sprintf(msg, "Employee \"%s\" was deleted %s\n", name, strTime);
	SaveToLog(msg);
}

void SaveToLog(char *str)
{

	FILE *pfile;
	if((pfile = fopen("log.txt", "a")) == NULL)
	{
		fprintf(stderr, "Can't open file \"log.txt\"\n");
		return;
	}
	fprintf(pfile, "%s", str);
	fclose(pfile);
}

void GetTimeStamp(char *str)
{
	time_t t;
	struct tm *pobjTime;
	//must use next line in FreeBSD
	t = time(NULL); 
	//or next line worked in Linux (UBUNTU)
	//time(&t);
	pobjTime = localtime(&t);
	//printf("\ntime is %s\n", asctime(pobjTime));
	sprintf(str, "%d.%d.%d %d:%d:%d",
			pobjTime->tm_mday, pobjTime->tm_mon,pobjTime->tm_year + 1900, 
			pobjTime->tm_hour, pobjTime->tm_min, pobjTime->tm_sec);
}
