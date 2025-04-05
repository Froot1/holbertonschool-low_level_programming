#ifndef MAIN_H
#define MAIN_H

/* Includes */

#include <stdlib.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

/* Structures */


/* Prototypes */

ssize_t read_textfile(const char *filename, size_t letters);
int create_file(const char *filename, char *text_content);
int append_text_to_file(const char *filename, char *text_content);
int copy_f(int from, const char *f_from, int to, const char *f_to);

#endif /* _HOLBERTON_H_ */
