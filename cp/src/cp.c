#include "../includes/cp.h"
#include <dirent.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>

void copy_file(char *source, char *destination);
void copy_repertory(char *source, char *destination);

void at_cp(char *source, char *destination, char opt)
{
    switch (opt)
    {
        case 'R':
            copy_repertory(source, destination);
            break;

        default:
            copy_file(source, destination);
            break;
    }
}

void copy_file(char *source, char *destination)
{
    FILE *src = fopen(source, "rb");
    if (!src)
    {
        printf("Erreur lors de l'ouverture du fichier source \n");
        return;
    }

    FILE *dst = fopen(destination, "wb");
    if (!dst)
    {
        printf("Erreur lors de l'ouverture du fichier destination \n");
        fclose(src);
        return;
    }

    unsigned char b;

    while (fread(&b, sizeof(b), 1, src) > 0)
    {
        fwrite(&b, sizeof(b), 1, dst);
    }

    fclose(src);
    fclose(dst);
}

void copy_repertory(char *source, char *destination)
{
    DIR *d = opendir(source);
    struct dirent *dir;

    if (!d)
    {
        perror("Erreur lors de l'ouverture du répertoire source");
        return;
    }

    if (mkdir(destination, 0777) == -1)
    {
        perror("Impossible de créer le dossier de destination !");
        closedir(d);
        return;
    }

    while ((dir = readdir(d)) != NULL)
    {
        if (strcmp(dir->d_name, ".") == 0 || strcmp(dir->d_name, "..") == 0)
            continue;

        char src_path[1024], dst_path[1024];

        snprintf(src_path, sizeof(src_path), "%s/%s", source, dir->d_name);
        snprintf(dst_path, sizeof(dst_path), "%s/%s", destination, dir->d_name);

        struct stat info;

        if (stat(src_path, &info) == 0)
        {
            if (S_ISREG(info.st_mode))
                copy_file(src_path, dst_path);

            else if (S_ISDIR(info.st_mode))
                copy_repertory(src_path, dst_path);

            else
                printf("%s n'est ni un fichier ni un répertoire.\n", src_path);
        }
        else
            printf("Une erreur s'est produite lors de la vérification de %s\n", src_path);
    }

    closedir(d);
}
