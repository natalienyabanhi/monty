#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * add_dnodeint_end - Add a node at the end of the doubly linked list
 * @head: Pointer to the head of the list
 * @n: Value to be stored in the new node
 * Return: Address of the newly added node, or NULL on failure
 */
stack_t *add_dnodeint_end(stack_t **head, int n)
{
    stack_t *new_node = malloc(sizeof(stack_t));
    if (!new_node)
        return NULL;

    new_node->n = n;
    new_node->prev = NULL;
    new_node->next = NULL;

    if (*head == NULL)
    {
        *head = new_node;
    }
    else
    {
        stack_t *current = *head;
        while (current->next != NULL)
            current = current->next;
        current->next = new_node;
        new_node->prev = current;
    }

    return new_node;
}

/**
 * free_dlistint - Frees a doubly linked list
 * @head: Pointer to the head of the list
 */
void free_dlistint(stack_t *head)
{
    while (head != NULL)
    {
        stack_t *temp = head;
        head = head->next;
        free(temp);
    }
}

/**
 * print_dlistint - Prints the contents of a doubly linked list
 * @h: Pointer to the head of the list
 */
void print_dlistint(const stack_t *h)
{
    while (h != NULL)
    {
        printf("%d\n", h->n);
        h = h->next;
    }
}

