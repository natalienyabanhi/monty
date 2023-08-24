#include "monty.h"

/**
 * rotl - Rotate the stack to the top
 * @stack: Double pointer to the top of the stack
 * @line_number: Line number of the instruction
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *last;

	(void)line_number;

	if (*stack == NULL || (*stack)->next == NULL)
	return;

	last = *stack;

	while (last->next != NULL)
	last = last->next;

	last->next = *stack;
	(*stack)->prev = last;
	*stack = (*stack)->next;
	(*stack)->prev->next = NULL;
	(*stack)->prev = NULL;
}

