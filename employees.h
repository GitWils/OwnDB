#pragma once
struct employee {	
	struct employee *pnext;
	struct employee *pprev;
	unsigned short int form;
	char fname[];
};

struct employee * GetFirst();
struct employee * GetLast();
struct employee * GetNext(const struct employee *empl);
struct employee * GetPrev(const struct employee *empl);
struct employee * AddEmployee(char *name, int form);
void DelEmployee(struct employee *empl);
struct employee * GetEmplByNum(int id);
int GetCount();
void ClearEmployee();
