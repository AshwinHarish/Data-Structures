#include<stdio.h>
typedef struct
{
    int row, column, value;
}term;
void transpose(term a[], term t[]);
void displayMatrix(term a[])
{
    int i;
    for(i=0; i<=a[0].value; i++)
    {
        printf("%d\t%d\t%d\t",a[i].row, a[i].column, a[i].value);
        printf("\n");
    }
}
void transpose(term a[], term b[])
{
    int rowTerms[10],startingPos[10], i;
    int j,numCols=a[0].column, numTerms=a[0].value;
    b[0].row=numCols;
    b[0].column=a[0].row;
    b[0].value=numTerms;
    for(i=0; i<numCols; i++)
    {
        rowTerms[i]=0;
    }
    for(i=1; i<=numTerms; i++)
    {
        rowTerms[a[i].column]++;
    }
    startingPos[0]=1;
    for(i=1; i<numCols; i++)
    {
        startingPos[i]=startingPos[i-1]+rowTerms[i-1];
    }
    for(i=1; i<=numTerms; i++)
    {
        j=startingPos[a[i].column]++;
        b[j].row=a[i].column;
        b[j].column=a[i].row;
        b[j].value=a[i].value;
    }
}

void main()
{
    int mat, count = 1;
    term a[10], t[10];
    int i, j, x, y;
    printf("Enter number of rows & columns");
    scanf("%d%d",&x, &y);
    a[0].row = x;
    a[0].column = y;
    printf("Enter the elements :");
    for(i=0; i<x; i++)
        for(j=0; j<y; j++)
        {
            scanf("%d", &mat);
            if(mat)
            {
                a[count].row = i;
                a[count].column = j;
                a[count].value  = mat;
                count++;
            }
        }
    a[0].value = count-1;
    printf("Entered matrix :\n");
    displayMatrix(a);
    transpose(a,t);
    printf("Transpose matrix :\n");
    displayMatrix(t);
}

