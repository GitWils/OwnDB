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
			ClearBuffer();
	}
	//trim stroke
	n = strlen(st);
	n--;
	while(n >= 0 && (*(st+n) == ' ' || *(st+n) == '\n'))
	{
		*(st+n) = '\0';
		n--;
	}
	//ClearGarbage(st);
	return ret_val;
}

void ClearBuffer()
{
	while(getchar() != '\n')
		continue;
}

//clearing garbage fron utf8 characters
//that 
void ClearGarbage(char *str)
{
	int garbages = 0;
	for(int i = 0; i < strlen(str); i++)
	{
		if(str[i] == '\320' || str[i] == '\321')
			garbages++;
		else
			str[i - garbages] = str[i];
	}
}
