#include "monty.h"
#include <string.h>
#include <stdio.h>

instruction_t instructions[] = {
    {"push", push},
    {"pop", pop},
    {"swap", swap},
    {"add", add},
    {"nop", nop},
    {"sub", sub},
    {"pall", pall},
    {"mul", mul},
    {"mod", mod},
    {"div_op", div_op},
    {"pchar", pchar},
    {NULL, NULL}
};

/**
 * main - Entry point of the Monty interpreter.
 * @argc: Number of arguments.
 * @argv: Array of argument strings.
 * Return: 0 on success, 1 on failure.
 */
int main(int argc, char *argv[])
{
    FILE *file;
    stack_t *stack = NULL;
    char *line = NULL;
    size_t len = 0;
    unsigned int line_number = 0;
    char *opcode;
    int found;
    instruction_t *instr;

    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        return 1;
    }

    file = fopen(argv[1], "r");
    if (!file)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        return 1;
    }

    while (fgets(line, len, file) != NULL)
    {
        line_number++;
        opcode = strtok(line, " \t\n");

        if (opcode == NULL || opcode[0] == '#')
            continue; /* Skip empty lines and comments */

        found = 0;
       
        for (instr = instructions; instr->opcode != NULL; instr++)
        {
            if (strcmp(opcode, instr->opcode) == 0)
            {
                instr->f(&stack, line_number);
                found = 1;
                break;
            }
        }

        if (!found)
        {
            fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
            fclose(file);
            free(line);
            /* Free the stack nodes */
            /* ... */
            return 1;
        }
    }

    fclose(file);
    free(line);
    /* Free the stack nodes */
    /* ... */

    return 0;
}

