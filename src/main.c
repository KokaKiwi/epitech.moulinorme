#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <getopt.h>
#include "checker.h"

static int                  verbose_flag;
static char                 *input_filename = NULL;

void                        parse_args(int, char **);
void                        print_usage(char **);

int                         main(int argc, char **argv)
{
    FILE                    *fp;

    parse_args(argc, argv);
    if (input_filename != NULL)
    {
        fp = fopen(input_filename, "r");
    }
    else
    {
        fp = stdin;
    }
    if (fp != NULL)
    {
        check_file(fp);
        fclose(fp);
    }
    else
    {
        perror("Error");
    }
    return (0);
}

void                        parse_args(int argc, char **argv)
{
    static struct option    long_options[] = 
    {
        {"verbose", no_argument,    &verbose_flag, 1},
        {"brief",   no_argument,    &verbose_flag, 0},

        {0,         0,              0,              0}
    };
    int                     c;
    int                     option_index;

    while (1)
    {
        c = getopt_long(argc, argv, "", long_options, &option_index);

        if (c == -1)
        {
            break;
        }

        switch (c)
        {
            case 0:
                break;

            case '?':
                break;

            default:
                exit(0);
                break;
        }
    }

    if (optind < argc)
    {
        input_filename = argv[optind];
    }
}

void                        print_usage(char **argv)
{
    printf("Usage: %s <input file>\n", argv[0]);
}
