#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * div_op - Divides the second top element of the stack by the top element.
 * @stack: Pointer to the stack.
 * @line_number: Line number in the Monty bytecode file.
 */
void div_op(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
	fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
	exit(EXIT_FAILURE);
	}

	if ((*stack)->n == 0)
	{
	fprintf(stderr, "L%d: division by zero\n", line_number);
	exit(EXIT_FAILURE);
	}

	temp = *stack;
	*stack = (*stack)->next;
	(*stack)->n /= temp->n;
	(*stack)->prev = NULL;
	free(temp);
}
