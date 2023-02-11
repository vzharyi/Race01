#include "header.h"
void mx_printchar(char c) 
{
    char *simvol = &c;
    write(1, simvol, 1);
}
