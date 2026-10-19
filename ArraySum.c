#include <stdio.h>

int main(){

    //GPT TASK1:

    int array[5],sum=0;

    printf("Enter 5 numbers:");

    for(int i=0 ; i<5 ; i++){
        scanf( "%d" , &array[i] );
    }

    for(int i=0 ; i<5 ; i++){
        printf("%d\n",array[i]);
        sum+=array[i];

    }

    printf("Sum=%d",sum);
    
    return 0;

}
