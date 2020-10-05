#include <stdio.h>

int main()
{
    double A =  373737.0;
    double B, C, D;

    B = A*A*A + 0.373737/A;
    C = A*A*A - 0.373737/A;
    D = B-C;
    printf("B %f and C %f, difference is %d", B,C,D);  
}