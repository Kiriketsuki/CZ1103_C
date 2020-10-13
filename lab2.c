#include <stdio.h>
#include <stdbool.h>

int num_digits_1 (int num);
int digits_pos_1 (int num, int digit);
int square_1 (int num);
void num_digits_2 (int num, int *result);
void digits_pos_2 (int num, int digit, int *result);
void square_2 (int num, int *result);

int main() {
    int choice;
    int number, digit, result = 0;

    do {
        printf("\nPerform the following functions ITERATIVELY:\n");
        printf("1:num_digits_1()\n");
        printf("2:num_digits_2()\n");
        printf("3:digit_pos_1()\n");
        printf("4:digit_pos_2()\n");
        printf("5:square_1()\n");
        printf("6:square_2()\n");
        printf("7:quit\n");
        printf("Enter your choice: ");
        scanf("%d",&choice);

        switch (choice) {
            case 1:
                printf("Enter the number:\n");
                scanf("%d",&number);
                printf("num_digits_1(): %d\n", num_digits_1(number));
                break;
            case 2:
                printf("Enter the number:\n");
                scanf("%d",&number);
                num_digits_2(number, &result);
                printf("num_digits_2(): %d\n", result);
                break;
            case 3:
                printf("Enter the number:\n");
                scanf("%d",&number);
                printf("Enter the digit: \n");
                scanf("%d", &digit);
                printf("digits_pos_1(): %d\n", digits_pos_1(number, digit));
                break;
            case 4:
                printf("Enter the number: \n");
                scanf("%d", &number);
                printf("Enter the digit: \n");
                scanf("%d", &digit);
                digits_pos_2(number, digit, &result);
                printf("digits_pos_2(): %d\n", result);
                break;
            case 5:
                printf("Enter the number: \n");
                scanf("%d",&number);
                printf("square_1(): %d\n",square_1(number));
                break;
            case 6:
                printf("Enter the number: \n");
                scanf("%d",&number);
                square_2(number,&result);
                printf("square_2(): %d\n",result);
                break;
            default:
                printf("Program terminating ......\n");
                break;
        }
        
    }
    while (choice < 7);
    return 0;
}

int num_digits_1 (int num) {
    int count = 0;
    do {
        count++;
        num = num/10;
    } while (num > 0);

    return count;
}

void num_digits_2 (int num, int *result) {
    *result = 0;
    int counter = 0;
    do {
        counter++;
        num = num/10;
    } while (num > 0);
    *result = counter;
}

// int digits_pos_1 (int num, int digit) {
//     bool contains = false;
//     int num_copy = num;
//     int num_len = 0;
//     int last_digit;

//     do {
//         num_len++;
//         num_copy = num_copy/10;
//     } while (num_copy > 0);

//     for (int i = 1; i < num_len; i++)
//     {
//         last_digit = num%10;
//         if (digit == last_digit) {
//             return i;
//         } else {
//             num = num/10;
//         }
        
//     }
//     return 0;
// }

int digits_pos_1 (int num, int digit) {
    int pos = 0;
    do {
        pos++;
        if (digit == num%10){
            return pos;
        } else {
            num = num/10;
        }
    } while (num > 0);
    return 0;
}

void digits_pos_2 (int num, int digit, int *result) {
    int pos = 0;
    *result = 0;

    do {
        pos++;

        if (num&10 == digit) {
            *result = pos;
            break;
        }

        num = num/10;
    } while (num > 0);
}

int square_1 (int num) {
    int sum = 0;
    for (int i = 1; i < num*2; i += 2)
    {
        sum += i;
    }
    return sum;
}

void square_2 (int num, int *result) {
    *result = 0;
    for (int i = 1; i <= num*2; i+=2)
    {
        *result += i;
    }
    
}