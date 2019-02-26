#include<stdio.h>
#include<stdlib.h>
#define COMPARE(a,b) ((a)==(b))?0:((a)<(b))?-1:1
int avail, startD;
typedef struct
{
    int exp;
    float coef;
}element;
element node[100];

void attach(float coefficient, int exponent)
{
    node[startD].coef = coefficient;
    node[startD].exp = exponent;
    startD++;
}

void polyprint(int start, int end)
{
    int i;
    for(i = start; i < end; i++)
        printf("%.2f X^%d + ", node[i].coef, node[i].exp);
    printf("%.2f X^%d \n", node[i].coef, node[i].exp);
}

void polyadd(int startA, int endA, int startB, int endB)
{
    float sum;
    while((startA <= endA) && (startB <= endB))
        switch(COMPARE(node[startA].exp, node[startB].exp))
        {
            case -1:
                attach(node[startB].coef, node[startB].exp);
                startB++;
                break;
            case 0:
                sum = node[startA].coef + node[startB].coef;
                if(sum)
                    attach(sum, node[startA].exp);
                startA++;
                startB++;
                break;
            case 1:
                attach(node[startA].coef, node[startA].exp);
                startA++;
                break;
        }
    for(; startA <= endA; startA++)
        attach(node[startA].coef, node[startA].exp);
    for(; startB <= endB; startB++)
        attach(node[startB].coef, node[startB].exp);
    avail = startD;
}

main()
{
    int t1, t2, i;
    printf("Enter Number of terms in first polynomial :");
    scanf("%d",&t1);
    printf("Enter coefficients and exponents :\n");
    for(i = 0; i < t1; i++)
        scanf("%f%d", &node[i].coef, &node[i].exp);
    printf("Enter Number of terms in second polynomial :");
    scanf("%d",&t2);
    printf("Enter coefficients and exponents :\n");
    for(i = t1; i < t1+t2; i++)
        scanf("%f%d", &node[i].coef, &node[i].exp);
    startD = t1 + t2;
    printf("First Polynomial :\n");
    polyprint(0, t1-1);
    printf("Second Polynomial :\n");
    polyprint(t1, t1+t2-1);
    printf("Added Polynomial :\n");
    polyadd(0, t1-1, t1, t1+t2-1);
    polyprint(t1+t2,avail-1);
    return 0;
}
