#include "header.h"
char *mx_strtrim(const char *str) 
{
int lenth = 0;
char *result = NULL;
while (mx_isspace(*str))
{
    str++;
}
lenth = mx_strlen(str);
while (mx_isspace(str[lenth - 1]))
{
    lenth--;
}
result = mx_strndup(str, lenth);
return (char *)result;
}
