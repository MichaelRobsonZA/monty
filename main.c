#include "monty.h"

int main(int argc, char *argv[])
{
    FILE *file;
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    unsigned int line_number = 0;
    stack_t *stack = NULL;
    instruction_t opcodes[] = {
        {"push", push},
        {"pall", pall},
        {NULL, NULL}
    };

    if (argc != 2)
    {
        fprintf(stderr, "USAGE: monty file\n");
        exit(EXIT_FAILURE);
    }

    file = fopen(argv[1], "r");

    if (file == NULL)
    {
        fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    while ((read = getline(&line, &len, file)) != -1)
    {
        line_number++;
         char *instruction = strtok(line, " \n");
        if (instruction == NULL || instruction[0] == '#')
            continue;

        instruction_t *opcode = opcodes;

        while (opcode->opcode != NULL)
        {
            if (strcmp(opcode->opcode, instruction) == 0)
            {
                opcode->f(&stack,   opcode++;
    }

   if (opcode->opcode == NULL)
   {
    fprintf(stderr, "L%u: unknown instruction %s\n", line_number, instruction);
    exit(EXIT_FAILURE);
   }
    }

    fclose(file);

    if (line)
        free(line);

    exit(EXIT_SUCCESS);
}

