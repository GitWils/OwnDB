#include <stdio.h>
#include <stdbool.h>
#include "view.h"

void showInvitationMsg(bool first)
{
	if(first)
		printf("Type a command or help for watching command list:\n");
	else
		printf("Type another command or help for watching command list:\n");
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
	printf("...\nfew another commands is developing for now\n...\n");
	printf("quit - exit from program\n");
}
