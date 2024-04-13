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
struct node* Delete_num(int num, struct node* start);
struct node* Delete_all(struct node* start);

void Counter(struct node* start);
void Find(int a, struct node* start);
struct node* Ascending(struct node* start);
struct node* Reverse(struct node* start);
struct node* Descending(struct node* start);

void Display(struct node* start);

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

struct node* Delete_num(int num, struct node* start)
{
    if (start == NULL)
    {
        printf("Your list is empty. So, please insert some value.\n");
    }
    else
    {
        struct node* temp = start;
        struct node* prev = NULL;
        struct node* last = start;
        int count = 0, q = 0, n = 0;

        while (last->next != start)
        {
            if (last->val != num)
            {
                count++;
            }
            else if (last->val == num)
            {
                printf("This number also present in index no %d .\n", count);
                count++;
                q++;
            }
            n++;
            last = last->next;
        }

        if (last->val == num)
        {
            printf("This number also present in index no %d .\n", count);
            count++;
            q++;
        }
        else if (last->next == start && q == 0)
        {
            printf("This number is not available.\n");
        }

        if (q != 0)
        {
            if (q == 1)
            {
                while (temp->val == num)
                {
                    temp = temp->next;
                    start = Delete_begin(start);
                }
                prev = start;

                while (prev->next != start)
                {
                    if (temp->val != num)
                    {
                        prev = temp;
                        temp = temp->next;
                    }
                    else if (temp->val == num)
                    {
                        prev->next = temp->next;
                        free(temp);
                        temp = prev;
                    }
                }

                if (prev->val == num)
                {
                    start = Delete_end(start);
                }
            }
            else
            {
                printf("You have total %d same numbers.\n", q);
                printf("If you delete one value then enter '1'\nIf you delete all values then enter '0'\n");
                int a;
                scanf("%d", &a);

                switch (a)
                {
                case 1:
                {
                    printf("Which index value you want to delete\n");
                    int b;
                    scanf("%d", &b);
                    start = Delete_any(b, start);
                    break;
                }
                case 0:
                {
                    while (temp->val == num)
                    {
                        temp = temp->next;
                        start = Delete_begin(start);
                    }
                    prev = start;

                    while (prev->next != start)
                    {
                        if (temp->val != num)
                        {
                            prev = temp;
                            temp = temp->next;
                        }
                        else if (temp->val == num)
                        {
                            prev->next = temp->next;
                            free(temp);
                            temp = prev;
                        }
                    }

                    if (prev->val == num)
                    {
                        start = Delete_end(start);
                    }
                    break;
                }
                }
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

void Counter(struct node* start)
{
    if (start == NULL)
    {
        printf("Your list is empty. So, please insert some value.\n");
    }
    else
    {
        struct node* tmp = start;
        int count = 1;

        while (tmp->next != start)
        {
            count++;
            tmp = tmp->next;
        }
        printf("There are %d elements.\n", count);
    }
}

void Find(int a, struct node* start)
{
    if (start == NULL)
    {
        printf("Your list is empty. So, please insert some value.\n");
    }
    else
    {
        struct node* tmp = start;
        int count = 0, q = 0;

        while (tmp->next != start)
        {
            if (tmp->val != a)
            {
                count++;
            }
            else if (tmp->val == a)
            {
                printf("This number also present in index no %d.\n", count);
                count++;
                q++;
            }
            tmp = tmp->next;
        }

        if (tmp->val == a)
        {
            printf("This number also present in index no %d.\n", count);
            q++;
        }
        else if (tmp->next == start && q == 0)
        {
            printf("This number is not available.\n");
        }
    }
}

struct node* Ascending(struct node* start)
{
    struct node* tmp = start;
    struct node* m = start;
    int a;

    while (m->next != start)
    {
        tmp = start;

        while (tmp->next != start)
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

struct node* Reverse(struct node* start)
{
    if (start == NULL)
    {
        printf("You have no elements.\n");
    }
    else
    {
        struct node* m = start;
        struct node* n = NULL;
        struct node* o = NULL;
        struct node* p = start;

        while (p->next != start)
        {
            o = p->next;
            p->next = n;
            n = p;
            p = o;
        }
        p->next = n;
        start = p;
        m->next = start;
    }
    return start;
}

struct node* Descending(struct node* start)
{
    start = Ascending(start);
    start = Reverse(start);
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