#pragma once
struct employee {	
	struct employee *pnext;
	char fname[];
};

struct employee * getFirst();
struct employee * getLast();
struct employee * getNext(struct employee *empl);
struct employee * addEmployee(char *name);
void delEmployee(struct employee *empl);
struct employee * getEmplById(int id);
int getCount();
void clearEmployee();
