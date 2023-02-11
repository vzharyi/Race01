#include "header.h"

int main(int argc, char *argv[]) 
{
    if(argc != 5)
    {
        mx_printerr(MX_NO_ARGUMENTS);
        exit(-1);
   }
	
	char *operand1 = argv[1];
	char *operation = argv[2];
	char *operand2 = argv[3];
	char *result = argv[4];

	assessment(&operand1, &operation, &operand2, &result);
    	mx_operation(operand1, operation, operand2, result);
	
    return 0;
}
