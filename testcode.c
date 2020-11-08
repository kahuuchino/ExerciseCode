#include <stdio.h>
#include <stdlib.h>

int array[2][2][2] = {1, 2, 3, 4,5,6,7,8};

int main(void)
{
    int a = 1, b = 0, c = 0;
    a = b++ + ++c;
    {
        int b = 0;
        a += b;
        {
            int c = 0;
            a += b + c;
        }
        a += b + c;
    }
    a += b + c;
    for (int i = 0; i < 2;i++)
        for (int j = 0; j < 2;j++)
            for (int k = 0; k < 2;k++)
                printf("%d ", array[i][j][k]);
        //printf("%d,%d,%d", a, b, c);
    return 0;
}

/* int a = 10, *pa = &a;

void func(int *pa){
    printf("%d\n", *pa);
    *pa = 20;
    printf("%d", a);
    pa = (int *)malloc(sizeof(int));
    *pa = 30;
}

int main(void){
    printf("%d\n", pa);
    printf("%d", a);
    func(pa);
    printf("%d\n", *pa);
    printf("%d", a);
    return 0;
} */

/* int main(void)
{
    int m=10,n=0,a=3,b=4;
    if((m!=n)&&(a=n)&&(b=m))
        ;
    printf("%d,%d,%d,%d",m,n,a,b);
    return 0;
} */