#include "monty.h"

/**
  * monty_pall -  function prints all values on stack from the top
  * @head: void
  * @line_c: void
  */
void monty_pall(stack_t **head, unsigned int line_c)
{
	stack_t *list;
	(void)head;
	(void)line_c;

	list = gs.tail;
	if (gs.size == 0)
	{
		return;
	}

	for (; list; list = list->prev)
	{
		printf("%d\n", list->n);
	}
}

/**
  * monty_mod - top two modulo elements of the stack
  * @head: void
  * @line_c: the store integer from node
  */
void monty_mod(stack_t **head, unsigned int line_c)
{
	(void)head;

	if (gs.size < 2)
	{
		monty_exit(-8, "mod");
	}

	line_c = gs.tail->n;
	if (line_c == 0)
	{
		monty_exit(-9, NULL);
	}

	monty_l_remove(gs.tail);
	line_c %= gs.tail->n;
	gs.tail->n = line_c;
}

/**
 * monty_l_remove - function removes node from doubly linked list
 * @node: the stack to be removed
 * Return: 0 on sucess else -1 if stack is empty
 */
int monty_l_remove(stack_t *node)
{
	if (node == NULL || gs.size == 0)
	{
		return (-1);
	}

	if (node == gs.head)
	{
		gs.head = node->next;
		if (gs.head == NULL)
		{
			gs.tail = NULL;
		}
		else
		{
			node->next->prev = NULL;
		}
	}
	else
	{
		node->prev->next = node->next;
		if (node->next == NULL)
		{
			gs.tail = node->prev;
		}
		else
		{
			node->next->prev = node->prev;
		}
	}

	free(node);
	gs.size--;
	return (0);
}

/**
 * monty_pchar - function rotates the stack to the bottom
 * @head: the beginning of stack
 * @line_c: the integer in stack
*/
void monty_pchar(stack_t **head, unsigned int line_c)
{
	int don;
	(void) head;
	(void) line_c;

	if (gs.size == 0)
	{
		monty_exit(-6, "pchar");
	}

	don = gs.tail->n;
	if (don < 0 || don > 127)
	{
		monty_exit(-10, NULL);
	}

	printf("%c\n", don);
}

/**
 * monty_pstr - function rotates the stack to the bottom
 * @head: the beginning of stack
 * @list_c: integer in stack
 */
void monty_pstr(stack_t **head, unsigned int list_c)
{
	stack_t *list;
	(void) head;
	(void) list_c;

	list = gs.tail;
	for (; list; list = list->prev)
	{
		if (list->n == 0)
		{
			break;
		}

		printf("%c", list->n);
	}

	printf("\n");
}
