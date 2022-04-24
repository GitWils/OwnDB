#include <stdio.h>
#include <string.h> //strchr()
#include "employees.h"
#include "save.h"

char * s_gets(char *st, int n);

int main(void)
{	
	struct employee *a;
	a = loadList();
	if(getCount())
	{		
		printf("Loaded structures fnames is:\n");
		for(int i = 0; i < getCount(); i++)
		{
			printf("%s\n", a->fname);
			a = getNext(a);
		}
	}
	//addEmployee("Ksenka");
	//addEmployee("Юрій Леонідович");
	//addEmployee("Solia");
	printf("cnt = %d\n", getCount());
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
