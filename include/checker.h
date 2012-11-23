#ifndef CHECKER_H_
#define CHECKER_H_

#include <stdio.h>

void            check_file(FILE *);
void            check_note(int, const char *);

extern FILE     *yyin;

#endif