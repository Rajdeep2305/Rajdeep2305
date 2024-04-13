#include<stdio.h>
#include<stdlib.h>
int top = -1;

void push(int a, int arr[])
{
    arr[++top] = a;
}

void pop()
{
    top--;
}

void peek(int arr[])
{
    printf("%d\n", arr[top]);
}

int main()
{
    int *arr;
    char key;
    while (key != 's' || key != 'S')
    {
        printf("Enter 's' or 'S' for start the program: ");
        key = getchar();
        if(key == 's' || key == 'S')
        {
            printf("Enter the size of stack : ");
            int size;
            scanf("%d",&size);
            arr = (int*)malloc(sizeof(int)*size);
            while(1)
            {
                printf("Enter 'e' or 'e' for Push. \nEnter 'd' or 'D' for Pop. \nEnter 'p' or 'P' for Peek. \nEnter 'x' or 'X' for exit. \n");
                char pass;
                pass = getchar();
                pass = getchar();
                switch (pass)
                {
                    case 'e':
                    case 'E':
                    {
                        if(top == size-1)
                        {
                            printf("Stack overflow.\n");
                        }
                        else
                        {
                            printf("Enter the element for push");
                            int a;
                            scanf("%d",&a);
                            push(a, arr);   
                        }
                        break;
                    }
                    case 'd':
                    case 'D':
                    {
                        if(top != -1)
                        {
                            printf("Pop done.\n");
                            pop();
                        }
                        else
                        {
                            printf("Underflow.\n");
                        }
                        break;
                    }
                    case 'p':
                    case 'P':
                    {
                        if(top != -1)
                        {
                            peek(arr);
                        }
                        else
                        {
                            printf("Stack is empty.\n");
                        }
                        break;
                    }
                    case 'x':
                    case 'X':
                    {
                        exit(EXIT_SUCCESS);
                        break;
                    }
                }
            }
        }
        else
        {
            printf("Enter the currect key.\n");
        }
        scanf("%c",&key);
    }
    
}