#include "monty.h"
#include <stdio.h>

/**
 * m_add - adds the top and the second element of the stack
 * @head: pointer to head
 * @line_count: current line number
 * Return: void function
 */
void m_add(stack_t **head, unsigned int line_count)
{
	stack_t *temp;
	int valor;

	if (!head || !(*head) || !(*head)->next)
	{
		dprintf(2, "L%u: can't add, stack too short\n", line_count);
		free_all();
		exit(EXIT_FAILURE);
	}
	temp = *head;

	valor = temp->n + temp->next->n;
	m_pop(head, line_count);
	m_pop(head, line_count);
	add_node(head, valor);
}

/**
 * add_node - add node at begining of double linked list
 * @head: pointer to hed
 * @n: integer
 * Return: number of nodes
 */
stack_t *add_node(stack_t **head, const int n)
{
	stack_t *new, *temp;

	new = malloc(sizeof(stack_t));
	if (!new)
		return (NULL);
	new->n = n;
	new->prev = NULL;
	temp = *head;
	if (!*head)
	{
		new->next = NULL;
	}
	else
	{
		new->next = temp;
		temp->prev = new;
	}
	*head = new;
	return (new);
}

/**
 * delete_node - delete node at nth index of double linked list
 * @head: pointer to head
 * @index: integer
 * Return: address of node inserted at the nth index or null if failed
 */
int delete_node(stack_t **head, unsigned int index)
{
	stack_t *temp;
	unsigned int i = 0;

	if (!*head)
		return (-1);
	temp = *head;
	if (index == 0)
	{
		if (temp->next)
		{
			temp->next->prev = NULL;
			*head = temp->next;
		}
		else
			*head = NULL;
		free(temp);
		return (1);
	}
	while (temp)
	{
		if (i == index)
		{
			if (temp->next)
			{
				temp->prev->next = temp->next;
				temp->next->prev = temp->prev;
			}
			else
				temp->prev->next = NULL;
			free(temp);
			return (1);
		}
		temp = temp->next;
		i++;
	}
	return (-1);
}

/**
 * m_div - divs the top and the second element of the stack
 * @head: pointer to head
 * @line_count: current line number
 * Return: void function
 */
void m_div(stack_t **head, unsigned int line_count)
{
	stack_t *temp;
	int valor;

	if (!head || !(*head) || !(*head)->next)
	{
		dprintf(2, "L%u: can't div, stack too short\n", line_count);
		free_all();
		exit(EXIT_FAILURE);
	}
	temp = *head;

	if (temp->n == 0)
	{
		dprintf(2, "L%u: division by zero\n", line_count);
		free_all();
		exit(EXIT_FAILURE);
	}
	valor = temp->next->n / temp->n;
	m_pop(head, line_count);
	m_pop(head, line_count);
	add_node(head, valor);
}

/**
 * free_all - function for free
 */
void free_all(void)
{
	stack_t *node_free;
	stack_t *temp = NULL;

	node_free = *global_free;

	while (node_free)
	{
		temp = node_free->next;
		free(node_free);
		node_free = temp;
	}
}

/**
 * m_mod - mods the top and the second element of the stack
 * @head: pointer to head
 * @line_count: current line number
 * Return: void function
 */
void m_mod(stack_t **head, unsigned int line_count)
{
	stack_t *temp;
	int valor;

	if (!head || !(*head) || !(*head)->next)
	{
		dprintf(2, "L%u: can't mod, stack too short\n", line_count);
		free_all();
		exit(EXIT_FAILURE);
	}
	temp = *head;
	if (temp->n == 0)
	{
		dprintf(2, "L%u: division by zero\n", line_count);
		free_all();
		exit(EXIT_FAILURE);
	}
	valor = temp->next->n % temp->n;
	m_pop(head, line_count);
	m_pop(head, line_count);
	add_node(head, valor);
}

/**
 * monty_function - search monty functions
 * @operator: function to search
 * @node: pointer to head
 * @count_lines: current line number
 * Return: void function
 */
