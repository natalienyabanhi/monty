#include "monty.h"

/**
 * rotr - Rotate the stack to the bottom
 * @stack: Double pointer to the top of the stack
 * @line_number: Line number of the instruction
 */
void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	(void)line_number;

	if (*stack == NULL || (*stack)->next == NULL)
	return;

	current = *stack;

	while (current->next != NULL)
	current = current->next;

	current->next = *stack;
	(*stack)->prev = current;
	*stack = current;
	current->prev->next = NULL;
	current->prev = NULL;
}

