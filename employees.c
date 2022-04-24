#include <stdio.h>
#include <stdlib.h> // malloc(), free()
#include <string.h> // strncpy()
#include "employees.h"

int cnt = 0;
struct employee *phead = NULL;
struct employee *ptail = NULL;

struct employee * getFirst()
{
	return phead;
}

struct employee * getLast()
{
	return ptail;
}

struct employee * getNext(struct employee *empl)
{
	return empl->pnext;
}

//add employee to begin
struct employee * addEmployee(char *name)
{
	struct employee *pempl;
	size_t name_size;
	name_size = strlen(name)+1;
	if(name_size > 40)	
	{
		*(name+39) = '\0';
		name_size = 40;
	}	
	pempl = malloc(sizeof(struct employee)+name_size*sizeof(char));
	if (pempl == NULL)
		exit (1);
	strncpy(pempl->fname, name, 40);
	pempl->pnext = phead;
	phead = pempl;
	cnt++;
	if(pempl->pnext == NULL)
		ptail = pempl;
	return pempl;
}

int getCount()
{
	return cnt;
}

void clearEmployee()
{
	struct employee *pdel;
	while(phead->pnext) 
	{
		pdel = phead;
		phead = getNext(phead);
		free(pdel);
		cnt--;
	}
	free(phead);
	cnt--;
	phead = NULL;
}
