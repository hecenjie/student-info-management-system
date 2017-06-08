#ifndef TOOLS_H_INCLUDED
#define TOOLS_H_INCLUDED

typedef struct _password{
   char account[20];
   char password[20];
}Password;

int countpass;
Password password[30];

void WritePass();
void ReadPass();

#endif // TOOLS_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>




