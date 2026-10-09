#include <stdio.h>

int main()
{

    int Num1, Num2, Num3;

    printf("Enter three numbers:");
    scanf("%d %d %d", &Num1, &Num2, &Num3);
    printf("\nThe three numbers are:%d %d %d", Num1, Num2, Num3);
    printf("Checcking the biggest.....\n");

    if (Num1 > Num2 && Num1 > Num3)
    {
        printf("The largest number =%d", Num1);
    }
    else if (Num2 > Num1 && Num2 > Num3)
    {
        printf("The largest number =%d", Num2);
    }
    else
    {
        printf("The largest number =%d", Num3);
    }

    return 0;
}
