#include"singlecircularlinklist.h"

int main(){
    struct node*start = NULL;
    int choice, value;
    do {
        printf("\nCircular Queue Menu\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:{
                printf("Enter value to enqueue: ");
                scanf("%d", &value);
                start = Insert_at_end(value, start);
                break;
            }
            case 2:{
                start = Delete_begin(start);
                break;
            }
            case 3:{
                Display(start);
                break;
            }
            case 4:{
                printf("Exiting the program.\n");
                exit(EXIT_SUCCESS);
                break;
            }
            default:{
                printf("Invalid choice. Please enter a valid option.\n");
            }
        }
    } while (choice != 4);
}