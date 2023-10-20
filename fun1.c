#include "monty.h"

/**
  * monty_push - function pushes element to the stack
  * @head: void
  * @line_c: function check if malloc fails
  */

void monty_push(stack_t **head, unsigned int line_c)
{
	(void)head;

	if (gs.mode == 1)
	{
		line_c = monty_end(gs.intarg);
	}
	else
	{
		line_c = monty_beg(gs.intarg);
	}

	if (line_c == 42)
	{
		monty_exit(-5, NULL);
	}
}

/**
  * monty_mul - function multiply top two elements of the stack
  * @head: void
  * @line_c: interger stored from node
  */
void monty_mul(stack_t **head, unsigned int line_c)
{
	(void)head;

	if (gs.size < 2)
	{
		monty_exit(-8, "mul");
	}

	line_c = gs.tail->n;
	monty_l_remove(gs.tail);
	line_c *= gs.tail->n;
	gs.tail->n = line_c;
}

/**
 * monty_l_init - function initializes doubly linked list
 */
void monty_l_init(void)
{
	gs.size = 0;
	gs.ln = 0;
	gs.head = NULL;
	gs.tail = NULL;
	gs.fd = NULL;
	gs.buffer = NULL;
	gs.intarg = 0;
	gs.mode = 1;
}

/**
  * monty_exit - function prints out error messages and exits failure
  * @doc: the corresponding error code
  * @command: the opcode failure occured on
  **/
void monty_exit(int doc, char *command)
{
	doc *= -1;
	switch (doc)
	{
		case 1:
			printf("USAGE: monty file\n");
			break;
		case 2:
			printf("Error: Can't open file %s\n", command);
			break;
		case 3:
			printf("L%d: unknown instruction %s\n", gs.ln, command);
			break;
		case 4:
			printf("L%d: usage: push integer\n", gs.ln);
			break;
		case 5:
			printf("Error: malloc failed\n");
			break;
		case 6:
			printf("L%d: can't %s, stack empty\n", gs.ln, command);
			break;
		case 7:
			printf("L%d: can't pop an empty stack\n", gs.ln);
			break;
		case 8:
			printf("L%d: can't %s, stack too short\n", gs.ln, command);
			break;
		case 9:
			printf("L%d: division by zero\n", gs.ln);
			break;
		case 10:
			printf("L%d: can't pchar, value out of range\n", gs.ln);
			break;
	}
	monty_dest();
	exit(EXIT_FAILURE);
}

/**
 * monty_chgmode - function changes mode: stack to que
 * @head: Unused
 * @line_c: Unused
 */
void monty_chgmode(stack_t **head, unsigned int line_c)
{
	(void) head;
	(void) line_c;

	gs.mode *= -1;
}
