#include "parser.h"
#include "checker.h"

extern int  yylineno;
extern int  column;

int         note = 0;

void        check_file(FILE *fp)
{
    yyin = fp;
    yyparse();
    printf("Note: %d\n", note);
}

void        check_note(int modifier, const char *msg)
{
    note += modifier;
    printf("%-50s (L%d) [%+d]\n", msg, yylineno, modifier);
}
