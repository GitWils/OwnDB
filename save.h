#pragma once

void SaveList(struct employee *empl);
struct employee * LoadList(void);
void SaveToLog(char *str);
void LogAddEmpl(char *name);
void LogDelEmpl(char *name);
void GetTimeStamp(char *str);
