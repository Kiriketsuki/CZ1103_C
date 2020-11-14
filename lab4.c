// //qn 1

// #include <stdio.h>
// #include <string.h> 

// char *sweep_space1(char *str);
// char *sweep_space2(char *str);

// int main() {
//     char str[80], str2[80], *p;
//     printf("Enter the string:\n");
//     fgets(str, 80, stdin);
    
//     if (p = strchr(str,'\n')) {
//         *p ='\0';
//         strcpy(str2, str);
//         printf("sweep_space1(): %s\n", sweep_space1(str));
//         printf("sweep_space2(): %s\n", sweep_space2(str2));
//     }
//     return 0;
// }

// void add_char(char *str, char to_add) {
//     int i = 0;
//     while (*(str+i) != '\0') {
//         i++;
//     }

//     *(str+i) = to_add;
//     *(str+1+i) = '\0';
// }
// char *sweep_space1(char *str) {
//     char copy[1000] = "";
    
//     for (int i = 0; str[i] != '\0'; i++) {
//         if (str[i] != ' ') {
//             add_char(copy,str[i]);
//         }
//     }

//     for (int j = 0; copy[j] != '\0'; j++) {
//         str[j] = copy[j];
//         str[j+1] = '\0';
//     }

//     return str;
// }

// char *sweep_space2(char *str) {
//     char copy[1000] = "";
    
//     for (int i = 0; *(str+i) != '\0'; i++) {
//         if (*(str+i) != ' ') {
//             add_char(copy,*(str+i));
//         }
//     }

//     for (int j = 0; copy[j] != '\0'; j++) {
//         str[j] = copy[j];
//         str[j+1] = '\0';
//     }

//     return str;
// }

//qn 2

// #include <stdio.h>
// #include <string.h>
// #define SIZE 10
// #define INIT_VALUE 999

// void print_names(char nameptr[][80],int size);
// void read_names(char nameptr[][80],int *size);
// int find_target(char *target, char nameptr[][80],int size);

// int main(){
//     char nameptr[SIZE][80], t[40], *p;
//     int size, result = INIT_VALUE;
//     int choice;
    
//     printf("Select one of the following options: \n");
//     printf("1: read_names()\n");
//     printf("2: find_target()\n");
//     printf("3: print_names()\n");
//     printf("4: exit()\n");
    
//     do {
//         printf("Enter your choice: \n");
//         scanf("%d", &choice);
        
//         switch (choice) { 
//             case 1:
//                 read_names(nameptr, &size);
//                 break;
            
//             case 2:
//                 printf("Enter target name:\n");
//                 scanf("\n");
//                 fgets(t, 80, stdin);
                
//                 if (p = strchr(t,'\n')) {
//                     *p='\0';
//                 }
                
//                 result = find_target(t, nameptr, size);
//                 printf("find_target(): %d\n", result);
//                 break;
            
//             case 3:
//                 print_names(nameptr, size);
//                 break;
//         }
//     } while (choice < 4);
    
//     return 0;
// }

// void print_names(char nameptr[][80],int size){
//     int i;
    
//     for (i = 0; i < size; i++) {
//         printf("%s", nameptr[i]);
//         putchar('\n');
//     }
    
// }

// void read_names(char nameptr[][80], int *size) {
//     printf("Enter size: \n");
//     scanf("%d", size);
//     printf("Enter %d names: \n", *size);

//     for (int i = 0; i < *size; i++) {
//         char new_name[80];
//         scanf("%s", &new_name);
//         strcpy(nameptr[i], new_name);
//     }
// }

// int find_target(char *target, char namept[][80], int size) {
//     int to_return = -1;

//     for (int i = 0; i < size; i++) {
//         if (strcmp(namept[i],target) == 0) {
//             to_return = i;
//             return to_return;
//         }
//     }

//     return to_return;
// }

//qn 3

#include <stdio.h>
#include <string.h>
#define INIT_VALUE -1000

int palindrome(char *str);

int main() {
    char str[80], *p;
    int result = INIT_VALUE;
    
    printf("Enter a string: \n");
    fgets(str, 80, stdin);
    
    if (p = strchr(str,'\n')) {
        *p='\0';
    }

    result = palindrome(str);
    
    if (result == 1) {
        printf("palindrome(): A palindrome \n");
    } else if (result == 0) {
        printf("palindrome(): Not a palindrome\n");
    } else {
        printf("An error \n");
    }
    
    return 0;
}

int palindrome(char *str) {
    int length = (int)strlen(str);
    int to_return = 1;

    for (int i = 0; i != (length/2); i++){
        if (str[i] != str[length-i-1]){
            to_return = 0;
        }
    }

    return to_return;
}