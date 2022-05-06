#pragma once
struct employee {	
	struct employee *pnext;
	struct employee *pprev;
	unsigned short int form;
	char fname[];
};

struct employee * GetFirst();
struct employee * GetLast();
struct employee * GetNext(struct employee *empl);
struct employee * GetPrev(struct employee *empl);
struct employee * AddEmployee(char *name, int form);
void DelEmployee(struct employee *empl);
struct employee * GetEmplById(int id);
int GetCount();
void ClearEmployee();
