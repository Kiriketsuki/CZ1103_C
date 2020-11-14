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

void print_pattern_3(int height) {
    int to_print;

    for (int i = 1; i < height; i++) {
        to_print = i;
        for (int j = 1; j != i+1; j++) {
            printf("%d", to_print);
            if (to_print == 9) {
                to_print = 0;
            } else {
                to_print++;
            }
        }
        putchar('\n');
    }
}

void insert(int max, int *size, int ar[], int num) {
    int i = 0;
    int *pt = ar;

    printf("%d", num);
    while (ar[i] < num) {
        i++;
    }
    printf("%d", i);
    for (int j = *size+1; j > i; j--) {
        ar[j] = ar[j-1];
    }

    *(pt+i) = num;
    putchar('\n');
}

int main() {
    int test[10] = {1,2,3,4,5};
    int size = 6;
    // insert(10, &size, test, 7);

    for (int i = 0; i < 10; i++) {
        printf("%d", test[i]);
    }
}