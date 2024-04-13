#include<stdio.h>
#include<stdlib.h>

struct node
{
    int val;
    struct node* next;
};

struct node* Insert_at_end(int val, struct node* start);
struct node* Insert_at_begin(int val, struct node* start);
struct node* Insert_at_any(int val, int index, struct node* start);

struct node* Delete_end(struct node* start);
struct node* Delete_begin(struct node* start);
struct node* Delete_any(int index, struct node* start);
struct node* Delete_all(struct node* start);

void Display(struct node* start);

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
                printf("1. Enter 'i' or 'I' for Insert any value.\n2. Enter 'e' or 'E' for erase any value.\n3. Enter 'd' or 'D' for display the list.\n4. Enter 'x' or 'X' for exit the program.\n");
                key = getchar();
                key = getchar();
                switch(key)
                {
                    case 'I':
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
                            printf("1. Enter 'e' or 'E' for Insert at end.\n2. Enter 'b' or 'B' for Insert at begin.\n3. Enter 'a' or 'A' for Insert at any possition.\n");
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
                    case 'E':
                    case 'e':
                    {
                        char pass;
                        if(list == NULL)
                        {
                            printf("You have no data.\n");
                        }
                        else
                        {
                            printf("1. Enter 'e' or 'E' for Delete at end.\n2. Enter 'b' or 'B' for Delete at begin.\n3. Enter 'i' or 'I' for Delete at any index. \n4. Enter 'a' or 'A' for Delete all node.\n");
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
                    case 'D':
                    case 'd':
                    {
                        printf("Dispaly\n");
                        Display(list);
                        break;
                    }
                    case 'X':
                    case 'x':
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

struct node* Insert_at_end(int val, struct node* start)
{
    struct node* tmp = (struct node*)malloc(sizeof(struct node));
    tmp->val = val;
    tmp->next = NULL;

    if (start == NULL)
    {
        start = tmp;
        start->next = start; // Circular linking
    }
    else
    {
        struct node* m = start;
        while (m->next != start)
        {
            m = m->next;
        }
        m->next = tmp;
        tmp->next = start; // Circular linking
    }
    return start;
}

struct node* Insert_at_begin(int val, struct node* start)
{
    struct node* tmp = (struct node*)malloc(sizeof(struct node));
    tmp->val = val;

    if (start == NULL)
    {
        start = tmp;
        start->next = start; // Circular linking
    }
    else
    {
        struct node* m = start;
        while (m->next != start)
        {
            m = m->next;
        }
        tmp->next = start;
        m->next = tmp;
        start = tmp;
    }
    return start;
}

struct node* Insert_at_any(int val, int index, struct node* start)
{
    if (start == NULL)
    {
        return Insert_at_end(val, start);
    }
    else
    {
        if (index == 0)
        {
            return Insert_at_begin(val, start);
        }
        else
        {
            struct node* tmp = (struct node*)malloc(sizeof(struct node));
            tmp->val = val;

            struct node* p = start;
            int count = 0;
            while (count != (index - 1) && p->next != start)
            {
                p = p->next;
                count++;
            }
            tmp->next = p->next;
            p->next = tmp;
            return start;
        }
    }
}

struct node* Delete_end(struct node* start)
{
    if (start == NULL)
    {
        printf("Your list is empty. So, please insert some value.\n");
    }
    else
    {
        struct node* tmp = start;
        struct node* prev = NULL;

        while (tmp->next != start)
        {
            prev = tmp;
            tmp = tmp->next;
        }

        if (prev == NULL)
        {
            free(tmp);
            start = NULL;
        }
        else
        {
            prev->next = start;
            free(tmp);
        }
    }
    return start;
}

struct node* Delete_begin(struct node* start)
{
    if (start == NULL)
    {
        printf("Your list is empty. So, please insert some value.\n");
    }
    else
    {
        struct node* tmp = start;
        struct node* last = start;

        while (last->next != start)
        {
            last = last->next;
        }

        last->next = start->next;
        start = start->next;
        free(tmp);
    }
    return start;
}

struct node* Delete_any(int index, struct node* start)
{
    if (start == NULL)
    {
        printf("Create a linked list first\n");
    }
    else
    {
        if (index == 0)
        {
            return Delete_begin(start);
        }
        else
        {
            struct node* tmp = start;
            struct node* prev = NULL;
            int count = 0;

            while (count != index && tmp->next != start)
            {
                prev = tmp;
                tmp = tmp->next;
                count++;
            }

            if (count == index)
            {
                prev->next = tmp->next;
                free(tmp);
            }
            else if (tmp->next == start)
            {
                printf("This index is not available.\n");
            }
        }
    }
    return start;
}

struct node* Delete_all(struct node* start)
{
    if (start == NULL)
    {
        printf("Your list is empty. So, please insert some value.\n");
    }
    else
    {
        struct node* tmp = start;
        struct node* current = start;

        do
        {
            tmp = current;
            current = current->next;
            free(tmp);
        } while (current != start);

        start = NULL;
    }
    return start;
}

void Display(struct node* start)
{
    if (start == NULL)
    {
        printf("You have no data.\n");
    }
    else
    {
        struct node* m = start;

        do
        {
            printf("%d\n", m->val);
            m = m->next;
        } while (m != start);
    }
}