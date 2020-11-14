#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 100

typedef struct {
    char name[20];
    int tel_no;
} phone_book;

int read_in(phone_book *pb) {
    char input_name[20], *p;
    char imagine;
    int index = 0;

    printf("Enter name:\n");
    fgets(input_name,80,stdin);
    if (p = strchr(input_name,'\n')) {
        *p = '\0';
    } 

    while (strcmp(input_name, "#") != 0) {
        strcpy((pb+index)->name, input_name);
        printf("Enter tel:\n");
        scanf("%d", &(pb+index)->tel_no);
        scanf("%c", &imagine);

        printf("Enter name:\n");
        fgets(input_name,80,stdin);
        if (p = strchr(input_name,'\n')){
            *p = '\0';
        } 
        index++;
    }

    return index;
}

void print_pb(phone_book *pb, int size) {
    if (size == 0) {
        printf("Empty phonebook\n");
        return;
    }

    for (int i = 0; i < size; i++) {
        printf("Name: %s\n", (pb+i)->name);
        printf("Tel. No.: %d\n", (pb+i)->tel_no);
    }

}

void search(phone_book *pb, int size, char *target) {
    int found = 1;
    for (int i = 0; i < size; i++) {
        found = strcmp((pb+i)->name, target);
        if (found == 0) {
            printf("Name = %s, Tel = %d\n", (pb+i)->name, (pb+i)->tel_no);
            return;
        }
    }

    printf("Name not found!\n");
}

int main() {
    phone_book s[MAX];
    char t[20], *p;
    int size=0, choice;
    char dummychar;
    
    printf("Select one of the following options: \n");
    printf("1: readin()\n");
    printf("2: search()\n");
    printf("3: printPB()\n");
    printf("4: exit()\n");
    do {
        printf("Enter your choice: \n");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                scanf("%c", &dummychar);
                size = read_in(s);
                break;
            case 2:
                scanf("%c", &dummychar);
                printf("Enter search name: \n");
                fgets(t, 20, stdin);
                if (p=strchr(t,'\n')) *p = '\0';
                search(s,size,t);
                break;
            case 3:
                print_pb(s, size);
                break;
            }
    } while (choice < 4);
    return 0; 
}
