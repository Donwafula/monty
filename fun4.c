#include "monty.h"

/**
  * monty_pop - function removes the top element of the stack
  * @head: void
  * @line_c: void
  */
void monty_pop(stack_t **head, unsigned int line_c)
{
	(void)head;
	(void)line_c;

	if (gs.size == 0)
	{
		monty_exit(-7, NULL);
	}

	monty_l_remove(gs.tail);
}

/**
  * monty_sub - function subtracts top two elements of the stack
  * @head: void
  * @line_c: function stores interger from node
  */
void monty_sub(stack_t **head, unsigned int line_c)
{
	(void)head;

	if (gs.size < 2)
	{
		monty_exit(-8, "sub");
	}

	line_c = gs.tail->prev->n;
	line_c -= gs.tail->n;
	gs.tail->prev->n = line_c;
	monty_l_remove(gs.tail);
}

/**
 * monty_beg - function adds to beginning of doubly linked list
 * @line_c: the int to be stored in node
 * Return: 0 on sucess else 42 if malloc fails
 */
int monty_beg(const int line_c)
{
	stack_t *nnode, *done;

	nnode = malloc(sizeof(stack_t));
	if (nnode == NULL)
	{
		return (42);
	}

	nnode->n = line_c;
	if (gs.size == 0)
	{
		gs.head = nnode;
		gs.head->prev = NULL;
		gs.head->next = NULL;
		gs.tail = nnode;
	}
	else
	{
		done = gs.head;
		nnode->next = done;
		nnode->prev = done->prev;
		gs.head = nnode;
		done->prev = nnode;
	}

	gs.size++;

	return (0);
}

/**
 * monty_opcode - function  searches for commands and executes them
 * @pork: the opcode taken from from file
 * Return: 0 if empty line or comment.
 */
int monty_opcode(char *pork)
{
	instruction_t cmd[] = {
		{"swap", monty_swap}, {"pall", monty_pall}, {"pint", monty_pint},
		{"pop", monty_pop}, {"add", monty_add}, {"push", monty_push},
		{"pstr", monty_pstr}, {"sub", monty_sub}, {"mul", monty_mul},
		{"mod", monty_mod}, {"rotl", monty_rotl}, {"rotr", monty_rotr},
		{"nop", monty_nop}, {"queue", monty_chgmode}, {"stack", monty_chgmode},
		{"pchar", monty_pchar}, {"div", monty_div}, {NULL, NULL}
	};

	char *limiter = " \t\n\r", *opcode, *intg;
	unsigned int xax;
	int iarg = 0;

	opcode = strtok(pork, limiter);
	if (opcode == NULL || opcode[0] == '#')
		return (0);

	for (xax = 0; cmd[xax].f != NULL; xax++)
	{
		if (strcmp(opcode, cmd[xax].opcode) == 0)
		{
			if (xax == 0)
			{
				intg = strtok(NULL, limiter);
				iarg = monty_int(intg);
				if (iarg == -4)
					monty_exit(-4, NULL);
			}
			cmd[xax].f(NULL, 0);
			break;
		}
	}

	if (cmd[xax].f == NULL)
		monty_exit(-3, opcode);

	return (0);
}

/**
 * monty_rotl - function rotates the stack to the top
 * @head: the beginning of stack
 * @line_c: the integer in stack
 */
void monty_rotl(stack_t **head, unsigned int line_c)
{
	(void) head;
	if (gs.size == 0)
	{
		monty_exit(0, NULL);
	}

	line_c = gs.tail->n;
	monty_beg(line_c);
	monty_l_remove(gs.tail);
}
