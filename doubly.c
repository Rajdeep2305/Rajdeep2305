#include <stdio.h>
#include <stdlib.h>

struct node
{
    int val;
    struct node *prev;
    struct node *next;
};

struct node *Insert_at_end(int val, struct node *start)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->val = val;
    new_node->next = NULL;
    new_node->prev = NULL;

    if (start == NULL)
    {
        start = new_node;
    }
    else
    {
        struct node *temp = start;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = new_node;
        new_node->prev = temp;
    }
    return start;
}

struct node *Insert_at_begin(int val, struct node *start)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->val = val;
    new_node->next = start;
    new_node->prev = NULL;

    if (start != NULL)
    {
        start->prev = new_node;
    }
    return new_node;
}

struct node *Insert_at_any(int val, int index, struct node *start)
{
    struct node *new_node = (struct node *)malloc(sizeof(struct node));
    new_node->val = val;
    new_node->next = NULL;
    new_node->prev = NULL;

    if (start == NULL)
    {
        start = new_node;
    }
    else
    {
        struct node *temp = start;
        int i = 0;
        while (i < index && temp != NULL)
        {
            temp = temp->next;
            i++;
        }

        if (temp != NULL)
        {
            new_node->next = temp;
            new_node->prev = temp->prev;
            temp->prev = new_node;
            if (new_node->prev != NULL)
            {
                new_node->prev->next = new_node;
            }
            else
            {
                start = new_node;
            }
        }
        else
        {
            printf("Invalid index.\n");
            free(new_node);
        }
    }
    return start;
}

struct node *Delete_end(struct node *start)
{
    if (start == NULL)
    {
        printf("List is empty.\n");
    }
    else
    {
        struct node *temp = start;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        if (temp->prev != NULL)
        {
            temp->prev->next = NULL;
        }
        free(temp);
    }
    return start;
}

struct node *Delete_begin(struct node *start)
{
    if (start == NULL)
    {
        printf("List is empty.\n");
    }
    else
    {
        struct node *temp = start;
        start = start->next;
        if (start != NULL)
        {
            start->prev = NULL;
        }
        free(temp);
    }
    return start;
}

struct node *Delete_any(int index, struct node *start)
{
    if (start == NULL)
    {
        printf("List is empty.\n");
    }
    else
    {
        struct node *temp = start;
        int i = 0;
        while (i < index && temp != NULL)
        {
            temp = temp->next;
            i++;
        }

        if (temp != NULL)
        {
            if (temp->prev != NULL)
            {
                temp->prev->next = temp->next;
            }
            if (temp->next != NULL)
            {
                temp->next->prev = temp->prev;
            }
            free(temp);
        }
        else
        {
            printf("Invalid index.\n");
        }
    }
    return start;
}

struct node *Delete_all(struct node *start)
{
    while (start != NULL)
    {
        struct node *temp = start;
        start = start->next;
        free(temp);
    }
    return start;
}

struct node *Reverse(struct node *start)
{
    struct node *temp = NULL;
    struct node *current = start;

    while (current != NULL) {
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    if (temp != NULL) {
        start = temp->prev;
    }

    return start;
}

void Display(struct node *start)
{
    if (start == NULL)
    {
        printf("List is empty.\n");
    }
    else
    {
        printf("Doubly Linked List:\n");
        struct node *temp = start;
        while (temp != NULL)
        {
            printf("%d\n", temp->val);
            temp = temp->next;
        }
        printf("\n");
    }
}

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
                printf("1. Enter 'i' or 'I' for Insert any value.\n2. Enter 'e' or 'E' for erase any value.\n3. Enter 'd' or 'D' for display the list.\n4. Enter 'r' or 'R' for Reverse. \nEnter 'x' or 'X' for exit the program.\n");
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
                    case 'r':
                    case 'R':
                    {
                        printf("reverse.\n");
                        list = Reverse(list);
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
