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
	pobjEmplList = LoadList();
	const int iCmdLength = 10;
	char strChoice[iCmdLength];
	const int iFNameLength = 40;
	char strFName[iFNameLength];
	enum cmdList eCommand;
	bool bIsCmd = false;

	ShowInvitationMsg(true);
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
					ShowHelpMsg();	
					break;
				case list:
					ShowListMsg(pobjEmplList);	
					break;
				case add:
					ShowAddMsg();
					if(s_gets(strFName, iFNameLength))
					{
						AddEmployee(strFName, 3);
						LogAddEmpl(strFName);
					}
					break;
				case del:
					ShowDelMsg(NULL);
					int id;
					struct employee *a;
					while(!scanf("%d", &id))
					{
						printf("id must be a number\n");
						ClearBuffer();
					}
					ClearBuffer();
					a = GetEmplById(id - 1);
					if(a)
					{
						ShowDelMsg(a->fname);
						char answer;

						while(!scanf("%c", &answer) || (answer != 'y' && answer != 'n'))
						{
							printf("Answer (%c) must be \"y\" or \"n\" keys: ", answer);
							if(answer == 'y')
								DelEmployee(a);
							ClearBuffer();
						}
					}
					else
						ShowErrorMsg(ER_ID);
					ClearBuffer();
					break;
				case sort:
					break;
				default:
					break;
			}
			bIsCmd = false;
		}
		else
		{
			ShowWrongMsg(strChoice);
		}
		if(eCommand != help)
			ShowInvitationMsg(true);
	}
	SaveList(pobjEmplList);
	ClearEmployee();
	ShowQuitMsg();

	return 0;
}
