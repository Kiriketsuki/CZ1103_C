#include <stdio.h> 
#include <string.h> 
#include <ctype.h>
#define SIZE 10

struct account {   
   struct
   {  
      char lastName[10];
      char firstName[10];
   } names;
   int accountNum;
   double balance;
};

void cipher(char *s) {
    for (s; *s != '\0'; s++) {
        if (isalpha(*s)) {
            if(*s != 'z' && *s != 'Z') {
                (*s)++;
            } else if (*s == 'z') {
                (*s) = 'a';
            } else {
                (*s) = 'A';
            }
        }
    }
}

void decipher(char *s) {
    for (s; *s != '\0'; s++) {
        if (isalpha(*s)) {
            if(*s != 'a' && *s != 'A') {
                (*s)--;
            } else if (*s == 'a') {
                (*s) = 'z';
            } else {
                (*s) = 'Z';
            }
        }
    }
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

    printf("First word = %s, Last word = %s", first, last);
}

int find_sub_string(char *str, char *substr) {
    int to_return = 1;
    int found = 0;
    char *ptsaver;
    char *ptsaver2 = substr;

    for (str; *str != '\0'; str++) {
        if (*str == *substr) {
            ptsaver = str;
            found = 1;
            to_return = 1;
            for (char *substrpt = ptsaver2; *substrpt != '\0'; substrpt++) {
                if (*(str+1) == '\0' && *(substrpt+1) != '\0') {
                    return 0;
                } else if (*str != *substrpt) {
                    to_return = 0;
                    str++;
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

void next_customer(struct account *acct) {
    char first_name[10];
	char last_name[10];
	char imagine;
	int acc_number;
	double balance;
	
    printf("Enter names(firstName lastName): \n");
    scanf("%s %s", &first_name, &last_name);
    scanf("%c", &imagine);
    
    strcpy(acct->names.firstName, first_name);
    strcpy(acct->names.lastName, last_name);
    if ((strcmp(first_name, "End") == 0) && (strcmp(last_name, "Customer") == 0)) {
        return;
    }
    
    printf("Enter account number: \n");
    scanf("%d", &acc_number);
    printf("Enter balance: \n");
    scanf("%lf", &balance);
    
    acct->accountNum = acc_number;
    acct->balance = balance;
}

void print_customer(struct account acct) {
    printf("Customer record: \n");
	printf("%s %s %d %.2lf\n", acct.names.firstName, acct.names.lastName, acct.accountNum, acct.balance);
}

int main () {
    char str[40] = "abcdefgh";
    char substr[40] = "abc";

    printf("%d", find_sub_string(str,substr));
}

