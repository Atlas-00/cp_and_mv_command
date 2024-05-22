#include "../includes/cp.h"
#include <stdio.h>
#include <string.h>

int main(int argc, char *argv[])
{
    if (argc < 3) 
    {
        printf("Usage 1 : cp file1 file2 (copy file) \n");
        printf("Usage 2 : cp -R dir1 dir2 (copy directory) \n");
        return 0;
    }

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