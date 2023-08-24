#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * mul - Multiplies the second top element of the stack with the top element.
 * @stack: Pointer to the stack.
 * @line_number: Line number in the Monty bytecode file.
 */
void mul(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
	fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
	exit(EXIT_FAILURE);
	}

	temp = *stack;
	*stack = (*stack)->next;
	(*stack)->n *= temp->n;
	(*stack)->prev = NULL;
	free(temp);
}

