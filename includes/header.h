#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>

void write_loop(int char_val, FILE* fd);
void convert_code(char *str, FILE* fd);
