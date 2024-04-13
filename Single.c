//2. Write a C program to design a Singly Linked List and perform Insertion at end, Insertion at Beginning, Deletion at Begin, Deletion at End, Insertion at Index, Deletion at Index, Deletion of entire List and Display Linked List operation on it. 


#include<stdio.h>
#include<stdlib.h>

struct node
{
    int val;
    struct node*next;
};

struct node*Insert_at_end(int val, struct node*start);
struct node*Insert_at_begin(int val, struct node*start);
struct node*Insert_at_any(int val, int index, struct node*start);

struct node*Delete_end(struct node*start);
struct node*Delete_begin(struct node*start);
struct node*Delete_any(int index, struct node*start);
struct node*Delete_all(struct node*start);

void Display(struct node*start);

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

struct node*Insert_at_end(int val, struct node*start)
{
    struct node *tmp;
    tmp = (struct node *)malloc(sizeof(struct node));
    tmp->val = val;
    tmp->next = NULL;
    if (start == NULL)
    {
        start = tmp;
    }
    else
    {
        struct node *m;
        m = start;
        while (m -> next != NULL)
        {
            m = m -> next;
        }
        m->next = tmp;
    }
    return start;
}

struct node*Insert_at_begin(int val, struct node*start)
{
    struct node *tmp;
    tmp = (struct node *)malloc(sizeof(struct node));
    tmp -> val = val;
    tmp -> next = NULL;
    if (start == NULL)
    {
        start = tmp;
    }
    else
    {
        tmp -> next = start;
        start = tmp;
    }
    return start;
}

struct node*Insert_at_any(int val, int index, struct node*start)
{
    if(start == NULL)
    {
        Insert_at_end(val,start);
    }
    else
    {
        if (index == 0)
        {
            Insert_at_begin(val,start);
        }
        else
        {
            struct node *tmp;
            tmp = (struct node *)malloc(sizeof(struct node));
            tmp->val = val;
            tmp->next = NULL;
            if (start == NULL)
            {
                start = tmp;
            }
            else
            {
                struct node *p;
                p = start;
                int count = 0;
                while (count != (index - 1) && p->next != NULL)
                {
                    p = p->next;
                    count++;
                }
                tmp->next = p->next;
                p->next = tmp;
            }
        }
    }
    return start;
}

struct node*Delete_end(struct node*start)
{
    if(start == NULL)
    {
        printf("Your list is empty. So, please insert some value.");
    }
    else
    {
        if(start -> next != NULL)
        {
            struct node *tmp;
            struct node *prev;
            tmp = prev = start;
            while (tmp->next != NULL)
            {
                prev = tmp;
                tmp = tmp->next;
            }
            free(tmp);
            prev->next = NULL;
        }
        else if (start -> next == NULL)
        {
            free(start);
            start == NULL;
        }
    }
    return start;
}

struct node*Delete_begin(struct node*start)
{   
    if(start == NULL)
    {
        printf("Your list is empty. So, please insert some value.");
    }
    else
    {
        if(start -> next != NULL)
        {
            struct node *tmp;
            tmp = start;
            start = start->next;
            free(tmp);
        }
        else if(start -> next == NULL)
        {
            free(start);
            start == NULL;
        }
    }
    return start;
}
struct node*Delete_any(int index, struct node*start)
{
    struct node *tmp;
    struct node *prev;
    tmp = prev = start;
    int count = 0;
    if (start == NULL)
    {
        printf("Create a linked list first");
    }
    else
    {
        if (index == 0)
        {
            Delete_begin(start);
        }
        else
        {
            while (count != index && tmp->next != NULL)
            {
                count++;
                prev = tmp;
                tmp = tmp->next;
            }
            if (count == index)
            {
                prev->next = tmp->next;
                free(tmp);
            }
            else if (tmp->next == NULL)
            {
                printf("This index is not available.\n");
            }
        }
    }
    return start;
}

struct node*Delete_all(struct node*start)
{
    if(start == NULL)
    {
        printf("Your list is empty. So, please insert some value.");
    }
    else
    {
        struct node *tmp;
        struct node *prev;
        tmp = prev = start;
        while (start->next != NULL)
        {
            tmp = prev = start;
            while (tmp->next != NULL)
            {
                prev = tmp;
                tmp = tmp->next;
            }
            free(tmp);
            prev->next = NULL;
        }
        free(start);
        start = NULL;
    }
    return start;
}

void Display(struct node*start)
{
    if(start == NULL)
    {
        printf("You have no data..\n");
    }
    else
    {
        struct node*m;
        m = start;
        printf("%d\n", m -> val);
        while( m -> next != NULL)
        {
            m = m -> next;
            printf("%d\n", m -> val);
        }
    }
}