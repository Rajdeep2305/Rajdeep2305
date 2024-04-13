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
struct node*Delete_num(int num,struct node*start);
struct node*Delete_all(struct node*start);

void Counter(struct node*start);
void Find(int a, struct node*start);
struct node*Ascending(struct node*start);
struct node*Reverse(struct node*start);
struct node*Descending(struct node*start);

void Display(struct node*start);

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

struct node*Delete_num(int num,struct node*start)
{
    if(start == NULL)
    {
        printf("Your list is empty. So, please insert some value.");
    }
    else
    {
        struct node *temp;
        temp = start;
        int count = 0, q = 0, n = 0;
        while (temp->next != NULL)
        {
            if (temp->val != num)
            {
                count++;
            }
            else if (temp->val == num)
            {
                printf("This number also present in index no %d .\n", count);
                count++;
                q++;
            }
            n++;
            temp = temp->next;
        }
        if (temp->val == num)
        {
            printf("This number also present in index no %d .\n", count);
            count++;
            q++;
        }
        else if (temp->next == NULL && q == 0)
        {
            printf("This number is not available.\n");
        }
            if (q != 0)
            {
                if( q == 1)
                {
                    struct node *tmp;
                    struct node *prev;
                    struct node *m;
                    m = start;
                    while (m->val == num)
                    {
                        m = m->next;
                        Delete_begin(start);
                    }
                    tmp = prev = start;
                    while (prev->next != NULL)
                    {
                        if(start -> next == NULL)
                        {
                            free(start);
                            start = NULL;
                        }
                        else
                        {
                            if (tmp->val != num)
                            {
                                prev = tmp;
                                tmp = tmp->next;
                            }
                            else if (tmp->val == num)
                            {
                                prev->next = tmp->next;
                                free(tmp);
                                tmp = prev;
                            }
                        }
                    }
                    if (prev->val == num)
                    {
                        Delete_end(start);
                    }
                }
                else
                {
                    printf("You have total %d same numbers. ", q);
                    printf("If you delete one value then enter '1' \nIf you delete all values then enter'0' \n");
                    int a;
                    scanf("%d", &a);
                    switch (a)
                    {
                        case 1:
                        {
                            printf("Which index value you want to delete \n");
                            int b;
                            scanf("%d", &b);
                            Delete_any(b,start);
                            break;
                        }
                        case 0:
                        {
                            struct node *tmp;
                            struct node *prev;
                            struct node *m;
                            m = start;
                                while (m->val == num)
                                {
                                    m = m->next;
                                    Delete_begin(start);
                                }
                                tmp = prev = start;
                                while (prev->next != NULL)
                                {
                                    if(start -> next == NULL)
                                    {
                                        free(start);
                                        start = NULL;
                                    }
                                    else
                                    {
                                        if (tmp->val != num)
                                        {
                                            prev = tmp;
                                            tmp = tmp->next;
                                        }
                                        else if (tmp->val == num)
                                        {
                                            prev->next = tmp->next;
                                            free(tmp);
                                            tmp = prev;
                                        }
                                    }
                                }
                                if (prev->val == num)
                                {
                                    Delete_end(start);
                                }
                            break;
                        }
                    }
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

void Counter(struct node*start)
{
    if(start == NULL)
    {
        printf("Your list is empty. So, please insert some value.");
    }
    else
    {
        struct node *tmp;
        tmp = start;
        int count = 1;
        while (tmp->next != NULL)
        {
            count++;
            tmp = tmp->next;
        }
        printf("There have only %d elements.\n", count);
    }
}

void Find(int a, struct node*start)
{
    if(start == NULL)
    {
        printf("Your list is empty. So, please insert some value.");
    }
    else
    {
        struct node *tmp;
        tmp = start;
        int count = 0, q = 0;
        while (tmp->next != NULL)
        {
            if (tmp->val != a)
            {
                count++;
            }
            else if (tmp->val == a)
            {
                printf("This number also present in index no %d .\n", count);
                count++;
                q++;
            }
            tmp = tmp->next;
        }
        if (tmp->val == a)
        {
            printf("This number also present in index no %d .\n", count);
            q++;
        }
        else if (tmp->next == NULL && q == 0)
        {
            printf("This number is not available.\n");
        }
    }
}

struct node*Ascending(struct node*start)
{
    struct node *tmp;
    struct node *m;
    tmp = m = start;
    int a;
    while (m->next != NULL)
    {
        tmp = start;
        while (tmp->next != NULL)
        {
            if (tmp->val > tmp->next->val)
            {
                a = tmp->val;
                tmp->val = tmp->next->val;
                tmp->next->val = a;
            }
            tmp = tmp->next;
        }
        m = m->next;
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

struct node*Descending(struct node*start)
{
    start = Ascending(start);
    start = Reverse(start);
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