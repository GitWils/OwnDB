#include <stdio.h>
#include <stdlib.h> // malloc(), free()
#include <string.h> // strncpy()
#include "employees.h"

int cnt = 0;
struct employee *phead = NULL;
struct employee *ptail = NULL;

struct employee * GetFirst()
{
	return phead;
}

struct employee * GetLast()
{
	return ptail;
}

struct employee * GetNext(struct employee *empl)
{
	return empl->pnext;
}

struct employee * GetPrev(struct employee *empl)
{
	return empl->pprev;
}

//add employee to begin
struct employee * AddEmployee(char *name, int form)
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
	pempl->form = form;
	pempl->pnext = phead;
	pempl->pprev = NULL;
	phead = pempl;
	if(pempl->pnext == NULL)
		ptail = pempl;
	else
		pempl->pnext->pprev = pempl;	
	cnt++;
	return pempl;
}

void DelEmployee(struct employee *empl)
{
	//struct employee * a;
}

int GetCount()
{
	return cnt;
}


struct employee * GetEmplById(int id)
{
	if(id > cnt - 1)
		return NULL;
	struct employee *pempl;
	pempl = phead;
	for(int i = 1; i < cnt; i++)
	{
		pempl = GetNext(pempl);
		if(i == id)
			return pempl;
	}
	return pempl;
}

void ClearEmployee()
{
	struct employee *pdel;
	while(phead->pnext) 
	{
		pdel = phead;
		phead = GetNext(phead);
		free(pdel);
		cnt--;
	}
	free(phead);
	cnt--;
	phead = NULL;
}
