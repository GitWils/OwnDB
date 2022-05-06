#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "employees.h"
#include "view.h"

void ShowInvitationMsg(bool first)
{
	if(first)
		printf("Type a command or help for watching command list:\n");
	else
		printf("Type another command or help for watching command list:\n");
}

void ShowListMsg(struct employee *empl)
{
	empl = GetFirst();
	printf("+-------+-----------------------------------+---------+\n");
	printf("|%4s   |%21s              |%7s  |\n", "#", "name", "group");
	printf("+-------+-----------------------------------+---------+\n");
	for(int i = 0; i < GetCount(); i++)
	{
		printf("|%4d   | ", i + 1);
		ShowByWidth(empl->fname, 34);
		printf("|   %2d    |\n", empl->form);
		empl = GetNext(empl);
	}
	printf("+-------+-----------------------------------+---------+\n");
}

void ShowByWidth(const char *str, int width)
{
	int len;
	len = strlen(str);
	if(width > len)
	{
		printf("%s", str);
		if(*str < 0)//for cyrylic symbols
		{
			len /= 2;
			len++;
		}
		for(int i = 0; i < width-len; i++)
		{
			printf(" ");
		}
	}
	else
	{
		for(int i = 0; i < width; i++)
		{
			putchar(*(str+i));
		}	
	}
}

void ShowAddMsg()
{
	printf("Write the first name:\n");
}

void ShowDelMsg(char *str)
{
	if(str)
		printf("Do you realy want to delete \"%s\"? (press y or n) ", str);
	else
		printf("Write the number of the employee you want to delete:\n");
}

void ShowQuitMsg()
{
	printf("Program is finished, see you later\n");
}

void ShowWrongMsg(char *msg)
{
	printf("Unknown command \"%s\".\n", msg);
}

void ShowHelpMsg()
{
	printf("List of possible commands:\n\n");
	printf("help - help menu\n");
	printf("list - show list of all entries\n");
	printf("add - add a new record\n");
	printf("del - delete entry\n");
	printf("sort - sorting list by names\n");
	printf("quit - exit from program\n\n");
	printf("Make your choice.\n");
}


void ShowErrorMsg(enum errList eError)
{
	switch(eError)
	{
		case ER_ID:
			printf("Error: wrong id number entered\n");
			break;
	}
}
