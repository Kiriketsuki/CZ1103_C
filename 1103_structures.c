#include <stdio.h>
#include <string.h>
#define SIZE 50
#define MAX 100

typedef struct {
    int id;
    char name[50];
} Student;



void input_student(Student *s, int size) {
    for (int i = 0; i < size; i++) {
        int id;
        char name[50];
        char *p;
        char imagine;

        printf("Student ID:\n");
        scanf("%d", &id);
        scanf("%c",&imagine);
        printf("Student Name:\n");
        fgets(name,50, stdin);
        if (p = strchr(name,'\n')) {
            *p = '\0';
        }

        (s+i)->id = id;
        strcpy(s[i].name, name);
    }
}

void print_student(Student *s, int size) {
    if (size == 0) {
        printf("Array is empty\n");
        return;
    }

    for (int i = 0; i < size; i++) {
        printf("Student ID: %d, Student Name: %s\n", s[i].id, s[i].name);
    }
}

void remove_student(Student *s, int *size, char *target) {
    if (*size == 0) {
        printf("Array is empty\n");
        return;
    }

    int removable_index = 0;
    int found = 0;
    for (int i = 0; i < *size; i++) {
        if (strcmp(target,s[i].name) == 0) {
            found = 1;
            removable_index = i;
            break;
        }
    }

    if (found == 0) {
        printf("Student not in array\n");
        return;
    }

    for (int j = removable_index; j < *size; j++) {
        s[j].id = s[j+1].id;
        strcpy(s[j].name,s[j+1].name);
    }
    (*size)--;
    printf("Student removed\n");
}

struct account {
    struct {
        char last_name[10];
        char first_name[10];
    } names;

    int account_num;
    double balance;
};

void next_customer(struct account *acct) {
    char first_name[10];
    char last_name[10];
    char imagine;
    int acc_num;
    double acc_bal;

    printf("Enter names (first_name last_name)\n");
    scanf("%s %s", &first_name, &last_name);
    scanf("%c", &imagine);

    strcpy(acct->names.first_name, first_name);
    strcpy(acct->names.last_name, last_name);

    if ((strcmp(first_name, "End") == 0) && (strcmp(last_name, "Customer") == 0)) {
        return;
    }

    printf("Enter account number:\n");
    scanf("%d", &acc_num);
    printf("Enter balance:\n");
    scanf("%lf", &acc_bal);

    acct->account_num = acc_num;
    acct->balance = acc_bal;
}

void print_customer(struct account acct) {
    struct account *pt = &acct;

    printf("Customer record:\n");
    printf("%s %s %d %.2lf\n", pt->names.first_name, pt->names.last_name, pt->account_num, pt->balance);
}

typedef struct {
    char name[40];
    char tel_no[40];
    int id;
    double salary;
} Employee;

int read_in(Employee *emp) {
    int to_return = 0;
    char name[40];
    char *p;
    char tel_no[40];
    int id;
    double salary;
    char imagine;
    

    do {
        scanf("%c", &imagine);
        printf("Enter name:\n");
        fgets(name, 40, stdin);
        if (p = strchr(name, '\n')) {
            *p = '\0';
        }

        if ((strcmp(name, "#") == 0)) {
            return to_return;
        }

        printf("Enter tel:\n");
        fgets(tel_no, 40, stdin);
        if (p = strchr(tel_no, '\n')) {
            *p = '\0';
        }

        printf("Enter id:\n");
        scanf("%d", &id);

        printf("Enter salary:\n");
        scanf("%lf", &salary);

        (emp+to_return)->salary = salary;
        (emp+to_return)->id = id;
        strcpy((emp+to_return)->tel_no, tel_no);
        strcpy((emp+to_return)->name, name);
        to_return++;
    } while ((strcmp(name, "#") != 0));

    return to_return;
}

void print_emp(Employee *emp, int size) {
    printf("The current employee list:\n");
    if (size == 0) {
        printf("Empty array\n");
    } else {
        for (int i = 0; i < size ; i++) {
            printf("%s %s %d %.2lf\n", emp[i].name, emp[i].tel_no, emp[i].id, emp[i].salary);
        }
    }
}

int search(Employee *emp, int size, char *target) {
    int to_return = -1;
    
    for (int i = 0; i < size; i++) {
        if ((strcmp((emp+i)->name, target) == 0)) {
            printf("Employee found at index location: %d\n", i);
            printf("%s %s %d %.2lf\n", emp[i].name, emp[i].tel_no, emp[i].id, emp[i].salary);
            to_return = 1;
            return to_return;
        }
    }
    
    return to_return;
}

int add_employee(Employee *emp, int size, char *target) {
    int to_return = 0;
    char name[40];
    char *p;
    char tel_no[40];
    int id;
    double salary;

    printf("Enter tel:\n");
    fgets(tel_no, 40, stdin);
    if (p = strchr(tel_no, '\n')) {
        *p = '\0';
    }

    printf("Enter id:\n");
    scanf("%d", &id);

    printf("Enter salary:\n");
    scanf("%lf", &salary);

    (emp+size)->salary = salary;
    (emp+size)->id = id;
    strcpy((emp+size)->name, target);
    strcpy((emp+size)->tel_no, tel_no);
    printf("Added at position: %d\n", size);
    size++;
    return size;
}

int main() {    
    Employee emp[MAX]; 
    char name[40], *p; 
    int size, choice, result;    
    printf("Select one of the following options: \n");    
    printf("1: readin() \n");         
    printf("2: search() \n");    
    printf("3: addEmployee() \n");   
    printf("4: print() \n");    
    printf("5: exit() \n");       

    do {       
        printf("Enter your choice: \n");       
        scanf("%d", &choice); 
        
        switch (choice) { 
            case 1:                        
                size = read_in(emp);         
                break;                
            case 2:                        
                printf("Enter search name: \n");             
                scanf("\n");             
                fgets(name, 40, stdin);   
                if (p = strchr(name,'\n')) *p = '\0';             
                result = search(emp,size,name);    
                
                if (result != 1)                 
                    printf ("Name not found! \n");      
                    break;                
            case 3:                        
                printf("Enter new name: \n");             
                scanf("\n");             
                fgets(name, 40, stdin);   
                if (p=strchr(name,'\n')) *p = '\0';     

                result = search(emp,size,name);   
                
                if (result != 1)                
                    size = add_employee(emp, size, name);      
                else               
                    printf("The new name has already existed in the database\n"); 
                    break;          
            case 4:             
                print_emp(emp, size); 
                break; 
            default:  
                break;       
        }     
    } while (choice < 5); 
    
    return 0;
}