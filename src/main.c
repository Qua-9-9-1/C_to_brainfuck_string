#include "../includes/header.h"

void string_method(char *str)
{
    char *file_name = NULL;
    size_t size = 0;
    FILE* fd;

    if (!str) {
        printf("ERROR: you have nothing to write !\n");
        exit(1);
    }
    str[strlen(str)] = '\0';
    printf("Enter the file name (don't forget .bf):\n");
    if (getline(&file_name, &size, stdin) == -1) exit(1);
    fd = fopen(file_name, "w");
    convert_code(str, fd);
    fclose(fd);
    free(file_name);
    free(str);
}

void file_method(char *filepath)
{
    FILE* fd = fopen(filepath, "r");
    size_t size = 0;
    char *buffer = NULL;
    struct stat st;

    stat(filepath, &st);
    size = st.st_size;
    if (!fd) {
        printf("Invalid file.\n");
        exit(1);
    }
    buffer = malloc(sizeof(char) * size + 1);
    fread(buffer, 1, size, fd);
    fclose(fd);
    string_method(buffer);
}

void help(void)
{
    printf("USAGE\n");
    printf("    ./brainfuck_converter [file]\n\n");
    printf("DESCRIPTION\n");
    printf("if you don't give any file, you have to enter manually\n");
    printf("the string you want to convert.\n\n");
    printf("The program automatically save a file\nwith the name you give to it.\n");
    exit(0);
}

int main(int ac, char **av)
{
    char *str = NULL;
    char *bf_code = NULL;
    size_t size = 0;

    if (ac == 2 && av[1][0] == '-' && av[1][1] == 'h')
        help();
    if (ac > 2) {
        printf("ERROR: no more than one file !\n");
        return 1;
    }
    if (ac == 2)
        file_method(av[1]);
    else {
        printf("Enter the string that you want to convert :\n");
        if (getline(&str, &size, stdin) == -1) exit(1);
        string_method(str);
    }
    printf("Your file has been created sucessfully.");
    return 0;
}
