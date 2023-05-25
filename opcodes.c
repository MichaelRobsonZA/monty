#include "monty.h"

/**
 * push - pushes an element to the stack
 * @stack: pointer to stack
 * @line_number: line number where opcode appears
 **/
void push(stack_t **stack, unsigned int line_number)
{
    char *arg;
    int n;
    stack_t *new_node;

    arg = strtok(NULL, " \t\n");
    if (!arg || !isdigit(*arg))
    {
        fprintf(stderr, "L%d: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    n = atoi(arg);
    new_node = malloc(sizeof(stack_t));
    if (!new_node)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    new_node->n = n;
    new_node->prev = NULL;
    new_node->next = *stack;

    if (*stack != NULL)
        (*stack)->prev = new_node;

    *stack = new_node;
}

/**
 * pall - prints all the values on the stack
 * @stack: pointer to stack
 * @line_number: line number where opcode appears
 **/
void pall(stack_t **stack, unsigned int line_number)
{
    stack_t *temp;

    (void)line_number;

    for (temp = *stack; temp != NULL; temp = temp->next)
        printf("%d\n", temp->n);
}

#include "monty.h"

/**
 * pint - prints the value at the top of the stack
 * @stack: pointer to stack
 * @line_number: line number where opcode appears
 **/
void pint(stack_t **stack, unsigned int line_number)
{
    if (*stack == NULL)
    {
        fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
        exit(EXIT_FAILURE);
    }

    printf("%d\n", (*stack)->n);
}

/**
 * pop - removes the top element of the stack
 * @stack: pointer to stack
 * @line_number: line number where opcode appears
 **/
void pop(stack_t **stack, unsigned int line_number)
{
    stack_t *temp;

    if (*stack == NULL)
    {
        fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
        exit(EXIT_FAILURE);
    }

    temp = *stack;
    *stack = (*stack)->next;

    if (*stack != NULL)
        (*stack)->prev = NULL;

    free(temp);
}

