// 3. Write a program in C to reverse a singly linked list. 

#include<stdio.h>
#include<stdlib.h>

struct node
{
    int val;
    struct node*next;
};

struct node*Insert_at_end(int val, struct node*start);
struct node*Reverse(struct node*start);
void Display(struct node*start);

int main()
{
    struct node *list = NULL;
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
    printf("reverse.\n");
    list = Reverse(list);

    printf("Display\n");
    Display(list);            
    
    printf("Your program will be saved.\n Have a Good Day.");
    exit(EXIT_SUCCESS);
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

struct node*Reverse(struct node*start)
{
    if (start == NULL)
    {
        printf("You have no elements\n");
    }
    else
    {
        struct node *m;
        struct node *n;
        struct node *o;
        struct node *p;
        m = n = o = p = start;
        while (o->next != NULL)
        {
            o = o->next;
            m->next = n;
            n = m;
            m = o;
        }
        o->next = n;
        start = o;
        p->next = NULL;
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