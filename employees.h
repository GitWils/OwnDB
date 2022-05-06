#pragma once
struct employee {	
	struct employee *pnext;
	char fname[];
};

struct employee * GetFirst();
struct employee * GetLast();
struct employee * GetNext(struct employee *empl);
struct employee * AddEmployee(char *name);
void DelEmployee(struct employee *empl);
struct employee * GetEmplById(int id);
int GetCount();
void ClearEmployee();
