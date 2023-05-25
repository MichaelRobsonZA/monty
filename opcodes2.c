#include "monty.h"

/**
 * swap - swaps the top two elements of the stack
 * @stack: pointer to stack
 * @line_number: line number where opcode appears
 **/
void swap(stack_t **stack, unsigned int line_number)
{
    int temp;

    if (*stack == NULL || (*stack)->next == NULL)
    {
        fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    temp = (*stack)->n;
    (*stack)->n = (*stack)->next->n;
    (*stack)->next->n = temp;
}

/**
 * add - adds the top two elements of the stack
 * @stack: pointer to stack
 * @line_number: line number where opcode appears
 **/
void add(stack_t **stack, unsigned int line_number)
{
    if (*stack == NULL || (*stack)->next == NULL)
    {
        fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    (*stack)->next->n += (*stack)->n;
    pop(stack, line_number);
}

/**
 * nop - does nothing
 * @stack: pointer to stack
 * @line_number: line number where opcode appears
 **/
void nop(stack_t **stack, unsigned int line_number)
{
    (void)stack;
    (void)line_number;
}

/**
 * sub - subtracts the top element of the stack from the second top element
 * @stack: double pointer to the stack
 * @line_number: line number of the opcode
 */
void sub(stack_t **stack, unsigned int line_number)
{
    if (*stack == NULL || (*stack)->next == NULL)
    {
        fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    (*stack)->next->n -= (*stack)->n;
    pop(stack, line_number);
}


