#include <stdio.h>
#include <string.h> //strchr()
#include <stdbool.h>

#include "employees.h"
#include "save.h"
#include "view.h"
#include "controller.h"

enum cmdList {help, list, add, del, sort, quit};
const char * strCmdList[] = {"help", "list", "add", "del", "sort", "quit"};

int main(void)
{	
	struct employee *pobjEmplList;
	pobjEmplList = loadList();
	const int iCmdLength = 10;
	char strChoice[iCmdLength];
	const int iFNameLength = 40;
	char strFName[iFNameLength];
	enum cmdList eCommand;
	bool bIsCmd = false;

	showInvitationMsg(true);
	while(eCommand != quit 
				&&s_gets(strChoice, iCmdLength) != NULL 
				&& strChoice[0] != '\0')
	{
		for(eCommand = help; eCommand <= quit; eCommand++)
		{
			if(strcmp(strChoice, strCmdList[eCommand]) == 0)
			{
				bIsCmd = true;
				break;
			}
		}
		if(bIsCmd)
		{
			switch(eCommand)
			{
				case help:					
					showHelpMsg();
					break;
				case list:
					showListMsg(pobjEmplList);
					break;
				case add:
					showAddMsg();
					if(s_gets(strFName, iFNameLength))
					{
						addEmployee(strFName);
						logAddEmpl(strFName);
					}
					break;
				case sort:
					break;
				case del:
					showDelMsg();
					break;
				default:
					break;
			}
			bIsCmd = false;
		}
		else
		{
			showWrongMsg(strChoice);
		}
		if(eCommand != help)
			showInvitationMsg(true);
	}
	saveList(pobjEmplList);
	clearEmployee();
	showQuitMsg();

	return 0;
}
