#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 10
#define MAX 10

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

int min_of_max_2_d(int ar[][SIZE], int row, int col) {
    int min_max = 2147483647;
    for (int i = 0; i < row; i++) {
        int row_max = 0;
        for (int j = 0; j < col; j++) {
            if (ar[i][j] > row_max) {
                row_max = ar[i][j];
            }
        }
        if (min_max > row_max) {
            min_max = row_max;
        }
    }
    return min_max;
}

void insert(int max, int *size, int ar[], int num) {
    if (*size == max) {
        printf("The array is full\n");
    } else {
        int i = 0;

        while (ar[i] < num) {
            if (i == *size) {
                break;
            }
            i++;
        }

        int temp = ar[i];
        int temp2;
        ar[i] = num;
    
        while (i < *size-1) {
            temp2 = ar[i+1];
            ar[i+1] = temp;
            temp = temp2;
            i++;
        }

        ar[i+1] = temp;
        (*size)++;
    }   
}

void iremove(int *size, int ar[], int num) {
    if (*size == 0) {
        printf("The array is empty\n");
        return;
    }

    int index = -1;
    int i = 0;
    int j = *size-1;

    for (int i = 0; i < *size; i++) {
        if (ar[i] == num) {
            index = i;
            break;
        }
    }


    if (index == -1) {
        printf("The number is not in the array\n");
    } else {
        int temp = ar[j];
        int temp2;
        ar[j] = 0;

        while (j > index) {
            temp2 = ar[j-1];
            ar[j-1] = temp;
            temp = temp2;
            j--;
        }

        printf("The integer is removed\n");
        (*size)--;
    }
}

void display(int size, int ar[]) { 
    int i;
    printf("The %d numbers in the array: \n", size); 
    
    for(i = 0; i < size; i++) {
        printf("%d ", ar[i]);
    }
    printf("\n"); 
}

void initialize(int *size, int ar[]) {
    int total, i, num;    
    printf("Enter the total number of integers (MAX=%d): \n", MAX);    
    scanf("%d", &total);    
    (*size) = 0;    
    printf("Enter the integers: \n"); 
    for (i = 0; i < total; i++) {       
        scanf("%d", &num);       
        insert(MAX, size, ar, num);    
    } 
}

int main() {
    int arr[10] = {1,2,3,4,4,4,7,8,8,0};
    printf("%d", platform_1_D(arr,10));
}