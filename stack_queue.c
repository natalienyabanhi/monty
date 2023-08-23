#include "monty.h"

int g_mode = MODE_STACK;
/**
 * stack - Set the format of the data to a stack (LIFO)
 * @stack: Double pointer to the top of the stack
 * @line_number: Line number of the instruction
 */
void stack(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	g_mode = MODE_STACK;
}

/**
 * queue - Set the format of the data to a queue (FIFO)
 * @stack: Double pointer to the top of the stack
 * @line_number: Line number of the instruction
 */
void queue(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
	g_mode = MODE_QUEUE;
}

