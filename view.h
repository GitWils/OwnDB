#pragma once

enum errList {ER_ID};
//enum errList erMsg;

void showHelpMsg();
void showListMsg(struct employee *empl);
void showAddMsg();
void showDelMsg(char *str);
void showInvitationMsg(bool first);
void showQuitMsg();
void showWrongMsg(char *msg);
void showByWidth(const char *str, int width);
void showErrorMsg(enum errList error);
