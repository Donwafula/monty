#include "monty.h"

/**
* monty_swap - function swaps top two elements of stack
* @head: void
* @line_c: function store integer from node
*/
void monty_swap(stack_t **head, unsigned int line_c)
{
	(void)head;
	if (gs.size <= 2)
	{
		monty_exit(-8, "swap");
	}

	line_c = gs.tail->n;
	gs.tail->n = gs.tail->prev->n;
	gs.tail->prev->n = line_c;
}

/**
  * monty_add - function adds top two elements of the stack
  * @head: void
  * @line_c: void
  */
void monty_add(stack_t **head, unsigned int line_c)
{
	(void)head;

	if (gs.size < 2)
	{
		monty_exit(-8, "add");
	}

	line_c = gs.tail->n;
	monty_l_remove(gs.tail);
	line_c += gs.tail->n;
	gs.tail->n = line_c;
}

/**
 * monty_dest - Closes file descriptor and frees buffer.
 */
void monty_dest(void)
{
	while (gs.size > 0)
	{
		monty_l_remove(gs.tail);
	}

	if (gs.fd != NULL)
	{
		fclose(gs.fd);
	}

	if (gs.buffer != NULL)
	{
		free(gs.buffer);
	}
}

/**
 * monty_rotr - function rotates the stack to the bottom
 * @head: the beginning of stack
 * @list_c: the integer in stack
*/
void monty_rotr(stack_t **head, unsigned int list_c)
{
	(void) head;
	if (gs.size == 0)
	{
		monty_exit(0, NULL);
	}

	list_c = gs.head->n;
	monty_end(list_c);
	monty_l_remove(gs.head);
}

/**
* monty_nop - the function does nothing
* @head: voided
* @list_c: voided
*/
void monty_nop(stack_t **head, unsigned int list_c)
{
	(void)head;
	(void)list_c;
}
