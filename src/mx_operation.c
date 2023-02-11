#include "header.h"

void mx_operation(char *operand1, char *operation, char *operand2, char *result) 
{
    if (*operation == '?') 
    {
        mx_operation(operand1, "+", operand2, result);
        mx_operation(operand1, "-", operand2, result);
        mx_operation(operand1, "*", operand2, result);
        mx_operation(operand1, "/", operand2, result);
        return;
    }

    int operand1_length = mx_strlen(operand1);
	int operand2_length = mx_strlen(operand2);
	int result_length = mx_strlen(result);
	
    bool operand1_negative = false;
	bool operand2_negative = false;
	bool result_negative = false;

    if (operand1[0] == '-') 
    {
        operand1_negative = true;
        operand1++;
        operand1_length--;
    } 

    if (operand2[0] == '-')
     {
        operand2_negative = true;
        operand2++;
        operand2_length--;
    }

    if (result[0] == '-')
     {
        result_negative = true;
        result++;
        result_length--;
    }

    int operand1_integer = mx_atoi(operand1);
	int operand2_integer = mx_atoi(operand2);
	int result_integer = mx_atoi(result);

    for (long long i = 0; i < mx_pow(10, operand1_length); i++) 
    {
        if (operand1_integer > 0)
            i = operand1_integer;
		
        char *i_queue = mx_itoa(i);
        int i_length = mx_strlen(i_queue);
        bool i_is_correct = true;

        for (int j = 0; j < operand1_length - i_length; j++) 
        {
            if (mx_isdigit(operand1[j]) && operand1[j] != '0')
             {
                i_is_correct = false;
                break;
            }
        }

        for (int j = operand1_length - i_length, k = 0; j < operand1_length; j++, k++) {
            if (operand1[j] != '?' && operand1[j] != i_queue[k]) {
                i_is_correct = false;
                break;
            }
        }

        free(i_queue); i_queue = NULL;
        if (!i_is_correct)
            continue;

        for (long long j = 0; j < mx_pow(10, operand2_length); j++) 
        {  
            if (operand2_integer > 0) 
            {
                j = operand2_integer;
            }
            char *j_queue = mx_itoa(j);
            int j_length = mx_strlen(j_queue);
            bool j_is_correct = true;

            for (int p = 0; p < operand2_length - j_length; p++)
             {
                if (mx_isdigit(operand2[p]) && operand2[p] != '0') {
                    j_is_correct = false;
                    
                    break;
                }
            }

            for (int p = operand2_length - j_length, j_queue_i = 0; p < operand2_length; p++, j_queue_i++) 
            {
                if (operand2[p] != '?' && operand2[p] != j_queue[j_queue_i]) 
                {
                    j_is_correct = false;
                    break;
                }
            }

            free(j_queue); j_queue = NULL;
            if (!j_is_correct)
                continue;
            
            for (long long k = 0; k < mx_pow(10, result_length); k++) 
            {
                if (result_integer > 0) {
                    k = result_integer;
                }
                char *k_queue = mx_itoa(k);
                int k_length = mx_strlen(k_queue);
                bool k_is_correct = true;

                for (int n = 0; n < result_length - k_length; n++) 
                {
                    if (mx_isdigit(result[n]) && result[n] != '0') 
                    {
                        k_is_correct = false;
                        break;
                    }
                }

                for (int n = result_length - k_length, k_queue_i = 0; n < result_length; n++, k_queue_i++) 
                {
                    if (result[n] != '?' && result[n] != k_queue[k_queue_i]) 
                    {
                        k_is_correct = false;
                        break;
                    }
                }

                free(k_queue); k_queue = NULL;
                if (!k_is_correct)
                    continue;

                if (operand1_negative)
                    i *= -1;
                if (operand2_negative)
                    j *= -1;
                if (result_negative)
                    k *= -1;

                if (*operation == '+') 
                {
                    if (i + j == k) {
                        mx_printint(i);
                        mx_printstr(" + ");
                        mx_printint(j);
                        mx_printstr(" = ");
                        mx_printint(k);
                        mx_printchar('\n');
                    }
                }
                else if (*operation == '-') {
                        if (i - j == k) {
                        mx_printint(i);
                        mx_printstr(" - ");
                        mx_printint(j);
                        mx_printstr(" = ");
                        mx_printint(k);
                        mx_printchar('\n');
                    }
                }
                else if (*operation == '*') {
                        if (i * j == k) {
                        mx_printint(i);
                        mx_printstr(" * ");
                        mx_printint(j);
                        mx_printstr(" = ");
                        mx_printint(k);
                        mx_printchar('\n');
                    }
                }
                else if (*operation == '/') 
                {
                    if (j != 0 && i / j == k) 
                    {
                        mx_printint(i);
                        mx_printstr(" / ");
                        mx_printint(j);
                        mx_printstr(" = ");
                        mx_printint(k);
                        mx_printchar('\n');
                    }
                }
                
                if (operand1_negative)
                    i *= -1;
                if (operand2_negative)
                    j *= -1;
                if (result_negative)
                    k *= -1;
                if (result_integer > 0)
                    break;
            }
            if (operand2_integer > 0)
                break;
        }
        if (operand1_integer > 0)
            break;
    }

    if (operand1_negative)
        operand1--;
    if (operand1_negative)
        operand2--;
    if (result_negative)
        result--;
}
