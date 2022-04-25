#include <stdio.h>
#include <string.h> //strchr()
#include <stdbool.h>

#include "employees.h"
#include "save.h"
#include "view.h"
#include "controller.h"

enum cmdList {help, list, add, del, quit};
const char * strCmdList[] = {"help", "list", "add", "del", "quit"};

int main(void)
{	
	struct employee *pobjEmplList;
	pobjEmplList = loadList();
	const int iCmdLength = 10;
	char strChoice[iCmdLength];
	enum cmdList eCommand;
	bool bIsCmd = false;
	/*if(getCount())
	{		
		printf("Loaded structures fnames is:\n");
		for(int i = 0; i < getCount(); i++)
		{
			printf("%s\n", pobjA->fname);
			pobjA = getNext(pobjA);
		}
	}*/
	
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
			showInvitationMsg(false);
		}
	}
	//addEmployee("Ksenka");
	//addEmployee("Юрій Леонідович");
	//addEmployee("Solia");
	saveList(pobjEmplList);
	clearEmployee();
	showQuitMsg();

	return 0;
}
