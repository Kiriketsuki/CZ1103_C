#include <stdio.h>
#include <math.h>
//qn 1
// int main(){
//     int student_id = 0,mark;
//     char grade = 'F';
//     while (student_id != -1){
//         printf("Enter student id: \n");
//         scanf("%d", &student_id);

//         if (student_id != -1){
//             printf("Please enter mark: \n");
//             scanf("%d", &mark);
//             if (mark >= 75){
//                 grade = 'A';
//             } 
//             else if (mark < 75 && mark >= 65){
//                 grade = 'B';
//             }
//             else if (mark < 65 && mark >= 55){
//                 grade = 'C';
//             }
//             else if (mark < 55 && mark >= 45){
//                 grade = 'D';
//             }

//             switch (grade){
//             case 'A':
//                 printf("Grade: A\n");
//                 break;
//             case 'B':
//                 printf("Grade: B\n");
//                 break;
//             case 'C':
//                 printf("Grade: C\n");
//                 break;
//             case 'D':
//                 printf("Grade: D\n");
//             default:
//                 printf("Grade: F\n");
//             }
//         }
//         else {
//             return 0;
//         }
//     }
// }

//qn 2
// int main()
// {
//     int num_lines = 0;
 
//     printf("Please enter number of lines \n");
//     scanf("%d", &num_lines);

    

//     for (int i = 0; i < num_lines; i++)
//     {
//         int counter = 0, input = 0;
//         float sum = 0.0;
//         printf("Enter line %d, end with -1\n", i+1);

//         while (input != -1)
//         {   
//             scanf("%d", &input);
//             if (input != -1)
//             {
//                 sum += input;
//                 counter++;
//             }            
//         }

//         printf("Average = %.2f\n", sum/counter);
//     }
// }

//qn 3

// int main()
// {
//     int height, pattern = 1;
//     printf("Please enter the height of the pattern\n");
//     scanf("%d", &height);

//     for (int i = 1; i <= height; i++)
//     {
//         if (pattern == 4)
//         {
//             pattern = 1;
//         }

//         for (int j = 0; j < i; j++)
//         {
//             printf("%d", pattern);
//         }
//         printf("\n");
//         pattern++;
//     }
    
// }

//qn 4

long factorial(int n)
{
    if (n == 0)
    {
        return 1;
    }
    else
    {
        return(n*factorial(n-1));
    }
    
}

int main()
{
    float value, sum;
    printf("Please enter x:\n");
    scanf("%f", &value);

    for (int i = 0; i < 10; i++)
    {
        sum += (pow(value,i)/factorial(i));
    }
    
    printf("Result = %.2f", sum);
}