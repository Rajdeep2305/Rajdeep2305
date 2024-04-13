#include <stdio.h>
#include <stdlib.h>

struct node
{
    int val;
    struct node *prev;
    struct node *next;
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

struct node* Insert_at_end(int val, struct node* start) 
{
    struct node *tmp, *last;
    tmp = (struct node *)malloc(sizeof(struct node));
    if (tmp == NULL) 
    {
        printf("Memory allocation failed\n");
        return start;
    }
    tmp->val = val;
    tmp->next = start;  
    if (start == NULL) 
    {
        tmp->prev = tmp;
        start = tmp;
    } else {
        last = start->prev;  
        last->next = tmp;
        tmp->prev = last;
        start->prev = tmp;  
    }
    return start;
}

void Display(struct node* start) 
{
    if (start == NULL) 
    {
        printf("You have no data..\n");
        return;
    }
    struct node* current = start;
    do {
        printf("%d\n", current->val);
        current = current->next;
    } while (current != start);
}

struct node* Insert_at_begin(int val, struct node* start) 
{
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    if (new_node == NULL) 
    {
        printf("Memory allocation failed\n");
        return start;
    }
    new_node->val = val;
    new_node->next = start;
    new_node->prev = NULL;
    if (start == NULL) 
    {
        new_node->prev = new_node;  
        start = new_node;  
    }
    else 
    {
        start->prev->next = new_node;
        new_node->prev = start->prev;
        start->prev = new_node;  
        start = new_node;  
    }
    return start;
}

struct node* Insert_at_any(int val, int index, struct node* start) 
{
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    if (new_node == NULL) 
    {
        printf("Memory allocation failed\n");
        return start;
    }
    new_node->val = val;
    if (start == NULL) 
    { 
        new_node->next = new_node->prev = new_node;
        start = new_node;
    } 
    else 
    {
        struct node* temp = start;
        for (int i = 0; i < index - 1; ++i) 
        {
            temp = temp->next;
            if (temp == start) 
            {
                printf("Index out of bounds\n");
                free(new_node);
                return start;
            }
        }
        new_node->next = temp->next;
        new_node->prev = temp;
        temp->next->prev = new_node;
        temp->next = new_node;
    }
    return start;
}

struct node* Delete_end(struct node* start) 
{
    if (start == NULL) 
    {
        printf("List is empty\n");
        return NULL;
    }
    struct node* temp = start->prev; 
    start->prev = temp->prev;
    temp->prev->next = start;
    free(temp);
    if (start->prev == start) 
    {
        free(start);
        return NULL;
    }
    return start;
}

struct node* Delete_begin(struct node* start) 
{
    if (start == NULL) 
    {
        printf("List is empty\n");
        return NULL;
    }
    struct node* temp = start; 
    start = start->next;
    start->prev = temp->prev;
    temp->prev->next = start;
    free(temp);
    if (start == start->next) 
    { 
        free(start);
        return NULL;
    }
    return start;
}

struct node* Delete_any(int index, struct node* start) 
{
    if (start == NULL) 
    {
        printf("List is empty\n");
        return NULL;
    }
    struct node* temp = start;
    for (int i = 0; i < index; ++i) 
    {
        temp = temp->next;
        if (temp == start) 
        {
            printf("Index out of bounds\n");
            return start;
        }
    }
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    free(temp);
    if (start == start->next) 
    {
        free(start);
        return NULL;
    }
    return start;
}

struct node* Delete_all(struct node* start) 
{
    if (start == NULL) 
    {
        printf("Your list is empty. So, please insert some value.\n");
        return NULL;
    }
    struct node* current = start;
    struct node* next_node;
    do {
        next_node = current->next; 
        free(current); 
        current = next_node; 
    } while (current != start);
    return NULL; 
}
