// This program includes a function named "triangle" that outputs Pascal's
// triangle. In general the Pascal's triangle can be represented as:

//             0C0
//           1C1 1C0
//         2C2 2C1 2C0
//       3C3 3C2 3C1 3C0
//      4C4 4C3 4C2 4C1 4C0

// where nCr represents how many ways there are to choose r from n, not
// counting duplicates.

// The formula used to calculate nCr can be written as:
//  nCr=n!/(r!(n-r)!)
// where n! is the factorial of n.

/*
Author: Ridvik Pal
Date Modified: February 11th, 2022
File Name: Lab4Part1.c
Description: This program prints out the pascal's triangle for a row size between 0 and 13.
*/

#include <stdio.h>

//this function returns the factorial of a number
int factorial(int n){
    int fact=1;
    if(n==0){
        fact=1;
    }else{
        for(int i=1; i<=n; i++){
            fact=fact*i;
        }
    }
    return fact;
}

//this function returns a combination in the form of nCr
int choose(int n, int r){
    int nCr = (factorial(n)/((factorial(r))*factorial(n-r)));
    return nCr;
}

//this function prints out the pascal's triangle
void triangle(int rows){
    //increment through the rows
    for(int currentRow=0; currentRow<rows; currentRow++){ 
        //print the first spaces for each row; j must start at 2 because if rows = 1, then there should be no spaces printed, just the number
        for(int spacedRow=1; spacedRow<(rows-currentRow); spacedRow++){ 
            printf("   ");
        }
        //print the actual numbers. These must start at 0 because if rows is 1 then only the number should be printed.
        for(int currentColumn=0; currentColumn<=currentRow; currentColumn++){
            int number = choose(currentRow, currentColumn);
            printf("%d", number);

            //print the right number of spaces based on how many digits are in each "number"
            if (number>=1 && number<10){
                printf("     ");
            }else if (number>=10 && number<100){
                printf("    ");
            }else if(number>=100){
                printf("   ");
            }else{
                printf("  ");
            }
        }
        printf("\n"); //print each line on a new row
    }
}

void main(){
    int input;

    do{
        printf("Enter the number of rows: ");
        scanf("%d", &input);
        
        if (input>=0 && input<=13){
            triangle(input);
        }
    }while (input>=0 && input<=13);
}
