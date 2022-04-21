struct employee {	
	struct employee *pnext;
	char fname[];
};

struct employee * getFirst();
struct employee * getLast();
struct employee * getNext(struct employee *empl);
struct employee * addEmployee(char *name);
int getCount();
void clearEmployee();
