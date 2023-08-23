#include "monty.h"
#include <stdio.h>

/**
 * pchar - Print the char at the top of the stack as ASCII value
 * @stack: Double pointer to the top of the stack
 * @line_number: Line number of the instruction
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
	fprintf(stderr, "L%d: can't pchar, stack empty\n", line_number);
	exit(EXIT_FAILURE);
	}

	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
	fprintf(stderr, "L%d: can't pchar, value out of range\n", line_number);
	exit(EXIT_FAILURE);
	}

	putchar((*stack)->n);
	putchar('\n');
}

