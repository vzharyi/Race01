#include "header.h"
char *mx_strnew(const int size)
{
if (size < 0)
   {
     return 0;
   }
 
 int i = 0;
 char *result = (char*)malloc(size+1);
 for (i = 0; i < size +1 ; i++)
 {	
   result[i] = '\0';
 }
 return result;
}

