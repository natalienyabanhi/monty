#include "monty.h"

/**
 * push - Pushes an element onto the stack.
 * @stack: Double pointer to the top of the stack
 * @line_number: Line number of the instruction
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new_node;
	int value;
	char *arg = strtok(NULL, " \t\n");

	if (arg == NULL)
	{
	fprintf(stderr, "L%d: usage: push integer\n", line_number);
	exit(EXIT_FAILURE);
	}

	value = atoi(arg);
	if (value == 0 && arg[0] != '0' && arg[0] != '-')
	{
	fprintf(stderr, "L%d: usage: push integer\n", line_number);
	exit(EXIT_FAILURE);
	}

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
	fprintf(stderr, "Error: malloc failed\n");
	exit(EXIT_FAILURE);
	}

	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack != NULL)
	(*stack)->prev = new_node;

	*stack = new_node;
}
/**
 * pall - Prints all elements in the stack.
 * @stack: Double pointer to the top of the stack
 * @line_number: Line number of the instruction (unused)
 */
void pall(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *current = *stack;

	while (current != NULL)
	{
	printf("%d\n", current->n);
	current = current->next;
	}
}

