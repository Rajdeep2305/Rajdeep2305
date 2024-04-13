//1. write a C program to design a d array, store integer values in it and print them.
#include<stdio.h>
#include<stdlib.h>
int main()
{
    int a,b,c,d,e;
    int *****arr;
    printf("Enter the size of 5D matrix: ");
    scanf("%d",&a);
    printf("Enter the size of 4D matrix: ");
    scanf("%d",&b);
    printf("Enter the size of 3D matrix: ");
    scanf("%d",&c);
    printf("Enter the size of 2D matrix: ");
    scanf("%d",&d);
    printf("Enter the size of 1D matrix: ");
    scanf("%d",&e);
    arr = (int*****)malloc(a*sizeof(int****));
    for(int i=0;i<a;i++)
    {
        arr[i] = (int****)malloc(b*sizeof(int***));
        for(int j=0;j<b;j++)
        {
            arr[i][j] = (int***)malloc(c*sizeof(int**));
            for(int k=0;k<c;k++)
            {
                arr[i][j][k] = (int**)malloc(d*sizeof(int*));
                for(int l=0;l<d;l++)
                {
                    arr[i][j][k][l] = (int*)malloc(e*sizeof(int));
                    for(int m=0;m<e;m++)
                    {
                        scanf("%d",&arr[i][j][k][l][m]);
                    }
                }
            }
        }
    }
    for(int i=0;i<a;i++)
    {
        for(int j=0;j<b;j++)
        {
            for(int k=0;k<c;k++)
            {
                for(int l=0;l<d;l++)
                {
                    for(int m=0;m<e;m++)
                    {
                        printf("%d\t",arr[i][j][k][l][m]);
                    }
                    printf("\n");
                }
                printf("\n");
            }
            printf("\n");
        }
        printf("\n");
    }
    free(arr);
    return 0;
}