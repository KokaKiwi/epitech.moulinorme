#include "parser.h"
#include "checker.h"
#include "parser_states.h"

int     in_function = 0;

void    enter_function()
{
    in_function = 1;
}

void    exit_function()
{
    in_function = 0;
}
