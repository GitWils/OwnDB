#include <stdio.h>
#include <string.h> //strchr()
#include "employees.h"

char * s_gets(char *st, int n);

int main(void)
{
	struct employee *a;
	addEmployee("Ksenka");
	addEmployee("Юрій Леонідович");
	addEmployee("Solia");
	a = getFirst();
	do {
		printf("%s структура занимает %zu байт\n", a->fname, sizeof(*a));
		a = getNext(a);
	}
	while(a);
	printf("count = %d\n", getCount());
	clearEmployee();

	return 0;
}

char * s_gets(char *st, int n)
{
	char *ret_val;
	char *find;

	ret_val = fgets(st, n, stdin);
	if(ret_val)
	{
		find = strchr(st, '\n');
		if(find)
			*find = '\0';
		else
			while(getchar() != '\n')
				continue;
	}
	return ret_val;
}
