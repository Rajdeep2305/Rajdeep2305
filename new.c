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