#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int perfect_prod_1(int num) {
    int to_return = 1;
    int test;

    for (int i = 1; i < num; i++) {
        test = 0;
        for (int j = 1; j < i; j++) {
            if (i % j == 0) {
                test += j;
            }
        }
        
        if (test == i) {
            printf("Perfect number: %d\n", test);
            to_return *= test;
        }
    }

    return to_return;
}

void perfect_prod_2(int num, int *prod) {
    *prod = 1;
    int test;

    for (int i = 1; i < num; i++) {
        test = 0;
        for (int j = 1; j < i; j++) {
            if (i % j == 0) {
                test += j;
            }
        }

        if (test == i) {
            printf("Perfect number: %d\n", test);
            *prod *= test;
        }
    }
}

int count_even_digits_1(int number) {
    int to_return = 0;
    do {
        int test = number%10;
        if (test % 2 == 0) {
            to_return += 1;
        }
        number /= 10;
    } while (number > 0);

    return to_return;
}

void count_even_digits_2(int number, int *count) {
    *count = 0;
    while (number > 10) {
        int test = number%10;
        if (test % 2 == 0) {
            *count += 1;
        }
        number /= 10;
    }
}

int platform_1_D(int ar[], int size) {
    int to_return = 1;
    int current_chain = 1;

    for (int i = 1; i < size; i++) {
        if (ar[i] == ar[i-1]) {
            current_chain += 1;
            if (current_chain > to_return) {
                to_return = current_chain;
            }
        } else {
            current_chain = 1;
        }
    }
    return to_return;
}


int main() {
    int arr[10] = {1,2,3,4,4,4,7,8,8,0};
    printf("%d", platform_1_D(arr,10));
}