#include "header.h"
char *mx_strndup(const char *s1, int n) 
{
char *result = NULL;
int length = mx_strlen(s1);
if (n < length)
{
  length = n;
}
result = mx_strnew(length);
mx_strncpy(result, s1, length);
return result;
}
