#ifndef CALCULATOR
#define CALCULATOR

#include <stdbool.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>


#define MX_NO_ARGUMENTS "usage: ./part_of_the_matrix [operand1] [operation] [operand2] [result]\n"
#define MX_INVALID_OPERAND "Invalid operand: " 
#define MX_INVALID_OPERATION "Invalid operation: "
#define MX_INVALID_RESULT "Invalid result: "

enum e_error
{
	INVALID_OPERAND,
    	INVALID_OPERATION,
   	INVALID_RESULT
};

enum e_type
{
    OPERAND,
    OPERATOR,
	RESULT
};
int mx_strlen(const char *s);
bool mx_isdigit(int c);
bool mx_isspace(char c);
char *mx_itoa(int number);
int mx_atoi(const char *str);
void mx_printint(int num);
void mx_printchar(char c);
void mx_printstr(const char *s);
void mx_printerr(const char *s);
char *mx_strnew(const int size);
char *mx_strndup(const char *s1, int n);
char *mx_strncpy(char *dst, const char *src, int len);
char *mx_strcpy(char *dst, const char *src);
char *mx_strtrim(const char *str);
int mx_strcmp(const char *s1, const char *s2);
void mx_str_reverse(char *s);
int mx_pow(int num, int pow);
void mx_swap_char(char *s1, char *s2);

void errors(int error, char *value);
void assessment(char **operand1, char **operation, char **operand2, char **result);
void mx_operation(char *operand1, char *operation, char *operand2, char *result);
int main(int argc, char *argv[]);

#endif
