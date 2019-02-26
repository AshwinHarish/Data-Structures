#include<stdio.h>
#include<stdlib.h>
int main()
{
    int x,val = 0000,a,b,c,d;
    while(1)
    {
        x = val;
        d = x%10;
        x/=10;
        c = x%10;
        x/=10;
        b = x%10;
        x/=10;
        a = x%10;
        printf("%d %d %d %d\n",a,b,c,d);
        val++;
        int c, d;
        for (c = 1; c <= 32767; c++)
            for (d = 1; d <= 167; d++)
            {}
    }
    return 0;
}
