//qn 1

#include <stdio.h>
#include <string.h> 

char *sweep_space1(char *str);
char *sweep_space2(char *str);

int main() {
    char str[80], str2[80], *p;
    printf("Enter the string:\n");
    fgets(str, 80, stdin);
    
    if (p = strchr(str,'\n')) {
        *p ='\0';
        strcpy(str2, str);
        printf("sweep_space1(): %s\n", sweep_space1(str));
        printf("sweep_space2(): %s\n",sweep_space2(str2));
    }
    return 0;
}

char *sweep_space1(char *str) {

}

char *sweep_space2(char *str) {

}

//qn 2

#include <stdio.h>
#include <string.h>
#define SIZE 10
#define INIT_VALUE 999

void print_names(char nameptr[][80],int size);
void read_names(char nameptr[][80],int *size);
int find_target(char *target, char nameptr[][80],int size);

int main(){
    char nameptr[SIZE][80], t[40], *p;
    int size, result = INIT_VALUE;
    int choice;
    
    printf("Select one of the following options: \n");
    printf("1: read_names()\n");
    printf("2: find_target()\n");
    printf("3: print_names()\n");
    printf("4: exit()\n");
    
    do {
        printf("Enter your choice: \n");
        scanf("%d", &choice);
        
        switch (choice) { 
            case 1:
                read_names(nameptr, &size);
                break;
            
            case 2:
                printf("Enter target name:\n");
                scanf("\n");
                fgets(t, 80, stdin);
                
                if (p = strchr(t,'\n')) {
                    *p='\0';
                }
                
                result = find_target(t, nameptr, size);
                printf("find_target(): %d\n", result);
                break;
            
            case 3:
                print_names(nameptr, size);
                break;
        }
    } while (choice < 4);
    
    return 0;
}

void print_names(char nameptr[][80],int size){
    int i;
    
    for (i = 0; i < size; i++) {
        printf("%s", nameptr[i]);
    }
    
    printf("\n");
}

void read_names(char nameptr[][80], int *size) {

}

int find_target(char *target, char namept[][80], int size) {

}

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

int palidrome(char *str) {
    
}