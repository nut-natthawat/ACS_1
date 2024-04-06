#include <stdio.h>
#include <math.h>
int main() {
    double num[] = {2.25,4.16,6.17,7.18,6.19};
    double product = 1;
    double range = sizeof(num)/sizeof(num[0]);
    for (int i = 0; i < range; i++) 
    product = product*num[i];
    printf("Geometric Mean of 2.25 4.16 6.17 7.18 and 6.19 is %.4f", pow(product, 1.0 /range));
    return 0;
} 
