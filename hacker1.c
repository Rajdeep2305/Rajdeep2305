#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

int insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
    return arr[0];
}

int main() {
    char str[100];
    int arr[100], k = 0, l, m = 0, sum = 0, s, n = 0;
    scanf("%s",str);
    char *token = strtok(str, ":");
    while (token != NULL) {
        arr[k++] = atoi(token); 
        token = strtok(NULL, ":"); 
    }
    
    for(int j = 0; j < k;  j++)
    {
        if(k == m)
        {
            break;
        }
        else 
        {
            int array[j+1];
            for(l = 0; l <= j; l++)
            {
                array[l] = arr[m];
                m++;
            }
            if(m == 1)
            {
                sum = sum + array[0];
            }
            else
            {
                s = insertionSort(array,j+1);
                sum = sum + s;
            }
            n++;
        }
    }
    if(k == (n+1)*n/2)
    {
        printf("%d",sum);
    }
    else
    {
        printf("Not a triangle");
    }
    return 0;
}
