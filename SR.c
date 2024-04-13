#include<stdio.h>
#include<stdlib.h>

void push(int a, int arr[], int *top) {
    arr[++(*top)] = a;
}

void pop(int *top) {
    (*top)--;
}

void peek(int arr[], int top) {
    printf("%d\n", arr[top]);
}

void reverse(int arr1[], int arr[], int *top, int *top1) {
    int a;
    a = arr[(*top)--];
    arr1[++(*top1)] = a;
    peek(arr1, *top1);
}

int main() {
    int *arr, *arr1;
    int top = -1, top1 = -1;

    printf("Enter the size of array: ");
    int size;
    scanf("%d", &size);

    arr = (int*)malloc(size * sizeof(int));
    arr1 = (int*)malloc(size * sizeof(int));

    printf("Enter the values of array: \n");
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
        top++;
    }

    printf("Reverse the array.\n");
    for (int j = 0; j < size; j++) {
        reverse(arr1, arr, &top, &top1);
    }

    free(arr);
    free(arr1);

    return 0;
}
