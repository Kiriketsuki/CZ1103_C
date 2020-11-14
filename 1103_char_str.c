#include <stdio.h>
#include <string.h>
#include <ctype.h>

void insert_char(char *str1, char *str2, char ch) {
    char *pt1 = str1;
    char *pt2 = str2;
    int counter = 1;

    for (pt1; *pt1 != '\0'; pt1++) {
        if (counter % 3 == 0) {
            *pt2 = *pt1;
            pt2++;
            *pt2 = ch;
            pt2++;
            counter++;
        } else {
            *pt2 = *pt1;
            pt2++;
            counter++;
        }
    }
    *pt2 = '\0';
}

int locate_first_char(char *str, char ch) {
    int to_return = -1;
    for (int i = 0; *(str+i) != '\0'; i++) {
        if (*(str+i) == ch) {
            to_return = i;
            return to_return;
        }
    }

    return to_return;
}

void process_string(char *str, int *tot_vowels,int *tot_digits) {
    for (str; *str != '\0'; str++) {
        if (*str == 65 || *str == 69 || *str == 73 || *str == 79 || *str == 85 || *str == 97 || *str == 101 ||
            *str == 105 || *str == 111 || *str == 117) {
                (*tot_vowels)++;
            }
        else if (*str >= 48 && *str <= 57) {
            (*tot_digits)++;
        }
    }
}

int long_word_length(char *str) {
    char current_word[100];
    char *pt = current_word;
    int max_length = 0;
    for (str; *str != '\0'; str++) {
        if (*str == ' ') {
            *pt = '\0';
            int current_length = strlen(current_word);
            if (current_length > max_length) {
                max_length = current_length;
            }
            pt = current_word;
        } else {
            *pt = *str;
            *pt++;
        }
    }
    *pt = '\0';
    int current_length = strlen(current_word);
    if (current_length > max_length) {
        max_length = current_length;
    }
    return max_length;
}

int main() {
    char str[100] = "there are forty students in this class";
    int tot_vowels = 0;
    int tot_digits = 0;
    char str2[100];

    printf("%d", long_word_length(str));
}