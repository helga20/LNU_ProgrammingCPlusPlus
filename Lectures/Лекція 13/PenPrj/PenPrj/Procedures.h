#ifndef _PROC_GUARD_
#define _PROC_GUARD_

#include "Pen.h"

void Proc();
int LoadPens(const char*, Pen*&);
Pen UsePens(Pen*, int);
void CatchException(Pen&);
void ShowColoredText(const char *);

#endif