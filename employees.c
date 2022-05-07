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

struct employee * GetNext(const struct employee *empl)
{
	return empl->pnext;
}

struct employee * GetPrev(const struct employee *empl)
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

	if(pempl->pnext == NULL)
		ptail = pempl;
	if(phead)
		phead->pprev = pempl;
	phead = pempl;
	cnt++;
	return pempl;
}

void DelEmployee(struct employee *empl)
{
	struct employee *next, *prev;
	next = GetNext(empl);
	prev = GetPrev(empl);

	if(next)
		next->pprev = empl->pprev;
	else
		ptail = empl->pprev;

	if(prev)
		prev->pnext = empl->pnext;
	else 
		phead = empl->pnext;

	free(empl);
	cnt--;
}

int GetCount()
{
	return cnt;
}


struct employee * GetEmplByNum(int id)
{
	if(id > cnt)
		return NULL;
	struct employee *pempl;
	pempl = phead;
	if(id > 1)
	{
		for(int i = 2; i <= cnt; i++)
		{
			pempl = GetNext(pempl);
			if(i == id)
				return pempl;
		}
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
