#include "monty.h"

/**
 * main - entry point for the Monty interpreter
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure
 **/
int main(int argc, char *argv[])
{
    FILE *file;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    unsigned int line_number = 1;
    stack_t *stack = NULL;

    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        return (EXIT_FAILURE);
    }

    file = fopen(argv[1], "r");
    if (!file)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        return (EXIT_FAILURE);
    }

    while ((read = getline(&line, &len, file)) != -1)
    {
        char *opcode;
        instruction_t *instruction;

        if (line[0] == '#' || line[0] == '\n')
        {
            line_number++;
            continue;
        }

        opcode = strtok(line, " \t\n");
        if (!opcode)
            continue;

        instruction = get_instruction(opcode);
        if (!instruction)
        {
            fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
            fclose(file);
            free(line);
            free_stack(stack);
            return (EXIT_FAILURE);
        }

        instruction->f(&stack, line_number);

        line_number++;
    }

    fclose(file);
    free(line);
    free_stack(stack);

    return (EXIT_SUCCESS);
}

