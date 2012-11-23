##
## Makefile.in for moulinette in /home/hervie_g/epidev/projects/moulinette
## 
## Made by guillaume hervier
## Login   <hervie_g@epitech.net>
## 
## Started on  Thu Nov 22 17:56:44 2012 guillaume hervier
## Last update Thu Nov 22 17:56:51 2012 guillaume hervier
##

# Programs
CC		    			:= gcc
INSTALL	    			:= /usr/bin/install
RM 		    			:= /bin/rm
LEX 	    			:= /usr/bin/flex
YACC	    			:= /usr/bin/yacc

# Flags
CFLAGS	    			+= -Iinclude
LDFLAGS	    			+= 
RMFLAGS	    			+= -rf
LEXFLAGS				+= 
YACCFLAGS				+= 

# Some paths
prefix					:= /usr/local
exec_prefix				:= ${prefix}
includedir				:= ${prefix}/include
bindir					:= ${exec_prefix}/bin

O 						:= .o

PSRCS					:= src/parser.c src/lexer.c
SRCS					:= $(filter-out $(PSRCS), $(shell find src -type f -name "*.c"))
OBJS					=  $(SRCS:.c=.o)

NAME 					:= epinorme

all:					$(NAME)

$(NAME):				src/parser.o src/lexer.o $(OBJS)
	$(CC) -o $(NAME) $^ $(LDFLAGS)

src/parser.c:		src/parser.yy
	$(YACC) $(YACCFLAGS) -o $@ --defines=include/parser.h src/parser.yy

src/lexer.c:		src/lexer.lex
	$(LEX) $(LEXFLAGS) -o $@ src/lexer.lex

%.o:					%.c
	$(CC) $(CFLAGS) -c -o $@ $^

clean-parser:
	$(RM) $(RMFLAGS) src/parser.c src/lexer.c include/parser.h

clean:					clean-parser
	$(RM) $(RMFLAGS) $(OBJS)

fclean:					clean
	$(RM) $(RMFLAGS) $(NAME)

re:						fclean all

install:				$(NAME)
	$(INSTALL) $(NAME) $(bindir)

.PHONY:					all clean-parser clean fclean re install
