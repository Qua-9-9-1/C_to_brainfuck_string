#include "../includes/header.h"

void write_loop(int char_val, FILE* fd)
{
    for (int j = char_val / 10; j > 0; j--)
        fprintf(fd, "+");
    if (char_val / 10)
        fprintf(fd, "[>++++++++++<-]>");
    else
        fprintf(fd, ">");
    for (int j = char_val % 10; j > 0; j--)
        fprintf(fd, "+");
}

void convert_code(char *str, FILE* fd)
{
    int char_val = 0;

    write_loop(str[0], fd);
    fprintf(fd, ".");
    for (int i = 1; str[i]; i++) {
        char_val = str[i];
        if (str[i - 1] > char_val) {
            fprintf(fd, "[-]<");
            write_loop(char_val, fd);
        }
        if (str[i - 1] < char_val) {
            fprintf(fd, "<");
            write_loop(char_val - (int)str[i - 1], fd);
        }
        fprintf(fd, ".");
    }
    fprintf(fd, "[-]");
}
