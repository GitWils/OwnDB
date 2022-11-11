#pragma once

#define MAX_EMPL_NAME 100

struct employee {	
	struct employee *pnext;
	struct employee *pprev;
	unsigned short int form;
	char fname[MAX_EMPL_NAME + 1];
	//char *fname;
};

struct employee * GetFirst();
struct employee * GetLast();
struct employee * GetNext(const struct employee *empl);
struct employee * GetPrev(const struct employee *empl);
struct employee * AddEmployee(char *name, int form);
void DelEmployee(struct employee *empl);
struct employee * GetEmplByNum(int id);
int GetCount();
void SwapEmployee(struct employee *a, struct employee *b);
void SortEmployees();
void ClearEmployee();
