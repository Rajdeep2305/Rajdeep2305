#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int main() {

    int a,k = 1,count = 0;
    scanf("%d",&a);
    int arr[a];
    for(int i = 0; i < a; i++)
    {
        arr[i] = '0';
    }
    for(int i = 1; i <= a; i++)
    {
        for(int j = 0; j*k < a; j++)
        {
            if(arr[j*k] == '1')
            {
                arr[j*k] = '0';
            }
            else
            {
                arr[j*k] = '1';
            }
        }
        k++;
    }
    for(int i = 0; i < a; i++)
    {
        if(arr[i] == '1')
        {
            count++;
        }
    }
    printf("%d",count);
    return 0;
}