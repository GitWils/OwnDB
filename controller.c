#include <stdio.h>
#include <string.h>
#include "controller.h"

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
			clearBuffer();
	}
	//trim stroke
	n = strlen(st);
	n--;
	while(n >= 0 && (*(st+n) == ' ' || *(st+n) == '\n'))
	{
		*(st+n) = '\0';
		n--;
	}
	return ret_val;
}

void clearBuffer()
{
	while(getchar() != '\n')
		continue;
}
