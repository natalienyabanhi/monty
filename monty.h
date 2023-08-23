#ifndef MONTY_H
#define MONTY_H

#define MODE_STACK 0
#define MODE_QUEUE 1

#define __USE_MISC

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Forward declarations */
struct stack_s;
typedef void (*instruction_func)(struct stack_s **stack, unsigned int line_number);

/* Function prototypes */
void push(struct stack_s **stack, unsigned int line_number);
void pall(struct stack_s **stack, unsigned int line_number);
void pop(struct stack_s **stack, unsigned int line_number);
void swap(struct stack_s **stack, unsigned int line_number);
void add(struct stack_s **stack, unsigned int line_number);
void nop(struct stack_s **stack, unsigned int line_number);
void sub(struct stack_s **stack, unsigned int line_number);
void div_op(struct stack_s **stack, unsigned int line_number);
void mul(struct stack_s **stack, unsigned int line_number);
void mod(struct stack_s **stack, unsigned int line_number);
void pchar(struct stack_s **stack, unsigned int line_number);
void pstr(struct stack_s **stack, unsigned int line_number);
void rotl(struct stack_s **stack, unsigned int line_number);
void rotr(struct stack_s **stack, unsigned int line_number);
void stack(struct stack_s **stack, unsigned int line_number);
void queue(struct stack_s **stack, unsigned int line_number);


/* Stack structure definition */
typedef struct stack_s
{
    int n;
    struct stack_s *prev;
    struct stack_s *next;
} stack_t;

/* Instruction structure definition */
typedef struct instruction_s
{
    char *opcode;
    instruction_func f;
} instruction_t;

/* Global mode variable */
extern int g_mode;
#endif /* MONTY_H */

