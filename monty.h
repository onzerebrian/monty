#ifndef MONTY_H
#define MONTY_H
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
/**
 * struct global_s - global variables
 * @token: operand
 * @num: value to store in stack
 * @code: instruction
 * @file: pointer to monty file descriptor
 * @content: line content
 * @flag: change stack <-> queue
 * Description: carries values through the program
 */
typedef struct global_s
{
	char *code;
	char *token;
	FILE *file;
	char *content;
	int flag;
	int num;
}  global_t;
extern global_t global;
int check_int(char *num);
void s_v(stack_t **stack, unsigned int line_number);
void f_st(stack_t **stack);
char nl(char *line);
void __push(stack_t **stack, unsigned int line_number);
void __pall(stack_t **stack, unsigned int line_number);
void __pint(stack_t **stack, unsigned int line_number);
void __pop(stack_t **stack, unsigned int line_number);
void __swap(stack_t **stack, unsigned int line_number);
void err(stack_t **stack, unsigned int line_number);
void __add(stack_t **stack, unsigned int line_number);
void (*funct(char *token))(stack_t **stack, unsigned int line_number);
void __nop(stack_t **stack, unsigned int line_number);

#endif
