#include <stdio.h>

int main(){

    //GPT TASK1:

    int array[5];

    printf("Enter 5 numbers:");

    for(int i=0 ; i<5 ; i++){
        scanf( "%d" , &array[i] );
    }

    for(int i=0 ; i<5 ; i++){
        printf("Array=%d\n",array[i]);
    }

    return 0;

}
