#include <stdio.h>
//qn 1

// #define INIT_VALUE -1000

// int find_ar_1D(int size,int ar[],int target);

// int main(){
//     int ar[20];
//     int size, i, target;
//     int result = INIT_VALUE;
    
//     printf("Enter array size:\n");
//     scanf("%d",&size);
//     printf("Enter %d data:\n", size);
    
//     for(int i = 0;i <= size - 1;i++) {
//         scanf("%d",&ar[i]);
//     }

//     printf("Enter the target number:\n");
//     scanf("%d",&target);
    
//     result = find_ar_1D(size,ar,target);
//     if (result == -1){
//         printf("find_ar_1D(): Not found\n");
//     }   else {
//             printf("find_ar_1D(): %d",result);
//         }
        
            
//     return 0;
// }
            
// int find_ar_1D(int size,int ar[],int target) {
//     for (int i = 0; i < size; i++) {
//         if (ar[i] == target) {
//             return i;
//         }
//     }
//     return -1;
// }

//qn 2

// #define SIZE 3
// void swap_2_rows (int ar[][SIZE],int r1,int r2);
// void swap_2_cols(int ar[][SIZE],int c1,int c2);
// void display(int ar[][SIZE]);

// int main(){
//     int array[SIZE][SIZE];
//     int row1, row2, col1, col2;
//     int i, j;
//     int choice;

//     printf("Select one of the following options:\n");
//     printf("1: getInput() \n");
//     printf("2: swap_2_rows() \n");
//     printf("3: swap_2_cols() \n");
//     printf("4: display() \n");
//     printf("5: exit() \n");
    
//     do {
//         printf("Enter your choice: \n");
//         scanf("%d",&choice);
//         switch(choice){
//             case 1:
//                 printf("Enter the matrix(3x3):\n");
//                 for(i=0;i<SIZE;i++)
//                     for(j=0;j<SIZE;j++)
//                         scanf("%d",&array[i][j]);
//                         break;
//             case 2:
//                 printf("Enter two rows for swapping: \n");
//                 scanf("%d %d",&row1,&row2);
//                 swap_2_rows(array,row1,row2);
//                 printf("The new array is: \n");
//                 display(array);
//                 break;
            
//             case 3:
//                 printf("Enter two columns for swapping: \n");
//                 scanf("%d %d",&col1,&col2);
//                 swap_2_cols(array,col1,col2);
//                 printf("The new array is: \n");
//                 display(array);
//                 break;
//             case 4:
//                 display(array);
//                 break;
//             }
//         } while(choice<5);
        
//         return 0;
// }
// void display(int ar[][SIZE]){
//     int l,m;
    
//     for(l=0;l<SIZE;l++) {
//         for(m=0;m<SIZE;m++) {
//             printf("%d",ar[l][m]);
//             printf(" ");
//         }    
//         printf("\n");
//     }
// }

// void swap_2_rows (int ar[][SIZE], int r1, int r2) {
//     int ar_copy[SIZE][SIZE];

//     for (int i = 0; i < SIZE; i++){
//         for (int j = 0; j < SIZE; j++){
//             ar_copy[i][j] = ar[i][j];
//         }
//     }

//     for (int k = 0; k < SIZE; k++){
//         ar[r1][k] = ar_copy[r2][k];
//     }

//     for (int l = 0; l < SIZE; l++){
//         ar[r2][l] = ar_copy[r1][l];
//     }
    
// }

// void swap_2_cols (int ar[][SIZE], int c1, int c2) {
//     int ar_copy[SIZE][SIZE];

//     for (int i = 0; i < SIZE; i++){
//         for (int j = 0; j < SIZE; j++){
//             ar_copy[i][j] = ar[i][j];
//         }
//     }
//     for (int k = 0; k < SIZE; k++){
//         ar[k][c1] = ar_copy[k][c2];
//     }

//     for (int l = 0; l < SIZE; l++){
//         ar[l][c2] = ar_copy[l][c1];
//     }
// }

//qn 3

#include <stdio.h>
void printReverse1 (int ar[], int size);
void printReverse2 (int ar[], int size);
void reverseAr1D (int ar[], int size);

int main () {
    int ar[80];
    int size, i;
    printf("Enter array size: \n");
    scanf("%d", &size);
    printf("Enter %d data: \n", size);
    
    for (i = 0; i <= size-1; i++) {
        scanf("%d", &ar[i]);
    }

    printReverse1(ar, size);
    printReverse2(ar, size);
    reverseAr1D(ar,size);
    printf("reverseAr1D(): ");
    
    if (size>0) {
        for (i = 0; i < size; i++) {
            printf("%d", ar[i]);
            printf(" ");
        }
    }
    return 0;
}

void printReverse1 (int ar[], int size) {
    for (int i = size - 1; i > -1; i--) {
        printf("%d", ar[i]);
        printf(" ");
    }
    putchar('\n');
}

void printReverse2 (int ar[], int size) {
    for (int *pt = &ar[size-1]; pt >= ar; pt--) {
        printf("%d", *pt);
        printf(" ");
    }
    putchar('\n');
}

void reverseAr1D (int ar[], int size) {
    int ar_copy[size];
    int *pt = ar;

    for (int i = 0; i < size; i++) {
        ar_copy[i] = ar[i];
    }

    for (int j = size - 1; j > -1; j--) {
        *pt = ar_copy[j];
        pt++;
    }
}