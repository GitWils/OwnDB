#include <stdio.h>
#include <stdlib.h> // malloc(), free()
#include <string.h> // strncpy()
#include <stdbool.h>
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

	pempl = malloc(sizeof(struct employee));
	if (pempl == NULL)
		exit (1);

	strncpy(pempl->fname, name, MAX_EMPL_NAME);
	pempl->form = form;
	pempl->pnext = phead;
	pempl->pprev = NULL;

	if(pempl->pnext == NULL)
		ptail = pempl;
	if(phead)
		phead->pprev = pempl;
	phead = pempl;
	pempl = NULL;
	cnt++;
	return phead;
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
	int i = 1;
	while(pempl->pnext && i != id)
	{
		pempl = GetNext(pempl);
		i++;
	}
	return pempl;
}

void SwapEmployee(struct employee *a, struct employee *b)
{
	struct employee *ppreva, *pnexta, *temp;
	
	pnexta = a->pnext;
	ppreva = a->pprev;

	if(GetPrev(a) && GetPrev(a) != b)
	{
		temp = GetPrev(a);
		temp->pnext = b; 	
	}
	if(GetNext(a) && GetNext(a) != b)
	{
		temp = GetNext(a);
		temp->pprev = b;
	}
	if(GetPrev(b) && GetPrev(b) != a)
	{
		temp = GetPrev(b);
		temp->pnext = a;
	}
	if(GetNext(b) && GetNext(b) != a)
	{
		temp = GetNext(b);
		temp->pprev = a;
	}

	if(b == GetPrev(a)) //b located before a
	{
		a->pprev = b->pprev;
		a->pnext = b;
		b->pprev = a;
		b->pnext = pnexta;
	}
	else if(b == GetNext(a)) //b located after a
	{
		a->pprev = b;
		a->pnext = b->pnext;
		b->pprev = ppreva;
		b->pnext = a;
	}
	else //a and b are not neighbors
	{
		a->pprev = b->pprev;
		a->pnext = b->pnext;
		b->pprev = ppreva;
		b->pnext = pnexta;
	}

	if(a->pprev == NULL)	
		phead = a;		
	else if(b->pprev == NULL)
		phead = b;
	if(a->pnext == NULL)
		ptail = a;
	else if(b->pnext == NULL)
		ptail = b;
}

void SortEmployees()
{
	bool changes;
	struct employee *current, *next;
	do
	{
		changes = false;
		current = phead;
		//next = GetNext(current);
		while(current->pnext)
		{
			next = GetNext(current);
			if(strcmp(current->fname, next->fname) > 0)
			{
				SwapEmployee(current, next);
				changes = true;
			}
			else
			{
				current = next;
			}
		}
	} while(changes);
}

void ClearEmployee()
{
	if(!GetCount())
		return;
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
