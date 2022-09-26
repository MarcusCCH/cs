#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <math.h>
void display_matrix(int matrix[][2], int num_row)
{
    for (int r = 0; r < num_row; r++)
    {
        for (int c = 0; c < 2; c++)
        {
            printf("\t%d", matrix[r][c]);
        }
        printf("\n");
    }
}
float circleArea(float r)
{
    return M_PI * pow(r,2);
}
int main(){
    //interaction
    // float g;
    // int y;
    // printf("What is your GPA : ");
    // scanf("%f",&g);
    // printf("What is your year : ");
    // scanf("%d", &y);
    // printf("I am a year %0d stduent with GPA %0.1f.",y,g);



    //matrix addition
    // int matrix_A[3][2] = {
    //     {0, 1},
    //     {2, 3},
    //     {4, 5}};

    // int matrix_B[3][2] = {
    //     {0, 1},
    //     {2, 3},
    //     {4, 5}};

    // int result[3][2] = {0};

    // // your code starts here
    // for (int i = 0; i < 3; i++)
    // {
    //     for (int j = 0; j < 2; j++)
    //     {
    //         result[i][j] = matrix_A[i][j] + matrix_B[i][j];   
    //         }
    //     }
    //     // your code ends here

    //     printf("A = \n");
    //     display_matrix(matrix_A, 3);
    //     printf("\nB = \n");
    //     display_matrix(matrix_B, 3);
    //     printf("\nA + B = \n");
    //     display_matrix(result, 3);

        //trimming
        // char input[] = "Welcome to HKUST Robotics Team Software Tutorial";
        // printf("Before trimming: %s\n", input);

        // char output[10000];
        // for(int i = 0 ; input[i] != ' '; i++){
        //     output[i] = input[i];
        // }
        // printf("After trimming: %s\n", output);

        // circle area 
        printf("%f", circleArea(5.0f));

    return 0;
    }