#include "monty.h"

/**
* monty_pint- prints value on the top of the stack
* @head: void
* @line_c: void
*/
void monty_pint(stack_t **head, unsigned int line_c)
{
	(void)head;
	(void)line_c;

	if (gs.size == 0)
	{
		monty_exit(-6, "pint");
	}

	printf("%d\n", gs.tail->n);
}

/**
  * monty_div - function divides top two elements of the stack
  * @head: void
  * @line_c: function store integer from node
  */
void monty_div(stack_t **head, unsigned int line_c)
{
	(void)head;

	if (gs.size < 2)
	{
		monty_exit(-8, "div");
	}

	line_c = gs.tail->n;
	if (line_c == 0)
	{
		monty_exit(-9, NULL);
	}

	monty_l_remove(gs.tail);
	line_c /= gs.tail->n;
	gs.tail->n = line_c;
}

/**
 * monty_end - function adds node at the end ofdoubly linked list
 * @line_c: int to be stored in node
 * Return: 0 on sucess else 42 if malloc fails
 */
int monty_end(const int line_c)
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
		done = gs.tail;
		nnode->next = done->next;
		nnode->prev = done;
		gs.tail = nnode;
		done->next = nnode;
	}

	gs.size++;
	return (0);
}

/**
 * monty_int - function checks argument after opcode for integer
 * @list_c: the argument thats being checked to be integer
 * Return: -4 if strtok fails else 0
 */
int monty_int(const char *list_c)
{
	int xuk, done;

	if (list_c == NULL)
	{
		return (-4);
	}

	for (xuk = 0; list_c[xuk]; xuk++)
	{
		if (list_c[xuk] == '-' && list_c[xuk + 1] != '-')
		{
			continue;
		}

		done = isdigit(list_c[xuk]);
		if (done == 0)
		{
			return (-4);
		}
	}

	gs.intarg = atoi(list_c);
	return (0);
}
