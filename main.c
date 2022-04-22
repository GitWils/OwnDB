#include <stdio.h>
#include <string.h> //strchr()
#include "employees.h"
#include "save.h"

char * s_gets(char *st, int n);

int main(void)
{
	struct employee *a;
	addEmployee("Ksenka");
	addEmployee("Юрій Леонідович");
	addEmployee("Solia");
	a = getFirst();
	for(int i = 0; i < getCount(); i++)
	{
		printf("%s структура занимает %zu байт", a->fname, sizeof(*a));
		printf(" + %ld байт занимает имя\n",
					(strlen(a->fname) + 1)*(unsigned long)sizeof(char));
		a = getNext(a);
	}
	printf("count = %d\n", getCount());
	a = getFirst(a);
	saveList(a);
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
