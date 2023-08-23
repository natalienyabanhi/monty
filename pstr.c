#include "monty.h"
#include <stdio.h>

/**
 * pstr - Print the string starting at the top of the stack as ASCII characters
 * @stack: Double pointer to the top of the stack
 * @line_number: Line number of the instruction (unused)
 */
void pstr(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *current = *stack;

	while (current != NULL && current->n != 0 && (current->n >= 0 && current->n <= 127))
	{
		putchar(current->n);
		current = current->next;
	}

	putchar('\n');
}

