#include "header.h"

void errors(int error, char *value) {
    switch(error) {
	    case INVALID_OPERAND:
		    mx_printerr(MX_INVALID_OPERAND);
		    break;
        
	    case INVALID_OPERATION:
		    mx_printerr(MX_INVALID_OPERATION);
		    break;
        
	    case INVALID_RESULT:
		    mx_printerr(MX_INVALID_RESULT);
		    break;
    }
    mx_printerr(value);
    mx_printchar('\n');
}
