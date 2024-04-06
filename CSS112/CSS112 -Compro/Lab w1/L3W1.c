#include <stdio.h>

int main() {
    float num1 = 2.50, num2 = 1.30, swap = num1;
    printf("Before swapping: first number = %.2f and second number = %.2f\n",num1,num2);
     num1 = num2; 
	 num2 = swap;
    printf("After swapping: first number = %.2f and second number = %.2f",num1,num2);
    return 0;
}