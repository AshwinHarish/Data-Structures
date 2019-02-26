#include<stdio.h>
#include<stdlib.h>
main()
{

    long long int n,r = 0,d;
    printf("Enter the numb\n");
    scanf("%lld",&n);
    while(n!=0)
    {
        d = n%10;
        n /= 10;
        r*=10;
        r += d;
    };
    printf("%lld",r);
}

