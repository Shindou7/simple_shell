#ifndef SHELL_H_
#define SHELL_H_


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <signal.h>
#include <stdbool.h>
#include <sys/stat.h>
#include <limits.h>

#define MAXCOMMANDLENGTH 1024
extern char **environ;
extern char *env_path;

int EX_builtin_comd(char **tok, char *ligne);

void write_prompt(int get_sigint);

char *remove_newline(char *strings);
int countOccurrences(char *str, char *del);
int countWords(char *str);
/**void hand_varib(char *command);*/
void fork_prompt(char *command);
void _env_print(void);
void Hcommand_line(char *command, char **args);
void free_comd_args(char *args);
void free_Pointers(char **strArray);
void exect_cd(char **tok, char *ligne);
int _comment(const char *line);
void _SignalHandler(int signal);
int _executeCommand(char *command, char **arguments);
void inter_mode(void);

char *_getenv(const char *arg);

char **custom_Tokenize(char *str, char *delimiters, int maxTokens);
void process_input(char *ligne);
int main(int argc, char *argv[]);
char *concatenate_path(char *git, char *pot);
char *find(char *gite);
char *search_in_path(char *gite, char *pote);
void Execute_command(char **command_tokens);
void display_shell_help(void);
void _cd(char **tok);

int _strlen(const char *s);
/**char *_strstr(const char *hay, const char *needle);*/
char *_strncpy(char *dest, char *src, int n);
char *_strcat(char *dest, const char *src);
char *_strncat(char *dest, char *src, int n);

void exect_setenv(char **args);
void exect_unsetenv(char **args);

char *_strcpy(char *dest, char *src);
int _strcmp(char *s1, char *s2);
int _atoi(char *s);
void _puts(char *str);
int _putchar(char c);
char *_strdup(char *str);
void process_input_semicolon(char *input);

void *_realloc(void *ptr, unsigned int old_size, unsigned int new_size);


#endif /* SHELL_H_ */
