#include <stdio.h>
#include <stdlib.h>

struct node
{
    int val;
    struct node *prev;
    struct node *next;
};

// Function to insert a node at the end of the doubly linked list
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

// Function to insert a node at the beginning of the doubly linked list
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

// Function to insert a node at any position in the doubly linked list
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

// Function to delete a node at the end of the doubly linked list
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

// Function to delete a node at the beginning of the doubly linked list
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

// Function to delete a node at any position in the doubly linked list
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

// Function to delete a node with a specific value from the doubly linked list
struct node *Delete_num(int num, struct node *start)
{
    struct node *temp = start;
    while (temp != NULL)
    {
        if (temp->val == num)
        {
            if (temp->prev != NULL)
            {
                temp->prev->next = temp->next;
            }
            if (temp->next != NULL)
            {
                temp->next->prev = temp->prev;
            }
            struct node *to_free = temp;
            temp = temp->next;
            free(to_free);
        }
        else
        {
            temp = temp->next;
        }
    }
    return start;
}

// Function to delete all nodes in the doubly linked list
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

// Function to count the number of nodes in the doubly linked list
void Counter(struct node *start)
{
    int count = 0;
    struct node *temp = start;
    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    printf("Number of nodes: %d\n", count);
}

// Function to find a specific value in the doubly linked list
void Find(int a, struct node *start)
{
    struct node *temp = start;
    int index = 0;
    while (temp != NULL)
    {
        if (temp->val == a)
        {
            printf("Value %d found at index %d.\n", a, index);
        }
        temp = temp->next;
        index++;
    }
}

// Function to arrange the doubly linked list in ascending order
struct node *Ascending(struct node *start)
{
    if (start == NULL || start->next == NULL) {
        return start; // Already sorted or empty list
    }

    struct node *current = start;
    struct node *index = NULL;
    int temp;

    while (current != NULL) {
        index = current->next;

        while (index != NULL) {
            if (current->val > index->val) {
                temp = current->val;
                current->val = index->val;
                index->val = temp;
            }
            index = index->next;
        }
        current = current->next;
    }
    return start;
}

// Function to reverse the doubly linked list
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

// Function to arrange the doubly linked list in descending order
struct node *Descending(struct node *start)
{
    if (start == NULL || start->next == NULL) {
        return start; // Already sorted or empty list
    }

    struct node *current = start;
    struct node *index = NULL;
    int temp;

    while (current != NULL) {
        index = current->next;

        while (index != NULL) {
            if (current->val < index->val) {
                temp = current->val;
                current->val = index->val;
                index->val = temp;
            }
            index = index->next;
        }
        current = current->next;
    }
    return start;
}

// Function to display the doubly linked list
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
            printf("%d ", temp->val);
            temp = temp->next;
        }
        printf("\n");
    }
}