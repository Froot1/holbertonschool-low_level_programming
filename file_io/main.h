#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
ssize_t read_textfile(const char *filename, size_t letters);
int create_file(const char *filename, char *text_content);
int append_text_to_file(const char *filename, char *text_content);
int _putchar(char c);

/* Function prototypes */
void check_args(int argc);
void open_files(char **argv, int *fd_from, int *fd_to);
void copy_content(int fd_from, int fd_to, char **argv);
void close_files(int fd_from, int fd_to);
int main(int argc, char **argv);
#endif
