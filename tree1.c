#include<stdio.h>
#include<stdlib.h>

struct tree{
    int val;
    struct tree*left;
    struct tree*right;
};

struct tree*right(struct tree*m, struct tree*node);
struct tree*left(struct tree*m, struct tree*node);
struct tree*Insert(int value,struct tree*root);

int main()
{
    struct tree*root = NULL;
    char pass;
    while(pass != 's' || pass != 'S')
    {
        printf("Enter 's' or 'S' for start the program: ");
        pass = getchar();
        if(pass == 's' || pass == 'S')
        {
            printf("\n");
            while(1)
            {
                printf("Enter 'i' or 'I' for insert value. \n");
                printf("Enter 'x' or 'X' for exit the program. \n");
                char key;
                key = getchar();
                key = getchar();
                switch(key)
                {
                    case 'i':
                    case 'I':
                    {
                        if(root == NULL)
                        {
                            printf("Enter the value of Root: ");
                            int a;
                            scanf("%d",&a);
                            root = Insert(a,root);
                        }
                        else
                        {
                            printf("Enter the value: ");
                            int a;
                            scanf("%d",&a);
                            root = Insert(a,root);
                        }
                        break;
                    }
                    case 'x':
                    case 'X':
                    {
                        exit(EXIT_SUCCESS);
                        break;
                    }
                }
                printf("\n");
            }
        }
        else
        {
            printf("Enter the currect passward\n");
        }
        scanf("%c",&pass);
    }   
    return 0;
}

struct tree*left(struct tree*m, struct tree*node)
{
    m = right(m,node);
    return m;
}

struct tree*right(struct tree*m, struct tree*node)
{
    if(m -> val > node -> val)
    {
        if(m -> left == NULL)
        {
            m -> left = node;
        }
        else
        {
            m = left(m,node);
        }
    }
    else if(m -> val < node -> val)
    {
        if(m -> right == NULL)
        {
            m -> right = node;
        }
        else
        {
            m = right(m,node);
        }
    }
    else
    {
        printf("Please give an unique value.");
    }
    return m;
}

struct tree*Insert(int value,struct tree*root)
{
    struct tree *node;
    node = (struct tree*)malloc(sizeof(struct tree));
    node -> val = value;
    node -> left = NULL;
    node -> right = NULL;
    if(root == NULL)
    {
        root = node;
    }
    else 
    {
        struct tree*m = root;
        if(m -> val > node -> val)
        {
            if(m -> left == NULL)
            {
                m -> left = node;
            }
            else
            {
                m = left(m,node);
            }
        }
        else if(m -> val < node -> val)
        {
            if(m -> right == NULL)
            {
                m -> right = node;
            }
            else
            {
                m = right(m,node);
            }
        }
        else
        {
            printf("Please give an unique value.");
        }
    }
    return root;
}