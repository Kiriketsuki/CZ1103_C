#include <stdio.h>
#include <math.h>

double compute_pay_1(int no_of_hours, int pay_rate) {
    if (no_of_hours < 160) {
        return no_of_hours * pay_rate;
    } else {
        int excess_hours = no_of_hours - 160;
        return 160 * pay_rate + excess_hours * 1.5 * pay_rate;
    }
}

void read_input(int *id, int *no_of_hours, int *pay_rate) {
    printf("Enter ID (-1 to end): \n");
    scanf("%d", id);

    if (*id == -1) {
        return;
    } else {
        printf("Enter number of hours: \n");
        scanf("%d", no_of_hours);
        printf("Enter hourly pay rate: \n");
        scanf("%d", pay_rate);
    }
}

double compute_salary_1(int no_of_hours, int pay_rate) {
    if (no_of_hours < 160) {
        return no_of_hours * pay_rate;
    } else {
        int excess_hours = no_of_hours - 160;
        return 160 * pay_rate + excess_hours * 1.5 * pay_rate;
    }
}

float power_1(float num, int p) {
    float to_return = 1;
    if (p == 0) {
        return to_return;
    } else if (p < 0) {
        for (int i = 0; i > p; i--) {
            to_return /= num;
        }
    } else {
        for (int i = 0; i < p; i++) {
            to_return *= num;
        }
    }
    return to_return;
}

int perfect_prod(int num) {
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

void print_pattern_2(int height) {
    char to_print = 'A';

    for (int i = 1; i != height+1; i++) {
        if (i%2 == 0) {
            to_print = 'B';
        }

        for (int j = 1; j != i+1; j++) {
            printf("%c", to_print);
            if (to_print == 'A') {
                to_print++;
            } else {
                to_print--;
            }
        }
        printf("\n");
    }
}

void print_pattern_3(int height) {
    int to_print = 1;

    for (int i = 1; i < height+1; i++) {
        to_print = i;
        for (int j = 1; j < i+1; j++) {
            printf("%d", to_print);
            if (to_print == 9) {
                to_print = 0;
            } else {
                to_print++;
            }
        }
        printf("\n");
    }
}

void compute_total(int num_of_lines) {
    for (int i = 1; i < num_of_lines + 1; i++) {
        int sum = 0;
        int new_num;
        int new_num_2;
        printf("Enter line %d\n", i);
        scanf("%d", &new_num);
        sum += new_num;
        for (int i = 0; i != new_num; i++) {
            scanf("%d", &new_num_2);
            sum += new_num_2;
        }

        printf("Total: %d\n", sum);
    }
}

int sum_sq_digits(int num) {
    int to_return = 0;

    do {
        int digit = num % 10;
        to_return += (digit*digit);
        num = num/10;
    } while (num > 0);

    return to_return;
}

int count_even_digits(int num) {
    int to_return = 0;
    do {
        int digit = num % 10;
        if (digit % 2 == 0) {
            to_return++;
        }
        num = num/10;
    } while (num > 0);

    return to_return;
}

int all_even_digits(int num) {
    int to_return = 1;
    do {
        int digit = num%10;
        if (digit % 2 != 0) {
            to_return = 0;
            return to_return;
        }
        num = num/10;
    } while (num > 0);

    return to_return;
}

int ext_even_digits(int num) {
    int ten_power = 0;
    int to_return = 0;
    int found = 0;

    do {
        int digit = num%10;
        if (digit % 2 == 0) {
            found = 1;
            to_return += digit*pow(10,ten_power);
            ten_power++;
        }
        num = num / 10;
    } while (num > 0);

    if (!found) {
        return -1;
    }
    return to_return;
}

int reverse_digits(int num) {
    int to_return = 0;
    
    do {
        to_return *= 10;
        int digit = num%10;
        to_return += digit;
        num /= 10;
    } while (num > 0);

    return to_return;
}

int main() {
    printf("%d", reverse_digits(8));
}