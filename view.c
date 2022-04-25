#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "employees.h"
#include "view.h"

void showInvitationMsg(bool first)
{
	if(first)
		printf("Type a command or help for watching command list:\n");
	else
		printf("Type another command or help for watching command list:\n");
}

void showListMsg(struct employee *empl)
{
	empl = getFirst();
	printf("------------------------------------------------------\n");
	printf("|%4s   |%23s                 |\n", "#", "name");
	printf("------------------------------------------------------\n");
	for(int i = 0; i < getCount(); i++)
	{
		printf("|%4d   |", i);
		showByWidth(empl->fname, 40);
		printf("|\n");
		empl = getNext(empl);
	}
	printf("------------------------------------------------------\n");
	showInvitationMsg(true);
}

void showByWidth(const char *str, int width)
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

void showAddMsg()
{

}

void showDelMsg()
{

}

void showQuitMsg()
{
	printf("Program is finished, see you later\n");
}

void showWrongMsg(char *msg)
{
	printf("Command \"%s\" is unknown.\n", msg);
}

void showHelpMsg()
{
	printf("List of commands:\n\n");
	printf("help - help menu\n");
	printf("list - show list of all entries\n");
	printf("add - add a new record\n");
	printf("del - delete entry\n");
	printf("...\nfew another commands is developing for now\n...\n");
	printf("quit - exit from program\n");
}
