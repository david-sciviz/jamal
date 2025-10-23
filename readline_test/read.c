#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <readline/readline.h>
#include <readline/history.h>

int main() {
    char *line = readline("thing> ");

    while (strcmp(line, "exit") != 0) {
       printf(" - %s - \n", line);
       free(line);
       line = readline("thing> ");
    }

    free(line);
    return 0;
}
