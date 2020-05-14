#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[]) {

    if (argc < 2) {
        printf("wgrep: searchterm [file ...]\n");
        exit(1);
    }

    FILE *fp;
    char *line_buf = NULL;
    size_t line_buf_size = 0;
    int line_count = 0;
    ssize_t line_size;

    if (argc == 2) {
         fp = stdin;
    }
    else {
        fp = fopen(argv[2], "r");
        if (fp == NULL) {
            printf("wgrep: cannot open file\n");
            exit(1);
         }
    }
    while(line_size >= 0) {

        line_count++;
        line_size = getline(&line_buf, &line_buf_size, fp);
        if (strstr(line_buf, argv[1]) != NULL) {
            printf("%s", line_buf);
        }
    }
}