void monty_function(char *operator, stack_t **node, unsigned int count_lines)
{
	size_t i;

	instruction_t valid_com[] = {
		{"push", m_push},
		{"pall", m_pall},
		{"pint", m_pint},
		{"pop", m_pop},
		{"swap", m_swap},
		{"add", m_add},
		{"sub", m_sub},
		{"div", m_div},
		{"mod", m_mod},
		{"mul", m_mul},
		{"pchar", m_pchar},
		{"pstr", m_pstr},
		{"rotl", m_rotl},
		{"rotr", m_rotr},
		{"nop", m_nop},
		{NULL, NULL}
	};
	for (i = 0; valid_com[i].opcode; i++)
	{
		if (strcmp(valid_com[i].opcode, operator) == 0)
		{
			valid_com[i].f(node, count_lines);
			return;
		}
	}
	dprintf(2, "L%u: unknown instruction %s\n", count_lines, operator);
	free_all();
	exit(EXIT_FAILURE);
}

/**
 * m_mul - muls the top and the second element of the stack
 * @head: pointer to head
 * @line_count: current line number
 * Return: void function
 */
void m_mul(stack_t **head, unsigned int line_count)
{
	stack_t *temp;
	int valor;

	if (!head || !(*head) || !(*head)->next)
	{
		dprintf(2, "L%u: can't mul, stack too short\n", line_count);
		free_all();
		exit(EXIT_FAILURE);
	}
	temp = *head;

	valor = temp->n * temp->next->n;
	m_pop(head, line_count);
	m_pop(head, line_count);
	add_node(head, valor);
}

/**
 * m_nop - doesn't do anything
 * @head: pointer to head
 * @count_lines: current line number
 * Return: void function
 */
void m_nop(stack_t **head, unsigned int count_lines)
{
	(void) head;
	(void) count_lines;
}

/**
 * m_pall - print the stack
 * @head: doble pointer to head of d linked list
 * @line_count: current line of monty file
 * Return: returns void
 */
void m_pall(stack_t **head, __attribute__((unused)) unsigned int line_count)
{
	stack_t *temp = *head;

	if (*head && head)
	{
		while (temp)
		{
			printf("%d\n", temp->n);
			temp = temp->next;
		}
	}
}

/**
 * m_pchar - prints top stack number as ascii
 * @node: pointer to head
 * @line_count: current line number
 * Return: void function
 */
void m_pchar(stack_t **node, unsigned int line_count)
{
	int num = 0;

	if (!*node || !node)
	{
		dprintf(2, "L%u: can't pchar, stack empty\n", line_count);
		free_all();
		exit(EXIT_FAILURE);
	}
	num = (*node)->n;
	if ((num < 33) || (num > 127))
	{
		dprintf(2, "L%u: can't pchar, value out of range\n", line_count);
		free_all();
		exit(EXIT_FAILURE);
	}
	putchar(num);
	putchar('\n');
}

/**
 * m_pint - pint is print stack backwards
 * @node: pointer to head
 * @line_count: current line number
 * Return: void function
 */
void m_pint(stack_t **node, unsigned int line_count)
{
	if (!*node || !node)
	{
		dprintf(2, "L%u: can't pint, stack empty\n", line_count);
		free_all();
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*node)->n);
}

/**
 * m_pop - delete element top of stack
 * @head: doble pointer to head of d linked list
 * @line_count: current line of monty file
 * Return: returns void
 */
void m_pop(stack_t **head, unsigned int line_count)
{
	stack_t *temp;

	if (!(*head) || !head)
	{
		dprintf(2, "L%u: can't pop an empty stack\n", line_count);
		free_all();
		exit(EXIT_FAILURE);
	}
	temp = *head;
	if (temp->next)
	{
		temp->next->prev = NULL;
		*head = temp->next;
	}
	else
		*head = NULL;
	free(temp);
}

/**
 * print - print double linked list
 * @h: pointer to hed
 * Return: number of nodes
 */
size_t print(stack_t *h)
{
	size_t i = 0;

	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
		i++;
	}
	return (i);
}

/**
 * print_rev - print double linked list
 * @h: pointer to hed
 * Return: number of nodes
 */
