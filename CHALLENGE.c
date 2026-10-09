/*Challenge 2: Number Analyzer
Beginner → Intermediate

Your task is to write a C program that asks the user to enter an integer and determines three things:

Is the number positive, negative, or zero?

Is it even or odd?

If it's positive, is it greater than 100?*/

#include <stdio.h>
//number analyzer
int main(){
    
    int Number;
    int positive=0;

    printf("Enter a number: ");
    scanf("%d",&Number);

    if(Number>0){
    printf("The number is positive");
    positive=1;
    }
    else if(Number==0){
        printf("the number is zero");
    }else{
        printf("The number is negative");
    }

    if(Number%2==0){
        printf("the number is even.");
    }
    else{
        printf("the number is odd.");
    }
    
    if(positive){
        printf("the number is greater than 100.");
    }else{
        printf("the number is less than or equal to 100.");
    }
    
    return 0;
}
