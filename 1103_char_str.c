#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define N 20

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

int count_words(char *str) {
    int to_return = 1;
    for (str; *str != '\0'; str++) {
        if (*str == ' ') {
            to_return++;
        }
    }

    return to_return;
}

void cipher(char *str) {
    for (str; *str != '\0'; str++) {
        if (isalpha(*str)) {
            if (*str != 'Z' && *str  != 'z') {
                (*str)++;
            } else if (*str == 'Z') {
                *str = 'A';
            } else {
                *str = 'a';
            }
        }
    }
}

void decipher(char *str) {
    for (str; *str != '\0'; str++) {
        if (isalpha(*str)) {
            if (*str != 'A' && *str  != 'a') {
                (*str)--;
            } else if (*str == 'A') {
                *str = 'Z';
            } else {
                *str = 'z';
            }
        }
    }
}

char *longest_str_in_ar(char str[N][40], int size, int *length) {
    int max_length = 0;
    int index_of_longest = 0;

    for (int i = 0; i < size; i++) {
        int current_length = 0;
        for (char *pt = str[i]; *pt != '\0'; pt++) {
            current_length++;
        }
        if (current_length > max_length) {
            max_length = current_length;
            index_of_longest = i;
        }
    }

    *length = max_length;
    return str[index_of_longest];
}

void find_min_max_str(char word[][40], char *first, char *last, int size) {
    strcpy(last, word[0]);
    strcpy(first, word[0]);

    for (int i = 0; i != size; i++) {
        if (strcmp(word[i], last) > 0) {
            strcpy(last, word[i]);
        } else if (strcmp(word[i], first) < 0) {
            strcpy(first, word[i]);
        }
    }
}

void max_char_to_front(char *str) {
    int biggest_char = 0;
    int index_of_biggest = 0;

    for (int i = 0; *(str+i) != '\0'; i++) {
        if ((int)*(str+i) > biggest_char) {
            biggest_char = (int)*(str+i);
            index_of_biggest = i;
        }
    }

    for (int j = index_of_biggest; j > 0; j--) {
        char current = *(str+j);
        char previous = *(str+j-1);
        *(str+j) = previous;
        *(str+j-1) = current;
    }

    
}

void str_intersect(char *str1, char *str2, char *str3) {
    char *pt = str2;
    for (str1; *str1 != '\0'; str1++) {
        for (str2; *str2 != '\0'; str2++) {
            if (*str1 == *str2) {
                *str3 = *str1;
                str3++;
            }
        }
        str2 = pt;
    }
    *str3 = '\0';
}

int find_sub_string(char *str, char *substr) {
    int to_return = 1;
    int found = 0;
    char *ptsaver;

    for (str; *str != '\0'; str++) {
        if (*str == *substr) {
            ptsaver = str;
            found = 1;
            for (char *substrpt = substr; *substrpt != '\0'; substrpt++) {
                if (*(str+1) == '\0' && *(substrpt+1) != '\0') {
                    return 0;
                } else if (*str != *substrpt) {
                    to_return = 0;
                } else {
                    to_return = 1;
                    str++;
                }
            }
            str = ptsaver;
        }
    }

    if (found == 0) {
        return 0;
    } else {
        return to_return;
    }
}

int count_sub_string(char str[], char substr[]) {
    int to_return = 0;
    char *ptsaver;

    for (char *strpt = str; *strpt != '\0'; strpt++) {
        if (*strpt == substr[0]) {
            ptsaver = strpt;
            int found = 1;
            for (int i = 0; substr[i] != '\0'; i++) {
                if (*strpt != substr[i]) {
                    found = 0;
                }
                strpt++;
            }
            to_return += found;
            strpt = ptsaver;
        }
    }
    return to_return;
}

int main() {
    char str1[50] = "babababaabf";
    char str2[50] = "ab";
    int test = 0;
    // if (strstr(str1,str2) != 0) {
    //     test = 1;
    // }

    // printf("%d\n", test);
    printf("%d", count_sub_string(str1, str2));
}