size_t print_rev(stack_t *h)
{
	size_t i = 0;

	while (h->next)
	{
		h = h->next;
	}
	while (h)
	{
		h = h->prev;
		i++;
	}
	return (i);
}

/**
 * m_pstr - prints stack as ascii code
 * @node: pointer to head
 * @line_count: current line number
 * Return: void function
 */
void m_pstr(stack_t **node, __attribute__((unused)) unsigned int line_count)
{
	stack_t *temp = *node;

	while (temp && (temp->n != 0) && ((temp->n) > 32) && ((temp->n) < 128))
	{
		printf("%c", temp->n);
		temp = temp->next;
	}
	putchar('\n');
}

/**
 * check_digit - check if string is a number
 * @param: param to push
 * @line_count: current line number
 * Return: number
 */
int check_digit(char *param, unsigned int line_count)
{
	int num;

	num = atoi(param);
	if (num == 0 && strcmp(param, "0") != 0)
	{
		dprintf(2, "L%u: usage: push integer\n", line_count);
		free_all();
		exit(EXIT_FAILURE);
	}
	return (num);
}

/**
 * m_push - it pushes an element to the stack.
 * @node: pointer to head
 * @line_count: current line number
 * Return: void function
 */
void m_push(stack_t **node, unsigned int line_count)
{
	int num;
	char *param;

	param = strtok(NULL, SEPARATORS);

	if (!param)
	{
		dprintf(2, "L%u: usage: push integer\n", line_count);
		free_all();
		exit(EXIT_FAILURE);
	}
	num = check_digit(param, line_count);
	if (!add_node(node, num))
	{
		dprintf(2, "Error: malloc failed\n");
		free_all();
		exit(EXIT_FAILURE);
	}
}

/**
 * m_rotl - rotates the stack to the top
 * @head: double pointer to the begining of the list
 * @line_count: script line number
 */
void m_rotl(stack_t **head, unsigned int line_count)
{
	stack_t *temp, *top;
	(void) line_count;

	if (!head || !(*head) || !(*head)->next)
		return;
	temp = *head;
	top = temp->next;
	top->prev = NULL;

	while (temp->next != NULL)
		temp = temp->next;
	temp->next = *head;

	(*head)->next = NULL;
	(*head)->prev = temp;

	*head = top;
}

/**
 * m_rotr - rotates the stack to the bottom
 * @head: double pointer to the begining of the list
 * @line_count: script line number
 */

void m_rotr(stack_t **head, unsigned int line_count)
{
	stack_t *temp;
	(void) line_count;

	if (!head || !(*head) || !(*head)->next)
		return;

	temp = *head;

	while (temp->next != NULL)
		temp = temp->next;

	temp->next = *head;
	temp->prev->next = NULL;
	temp->prev = NULL;

	(*head)->prev = temp;
	(*head) = temp;
}

/**
 * m_sub - subs the top and the second element of the stack
 * @head: pointer to head
 * @line_count: current line number
 * Return: void function
 */
void m_sub(stack_t **head, unsigned int line_count)
{
	stack_t *temp;
	int valor;

	if (!head || !(*head) || !(*head)->next)
	{
		dprintf(2, "L%u: can't sub, stack too short\n", line_count);
		free_all();
		exit(EXIT_FAILURE);
	}
	temp = *head;

	valor = temp->next->n - temp->n;
	m_pop(head, line_count);
	m_pop(head, line_count);
	add_node(head, valor);
}

/**
 * m_swap - swaps the top two elements of the stack
 * @head: double pointer to the head ot the stack
 * @count_lines: the number of the line in file
 * Return: void
 */
void m_swap(stack_t **head, unsigned int count_lines)
{
	stack_t *temp;

	if (!head || !(*head) || !(*head)->next)
	{
		dprintf(2, "L%u: can't swap, stack too short\n", count_lines);
		exit(EXIT_FAILURE);
	}

	temp = (*head)->next;
	(*head)->prev = temp;
	(*head)->next = temp->next;
	temp->prev = NULL;

	if (temp->next)
		temp->next->prev = *head;
	temp->next = *head;
	*head = temp;
}

