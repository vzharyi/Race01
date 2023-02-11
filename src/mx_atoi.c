#include "header.h"

  int mx_atoi(const char *str)
 {
 const char* quant;
 while(*str == ' ' || *str == '\t' || *str == '\n' || *str == '\v' || *str == '\f' || *str == '\r') 
	{
	str++;
	}
int num = 0;
int digit = (str[0] == '-') ? -1 : 1;
if (!(str[0] >= '0' && str[0] <= '9') && str[0] != '-' && str[0] != '+')
 {
return 0;
}
if (str[0] == '-' || str[0] == '+') 
{
	str++;
}
quant = str;
while(*quant >= '0' && *quant <= '9') 
{
num *= 10;
num += *quant - '0';
quant++;
}
if (*quant != '\0') 
{
	return 0;
}
return num * digit;
}

