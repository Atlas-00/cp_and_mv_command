#include "../includes/cp.h"
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    char opt;

    // Ajouter les arguments cp et mv à l'éxecution
    if (argv[1] != NULL && strcmp(argv[1], "-R") == 0)
    {
        opt = argv[1][1];
        at_cp(argv[2], argv[3], opt);
        return 0;
    }

    at_cp(argv[1], argv[2], opt);

    return 0;
}
