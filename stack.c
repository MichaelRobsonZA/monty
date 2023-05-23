#include "monty.h"

void push(stack_t **stack, unsigned int line_number)
{
    char *arg;
    int n;

    arg = strtok(NULL, " \n");

    if (arg == NULL || !isdigit(*arg))
    {
        fprintf(stderr, "L%u: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    n = atoi(arg);

    /* Create new node and add to top of stack */
}

void pall(stack_t **stack, unsigned int line_number)
{
    stack_t *current = *stack;

    while (current != NULL)
    {
        printf("%d\n", current->n);
        current = current->next;
    }
}

