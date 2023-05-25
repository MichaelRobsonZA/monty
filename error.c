#include "monty.h"

/**
 * get_instruction - retrieves instruction function associated with opcode
 * @opcode: the opcode to search for
 *
 * Return: pointer to instruction function, or NULL if not found
 **/
instruction_t *get_instruction(char *opcode)
{
    static instruction_t instructions[] = {
        {"push", push},
        {"pall", pall},
	{"pint", pint},
	 {"pop", pop},
        /* add more opcodes here */
        {NULL, NULL}
    };

    int i;

    for (i = 0; instructions[i].opcode != NULL; i++)
    {
        if (strcmp(opcode, instructions[i].opcode) == 0)
            return (&instructions[i]);
    }

    return (NULL);
}

/**
 * free_stack - frees a stack
 * @stack: pointer to the top of the stack
 */
void free_stack(stack_t *stack)
{
    stack_t *temp;

    while (stack != NULL)
    {
        temp = stack;
        stack = stack->next;
        free(temp);
    }
}

