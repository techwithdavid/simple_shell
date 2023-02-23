CC=gcc
CFLAGS=-Wall -Werror -Wextra -pedantic
LIBS=
EXENAME=hsh

CFILES=\
	alias1.c\
	alias2.c\
	inventory.c\
	builtin_1.c\
	builtin_2.c\
	cd.c\
	env1.c\
	env2.c\
	execute.c\
	file_io.c\
	free.c\
	getline.c\
	helper1.c\
	helper2.c\
	history.c\
	mem.c\
	parser_1.c\
	parser_2.c\
	link_path.c\
	pipeline.c\
	parsetree.c\
	custom_stdlib.c\
	str_funcs1.c\
	str_funcs2.c\
	str_funcs3.c\
	tokenizer.c\
	tokens.c\
	processor.c\
	printer.c

GLOBAL_HEADERS=\
	shell.h

# Make goals
all: $(GLOBAL_HEADERS) $(CFILES) main.c
	$(CC) $(CFLAGS) $(CFILES) main.c -o $(EXENAME) $(LIBS)

debug: $(GLOBAL_HEADERS) $(CFILES) main.c
	$(CC) $(CFLAGS) $(CFILES) main.c -o $(EXENAME) $(LIBS) -g

clean:
	rm -f $(EXENAME)
