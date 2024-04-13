#include"doublelinklist.h"

int main()
{
    struct node* list = NULL;
    char key;

    printf("Enter 's' or 'S' to start the program.\n");
    key = getchar();

    if (key == 'S' || key == 's')
    {
        while (1)
        {
            printf("1. Enter 'i' or 'I' to insert any value.\n");
            printf("2. Enter 'e' or 'E' to erase any value.\n");
            printf("3. Enter 'd' or 'D' to display the list.\n");
            printf("4. Enter 'o' or 'O' to perform other operations.\n");
            printf("5. Enter 'x' or 'X' to exit the program.\n");

            key = getchar();
            key = getchar();

            switch (key)
            {
            case 'i':
            case 'I':
            {
                char pass;

                if (list == NULL)
                {
                    printf("Enter how many numbers you want to enter: ");
                    int c;
                    scanf("%d", &c);

                    for (int i = 0; i < c; i++)
                    {
                        printf("Enter the value for node %d: ", i + 1);
                        int a;
                        scanf("%d", &a);
                        list = Insert_at_end(a, list);
                    }
                }
                else
                {
                    printf("1. Enter 'e' or 'E' to insert a value at the end.\n");
                    printf("2. Enter 'b' or 'B' to insert a value at the beginning.\n");
                    printf("3. Enter 'a' or 'A' to insert a value at any index.\n");

                    pass = getchar();
                    pass = getchar();

                    switch (pass)
                    {
                    case 'e':
                    case 'E':
                    {
                        printf("Enter the value: ");
                        int a;
                        scanf("%d", &a);
                        list = Insert_at_end(a, list);
                        break;
                    }
                    case 'b':
                    case 'B':
                    {
                        printf("Enter the value: ");
                        int a;
                        scanf("%d", &a);
                        list = Insert_at_begin(a, list);
                        break;
                    }
                    case 'a':
                    case 'A':
                    {
                        printf("Enter the value: ");
                        int a;
                        scanf("%d", &a);
                        printf("Enter the index: ");
                        int b;
                        scanf("%d", &b);
                        list = Insert_at_any(a, b, list);
                        break;
                    }
                    default:
                        printf("Invalid input.\n");
                    }
                }
                break;
            }
            case 'e':
            case 'E':
            {
                char pass;

                if (list == NULL)
                {
                    printf("Your list is empty.\n");
                }
                else
                {
                    printf("1. Enter 'e' or 'E' to erase a value from the end.\n");
                    printf("2. Enter 'b' or 'B' to erase a value from the beginning.\n");
                    printf("3. Enter 'a' or 'A' to erase a value from any index.\n");
                    printf("4. Enter 'n' or 'N' to erase a specific number.\n");
                    printf("5. Enter 'd' or 'D' to erase all the numbers.\n");

                    pass = getchar();
                    pass = getchar();

                    switch (pass)
                    {
                    case 'e':
                    case 'E':
                        list = Delete_end(list);
                        break;
                    case 'b':
                    case 'B':
                        list = Delete_begin(list);
                        break;
                    case 'a':
                    case 'A':
                    {
                        printf("Enter the index: ");
                        int a;
                        scanf("%d", &a);
                        list = Delete_any(a, list);
                        break;
                    }
                    case 'n':
                    case 'N':
                    {
                        printf("Enter the number: ");
                        int a;
                        scanf("%d", &a);
                        list = Delete_num(a, list);
                        break;
                    }
                    case 'd':
                    case 'D':
                        list = Delete_all(list);
                        break;
                    default:
                        printf("Invalid input.\n");
                    }
                }
                break;
            }
            case 'd':
            case 'D':
                Display(list);
                break;
            case 'o':
            case 'O':
            {
                char pass;

                if (list == NULL)
                {
                    printf("Your list is empty.\n");
                }
                else
                {
                    printf("1. Enter 'c' or 'C' to count the numbers.\n");
                    printf("2. Enter 'f' or 'F' to find the index of a number.\n");
                    printf("3. Enter 'a' or 'A' to sort the list in ascending order.\n");
                    printf("4. Enter 'z' or 'Z' to sort the list in descending order.\n");
                    printf("5. Enter 'r' or 'R' to reverse the list.\n");

                    pass = getchar();
                    pass = getchar();

                    switch (pass)
                    {
                    case 'c':
                    case 'C':
                        Counter(list);
                        break;
                    case 'f':
                    case 'F':
                    {
                        printf("Enter the number: ");
                        int a;
                        scanf("%d", &a);
                        Find(a, list);
                        break;
                    }
                    case 'a':
                    case 'A':
                        list = Ascending(list);
                        break;
                    case 'z':
                    case 'Z':
                        list = Descending(list);
                        break;
                    case 'r':
                    case 'R':
                        list = Reverse(list);
                        break;
                    default:
                        printf("Invalid input.\n");
                    }
                }
                break;
            }
            case 'x':
            case 'X':
                printf("Exiting the program...\n");
                exit(0);
            default:
                printf("Invalid input.\n");
            }
        }
    }
    else
    {
        printf("You entered an invalid key. Program terminated.\n");
    }

    return 0;
}
