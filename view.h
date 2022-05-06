#pragma once

enum errList {ER_ID};
//enum errList erMsg;

void ShowHelpMsg();
void ShowListMsg(struct employee *empl);
void ShowAddMsg();
void ShowDelMsg(char *str);
void ShowInvitationMsg(bool first);
void ShowQuitMsg();
void ShowWrongMsg(char *msg);
void ShowByWidth(const char *str, int width);
void ShowErrorMsg(enum errList error);
