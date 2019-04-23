/**
 * Author: Hair Albeiro Parra Barrera
 * Simple calculator program. Can be easily extended to 
 * more operations. 
 * Example usage by command line: 
 * $ MiniCalculator.c 5 + 4
 * */

#include <stdio.h> 
#include <stdlib.h> 
#include <math.h> 
#include <string.h>

double arithmetic(double a, char operator, double b) { 

    double result; 
    printf("a = %f, b = %f", a, b); 
    printf("Operator: %c\n", operator); 

    switch (operator){

        case '+': 
            printf("Addition\n"); 
            result = a+b; 
            break; 
        case '-': 
            printf("Substraction\n"); 
            result = a-b; 
            break; 
        case '*':
            printf("Multiplication\n");
            result = a*b; 
            break; 
        case '/':
            printf("Division\n");
            if( b != 0) { 
                result = a/b; 
            } 
            else { 
                printf("Error: Divisor cannot be 0"); 
                result = 0; 
            }
            break; 
        case '%': 
            printf("Modulus\n"); 
            result = ((int) a ) % ((int )b); 
            break;  
        default: 
            result = 0; 
            printf("Nothing happened\n"); 

    }
    return result;            
}

int main(int argc, char *argv[]){  

    printf("Welcome to the calculator program\n");
    printf("Please input your operation in the following format: \n"); 
    printf(" a operator b , where operators={+,-,*,/,%}\n");  
    // place the command line arguments into variables 
    const char* arg1 = argv[1]; 
    const char* arg2 = argv[2]; 
    const char* arg3 = argv[3]; 
    printf("arg1 = %s, arg2 = %s, arg3 = %s\n", arg1,arg2,arg3); 
    char operator; 
    sscanf(arg2,"%c", &operator); // convert the input argument to char
    printf("%c", operator); 
    double result = arithmetic(atoi(arg1),operator,atoi(arg3)); 
    printf("Result = %f\n", result); 
}
