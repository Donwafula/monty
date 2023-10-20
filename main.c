#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

ssize_t getline(char **lineptr, size_t *n, FILE *stream);

mlist_t gs;

/**
 * main - Monty bytecode interpreter
 * @ac: Argument count
 * @av: Argument variables entered from the command line
 * Return: 0 on success
 */
int main(int ac, char **av)
{
	FILE *FD;
	ssize_t glcount = 0;
	char *buffer = NULL;
	size_t bufflen = 0;

	monty_l_init();
	if (ac != 2)
	{
		monty_exit(-1, NULL);
	}

	FD = fopen(av[1], "r");
	if (FD == NULL)
	{
		monty_exit(-2, av[1]);
	}

	gs.fd = FD;
	while (glcount != -1)
	{
		gs.ln++;
		glcount = getline(&buffer, &bufflen, FD);
		if (glcount == -1)
			break;

		gs.buffer = buffer;
		monty_opcode(buffer);
	}

	monty_dest();
	return (EXIT_SUCCESS);
}
