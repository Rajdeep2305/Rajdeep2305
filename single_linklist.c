#include"singlelinklist.h"

int main()
{
    struct node *list = NULL;
    char key;
    while( key != 'S' || key != 's')
    {
        printf("Enter 's' or 'S' for start the program.\n");
        key = getchar();
        if(key == 'S' || key == 's')
        {
            while(key != 'x' || key != 'X')
            {
                printf("1. Enter 'i' or 'I' for Insert any value.\n2. Enter 'e' or 'E' for erase any value.\n3. Enter 'd' or 'D' for display the list.\n4. Enter 'o' or 'O' for perform other opetation.\n5. Enter 'x' or 'X' for exit the program.\n");
                key = getchar();
                key = getchar();
                switch(key)
                {
                    case 'i':
                    {
                        char pass;
                        if(list == NULL)
                        {
                            printf("Enter how many number you want to enter : ");
                            int c;
                            scanf("%d",&c);
                            for(int i = 0; i < c; i++)
                            {
                                printf("Enter the node %d value\t",i+1);
                                int a;
                                scanf("%d",&a);
                                list = Insert_at_end(a,list);
                            }
                        }
                        else
                        {
                            printf("1. Enter 'e' or 'E' for Insert at end.\n2. Enter 'b' or 'B' for Insert at begin.\n3. Enter 'a' or 'A' for Insert at any possition.");
                            pass = getchar();
                            pass = getchar();
                            if( pass == 'e' || pass == 'E')
                            {
                                printf("Enter the number which you want to insert at end\t:");
                                int c;
                                scanf("%d",&c);
                                list = Insert_at_end(c,list);
                            }
                            else if(pass == 'b' || pass == 'B')
                            {
                                printf("Enter the number which you want to insert at begin\t:");\
                                int c;
                                scanf("%d",&c);
                                list = Insert_at_begin(c,list);
                            }
                            else if(pass == 'a' || pass == 'A')
                            {
                                printf("Enter the index value\t:");
                                int d;
                                scanf("%d",&d);
                                printf("Enter the number which you want to insert at any possition\t:");
                                int c;
                                scanf("%d",&c);
                                list = Insert_at_any(c,d,list);
                            }
                        }
                        break;
                    }
                    case 'I':
                    {
                        char pass;
                        if(list == NULL)
                        {
                            printf("Enter how many number you want to enter : ");
                            int c;
                            scanf("%d",&c);
                            for(int i = 0; i < c; i++)
                            {
                                printf("Enter the node %d value\t",i+1);
                                int a;
                                scanf("%d",&a);
                                list = Insert_at_end(a,list);
                            }
                        }
                        else
                        {
                            printf("1. Enter 'e' or 'E' for Insert at end.\n2. Enter 'b' or 'B' for Insert at begin.\n3. Enter 'a' or 'A' for Insert at any possition.");
                            pass = getchar();
                            pass = getchar();
                            if( pass == 'e' || pass == 'E')
                            {
                                printf("Enter the number which you want to insert at end\t:");
                                int c;
                                scanf("%d",&c);
                                list = Insert_at_end(c,list);
                            }
                            else if(pass == 'b' || pass == 'B')
                            {
                                printf("Enter the number which you want to insert at begin\t:");\
                                int c;
                                scanf("%d",&c);
                                list = Insert_at_begin(c,list);
                            }
                            else if(pass == 'a' || pass == 'A')
                            {
                                printf("Enter the index value\t:");
                                int d;
                                scanf("%d",&d);
                                printf("Enter the number which you want to insert at any possition\t:");
                                int c;
                                scanf("%d",&c);
                                list = Insert_at_any(c,d,list);
                            }
                        }
                        break;
                    }
                    case 'e':
                    {
                        char pass;
                        if(list == NULL)
                        {
                            printf("You have no data.\n");
                        }
                        else
                        {
                            printf("1. Enter 'e' or 'E' for Delete at end.\n2. Enter 'b' or 'B' for Delete at begin.\n3. Enter 'i' or 'I' for Delete at any index. \n4. Enter 'n' or 'N' for Delete at any number. \n5. Enter 'a' or 'A' for Delete all node.");
                            pass = getchar();
                            pass = getchar();
                            if(pass == 'e' || pass =='E')
                            {
                                printf("Your last node deleted.\n");
                                list = Delete_end(list);
                            }
                            else if(pass == 'b' || pass == 'B')
                            {
                                printf("Your first node deleted.\n");
                                list = Delete_begin(list);
                            }
                            else if(pass == 'i' || pass == 'I')
                            {
                                printf("Enter the index no. ");
                                int b;
                                scanf("%d",&b);
                                list = Delete_any(b,list);
                            }
                            else if(pass == 'n' || pass == 'N')
                            {
                                printf("Enter the delete number : ");
                                int r;
                                scanf("%d",&r);
                                list = Delete_num(r,list);
                            }
                            else if(pass == 'a' || pass == 'A')
                            {
                                printf("All  data are Deleted.\n");
                                list = Delete_all(list);
                            }
                            else
                            {
                                printf("Enter Currect key.\n");
                            }
                        }
                        break;
                    }
                    case 'E':
                    {
                        char pass;
                        if(list == NULL)
                        {
                            printf("You have no data.\n");
                        }
                        else
                        {
                            printf("1. Enter 'e' or 'E' for Delete at end.\n2. Enter 'b' or 'B' for Delete at begin.\n3. Enter 'i' or 'I' for Delete at any index. \n4. Enter 'n' or 'N' for Delete at any number. \n5. Enter 'a' or 'A' for Delete all node.");
                            pass = getchar();
                            pass = getchar();
                            if(pass == 'e' || pass =='E')
                            {
                                printf("Your last node deleted.\n");
                                list = Delete_end(list);
                            }
                            else if(pass == 'b' || pass == 'B')
                            {
                                printf("Your first node deleted.\n");
                                list = Delete_begin(list);
                            }
                            else if(pass == 'i' || pass == 'I')
                            {
                                printf("Enter the index no. ");
                                int b;
                                scanf("%d",&b);
                                list = Delete_any(b,list);
                            }
                            else if(pass == 'n' || pass == 'N')
                            {
                                printf("Enter the delete number : ");
                                int r;
                                scanf("%d",&r);
                                list = Delete_num(r,list);
                            }
                            else if(pass == 'a' || pass == 'A')
                            {
                                printf("All  data are Deleted.\n");
                                list = Delete_all(list);
                            }
                            else
                            {
                                printf("Enter Currect key.\n");
                            }
                        }
                        break;
                    }
                    case 'o':
                    {
                        char pass;
                        if(list == NULL)
                        {
                            printf("You have no data.\n");
                        }
                        else
                        {
                            printf("1. Enter 'c' or 'C' for Count the list.\n2. Enter 'f' or 'F' for Find a number.\n3. Enter 'r' or 'R' for reverse. \n4. Enter 'a' or 'A' for arrange in Assending Order. \n5. Enter 'd' or 'D' for arrange in Descending Order.");
                            pass = getchar();
                            pass = getchar();
                            if(pass == 'a' || pass == 'A')
                            {
                                printf("arrange in Assending Order.\n");
                                list = Ascending(list);
                            }
                            else if(pass == 'c' || pass == 'C')
                            {
                                printf("Count the list.\n");
                                Counter(list);
                            }
                            else if(pass == 'f' || pass == 'F')
                            {
                                printf("Enter the number: ");
                                int a;
                                scanf("%d",&a);
                                Find(a,list);
                            }
                            else if(pass == 'r' || pass == 'R')
                            {
                                printf("reverse.\n");
                                list = Reverse(list);
                            }
                            else if(pass == 'd' || pass == 'D')
                            {
                                printf("arrange in Descending Order.\n");
                                list = Descending(list);
                            }
                            else
                            {
                                printf("Enter the currecty key.\n");
                            }
                        }
                        break;
                    }
                    case 'd':
                    {
                        printf("Dispaly\n");
                        Display(list);
                        break;
                    }
                    case 'D':
                    {
                        printf("Dispaly\n");
                        Display(list);
                        break;
                    }
                    case 'x':
                    {
                        printf("Your program will be saved.\n Have a Good Day.");
                        exit(EXIT_SUCCESS);
                        break;
                    }
                    case 'X':
                    {
                        printf("Your program will be saved.\n Have a Good Day.");
                        exit(EXIT_SUCCESS);
                        break;
                    }
                }
            }
        }
        else
        {
            printf("Please enter the currect key for enter the code.\n");
        }
        scanf("%c",&key);
    }
}