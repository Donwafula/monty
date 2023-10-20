#ifndef _MONTY_H_
#define _MONTY_H_

#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <unistd.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;
/**
 * struct instruction_s - opcoode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct mlist_s - doubly linked list representation of a stack (or queue)
 * @size: size of the stack (or queue)
 * @ln: line number
 * @head: points to the first node of the stack (or queue)
 * @tail: points to the last node of the stack (or queue)
 * @fd: file descriptor
 * @buffer: buffer
 * @intarg: integer arg
 * @mode: mode
*/
typedef struct mlist_s
{
	size_t size;
	unsigned int ln;
	stack_t *head;
	stack_t *tail;
	FILE *fd;
	void *buffer;
	int intarg;
	int mode;
} mlist_t;

extern mlist_t gs;

/* matths_func.c */
void monty_mod(stack_t **head, unsigned int line_c);
void monty_mul(stack_t **head, unsigned int line_c);
void monty_add(stack_t **head, unsigned int line_c);
void monty_sub(stack_t **head, unsigned int line_c);
void monty_div(stack_t **head, unsigned int line_c);

/*ROTATE.c*/
void monty_pstr(stack_t **head, unsigned int list_c);
void monty_rotl(stack_t **head, unsigned int line_c);
void monty_rotr(stack_t **head, unsigned int line_c);
void monty_chgmode(stack_t **head, unsigned int line_c);
void monty_pchar(stack_t **head, unsigned int line_c);

/*INT.c*/
void monty_l_init(void);
void monty_dest(void);
int monty_end(const int line_c);
int monty_beg(const int line_c);
int monty_l_remove(stack_t *node);

/*OPCODES.c*/
void monty_swap(stack_t **head, unsigned int line_c);
void monty_push(stack_t **head, unsigned int line_c);
void monty_pint(stack_t **head, unsigned int line_c);
void monty_pop(stack_t **stack, unsigned int line_c);
void monty_pall(stack_t **head, unsigned int line_c);

/*INT.c*/
int monty_int(const char *list_c);
int monty_opcode(char *pork);
void monty_nop(stack_t **head, unsigned int list_c);
void monty_exit(int doc, char *command);

#endif /* _MONTY_H_ */
