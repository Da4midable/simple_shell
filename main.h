#ifndef MAIN_H
#define MAIN_H


#include <sys/wait.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stddef.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>


#define BUFF_SIZE 1024
#define INITIAL_BUFSIZE 128
#define CHUNK_SIZE 128
#define UNUSED(x) (void)(x)

void sigint_handler(int sig_num);


void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);
void ffree(char **pp);
int process_cmd();
char *_memset(char *s, char b, unsigned int n);
char *new_get_line(void);
char *_memcpy(char *dest, char *src, unsigned int n);
char *_getenv(const char *name);
char *locate(const char *name);
char *join_paths(const char sep, const char *path1, const char *path2);
int file_exists(const char *filepath);
char *_strdup(const char *str);
int _strcmp(const char *str1, const char *str2);
int _atoi(const char *str);
char *_strtok(char *str, const char *delim);
char *_strstr(char *haystack, char *needle);
size_t _strlen(const char *str);
int _atoi(const char *str);
char *_findenv(const char *name);
int _isdigit(char *str);
int _append(const char *filename, char *text_content);
int _putchar(char c);
ssize_t get_line(char **lineptr, size_t *n, FILE *stream);

extern char **environ;

#endif
