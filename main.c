#include <stdio.h>
#include <string.h> //strchr()
#include <stdbool.h>

#include "employees.h"
#include "save.h"
#include "view.h"
#include "controller.h"

enum cmdList {help, quit};
const char * strCmdList[] = {"help", "quit"};

int main(void)
{	
	struct employee *pobjA;
	pobjA = loadList();
	int iCmdLength = 10;
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
					bIsCmd = false;
					break;
				default:
					break;
			}
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
	saveList(pobjA);
	clearEmployee();
	showQuitMsg();

	return 0;
}
