#include <stdio.h>
#include <math.h>
#define SIZE 10
#define INIT_VALUE 999

float absolute_sum_1_d(int size, float vector[]) {
    float to_return = 0;
    for (int i = 0; i < size; i++) {
        to_return += fabs(vector[i]);
    }

    return to_return;
}

void find_2_max_1_d(int ar[], int size, int *max1, int *max2) {
    *max1 = -100000000;
    *max2 = -100000000;

    for (int i = 0; i < size; i++) {
        if (ar[i] > *max1) {
            *max1 = ar[i];
        }
    }

    for (int i = 0; i < size; i++) {
        if (ar[i] > *max2 && ar[i] != *max1) {
            *max2 = ar[i];
        }
    }
}

void find_min_max_1(int ar[], int size, int *min, int *max) {
    *min = ar[0];
    *max = ar[0];

    for (int i = 0; i < size; i++) {
        if (*min > ar[i]) {
            *min = ar[i];
        }

        if (*max < ar[i]) {
            *max = ar[i];
        }
    }
}

void special_numbers_1_d(int ar[], int num, int *size) {
    for (int i = 100; i < num; i++) {
        int sum = 0;
        int j = i;
        do {
            int digit = j%10;
            sum += pow(digit,3);
            j /= 10;
        } while ( j > 0);

        if (sum == i) {
            ar[*size] = i;
            (*size)++;
        }
    }
}

void find_average_2_d(float matrix[][4]) {
    for (int i = 0; i < 4; i++) {
        float sum = 0;
        for (int j = 0; j < 4; j++){
            if (j != 3) {
                sum += matrix[i][j];
            } else {
                matrix[i][j] = sum/3;
            }
        }
    }
}

void compute_toal_2_d(int matrix[SIZE][SIZE]) {
    for (int i = 0; i < SIZE; i++) {
        int sum = 0;
        for (int j = 0; j < SIZE; j++) {
            if (j != SIZE - 1) {
                sum += matrix[i][j];
            } else {
                matrix[i][j] = sum;
            }
        }
    }
}

int platform_1_d(int ar[], int size) {
    int current;
    int longest_chain = 1;
    int current_chain = 1;

    for (int i = 0 ; i < size; i ++) {
        if (i != 0) {
            current = ar[i];
            if (current == ar[i-1]) {
                current_chain++;
                if (current_chain > longest_chain) {
                    longest_chain = current_chain;
                }
            }
        }
    }

    return longest_chain;
}

void swap_min_max_1_d(int ar[], int size) {
    int max = ar[0];
    int min = ar[0];
    int copy[size];

    for (int h = 0; h < size; h++) {
        copy[h] = ar[h];
    }

    for (int i = 0; i < size; i++) {
        if (ar[i] > max) {
            max = ar[i];
        }

        if (ar[i] < min) {
            min = ar[i];
        }
    }

    printf("max = %d\n", max);
    printf("min = %d\n", min);

    for (int j = size-1; j > -1; j--) {
        if (ar[j] == max) {
            printf("found max\n");
            copy[j] = min;
        }
    }

    for (int k = size-1; k > -1; k--) {
        if (ar[k] == min) {
            printf("found min\n");
            copy[k] = max;
        }
    }

    for (int l = 0; l < size; l++) {
        ar[l] = copy[l];
    }
}

int symmetry_2_d(int M[3][3], int row_size, int col_size) {
    int to_return = 1; 
    for (int i = 0; i < row_size; i++) {
        for (int j = 0; j < col_size; j++) {
            if (M[i][j] != M[j][i]) {
                to_return = 0;
                return to_return;
            }
        }
    }
    return to_return;
}

void compress_2_d(int ar[4][4], int row_size, int col_size) {
    for (int i = 0; i < row_size; i++) {
        int one_count = 0;
        int zero_count = 0;
        for (int j = 0; j < col_size; j++) {
            if (ar[i][j] == 1) {
                one_count ++;
            } else {
                zero_count ++;
            }
            ar[i][j] = -1;
        }
        ar[i][0] = 1;
        ar[i][1] = one_count;
        ar[i][2] = 0;
        ar[i][3] = zero_count;
    }
}

int min_of_max_2_d(int ar[][SIZE], int row_size, int col_size) {
    int min_max = 10000;
    for (int i = 0; i < row_size; i++) {
        int row_max = 0;
        for (int j = 0; j < col_size; j++) {
            if (ar[i][j] > row_max) {
                row_max = ar[i][j];
            }
        }
        if (row_max < min_max) {
            min_max = row_max;
        }
    }
    return min_max;
}

int main() {
    int ar[][SIZE] = {{1,2,3,4,5},{2,3,4,5,6},{5,6,7,8,9},{8,10,2,4,7},{2,3,4,5,8}};
    printf("%d", min_of_max_2_d(ar,5,5));
}