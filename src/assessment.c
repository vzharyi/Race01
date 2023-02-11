#include "header.h"

bool scan_num(char *value)
 {
    if(mx_strlen(value) == 0)
    {
	    return false;
    }
    for(int i = 0; value[i]; i++) 
    {
	    if((!mx_isdigit(value[i]) && value[i] != '?') && !(value[i] == '-' && i == 0))
	    {
		    return false;
	    }
    }
    return true;
}

bool scan_op(char *value) 
{
    if(mx_strlen(value) == 0)
    {
	    return false;
    }
    int counter = 0;
    for(int i = 0; value[i]; i++) 
    {
	    if(counter > 1)
	    {
		    return false;
	    }
	    if(value[i] == '?')
	    {
		    counter++;
	    }
    }
    char *quant = mx_strtrim(value);
    if(mx_strcmp(quant, "?") != 0 && mx_strcmp(quant,"+") != 0 && mx_strcmp(quant,"-") != 0 && mx_strcmp(quant,"*") != 0 && mx_strcmp(quant,"/") != 0)
    {
	    return false;
    }
    free(quant);
    return true;
}

bool test(char *value, int type)
 {
    int valid = 0;
    switch(type)
     {
	    case OPERAND:
		    valid = scan_num(value);
		    break;
	    case OPERATOR:
		    valid = scan_op(value);
		    break;
	    case RESULT:
		    valid = scan_num(value);
	    default:
		    break;
    }
    return valid;
}

void assessment(char **operand1, char **operation, char **operand2, char **result)
 {
	*operand1 = mx_strtrim(*operand1);
	*operation = mx_strtrim(*operation);
	*operand2 = mx_strtrim(*operand2);
	*result = mx_strtrim(*result);

    if(!test(*operation, OPERATOR)) 
    {
	    errors(INVALID_OPERATION, *operation);
	    exit(-1);
    }

// Operand1
    if(!test(*operand1, OPERAND)) 
    {
	    errors(INVALID_OPERAND, *operand1);
	    exit(-1);
    }
	
// Operand2
    if(!test(*operand2, OPERAND)) 
    {
	    errors(INVALID_OPERAND, *operand2);
	    exit(-1);
    }
// Result
    if(!test(*result, RESULT))
     {
	    errors(INVALID_RESULT, *result);
	    exit(-1);
    }
}

