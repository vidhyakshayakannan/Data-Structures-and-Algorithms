#include <stdio.h>
#include <stdlib.h>

/* Global Variable Declarations */

struct node
{
    int data;
    struct node *next;
};

struct node *Q_head = NULL; // Pointer to the front element
struct node *Q_tail = NULL; // Pointer to the rear element

/* Queue operations */
void display();
void ENQUEUE(int);
void DEQUEUE();
void PEEK();

int isQ_EMPTY();

int main(void)
{
    int x = 0;
    char option = '\0';

    printf("-----------------\n");
    printf("---QUEUE  Menu---\n");
    printf("Show: S\n");
    printf("ENQUEUE: I\n");
    printf("DEQUEUE: D\n");
    printf("PEEK: P\n");
    printf("EXIT: E\n");
    printf("-----------------\n");

    while (1)
    {

        printf("Enter your option: ");
        scanf(" %c", &option);

        switch (option)
        {
        case 'S':
            printf("Displaying Queue\n\n");
            display();
            break;

        case 'I':
            printf("Enter element to insert: ");
            scanf("%d", &x);
            ENQUEUE(x);
            break;

        case 'D':
            DEQUEUE();
            break;

        case 'P':
            PEEK();
            break;

        case 'E':
            printf("Exit\n\n");
            exit(0);

        default:
            printf("Enter correct option\n\n");
        }
    }

    return 0;
}

void display()
{
    if (isQ_EMPTY())
    {
        printf("The queue is empty. \n");
    }
    else
    {
        struct node *current = Q_head;
        while (current != NULL)
        {
            printf("%d ", current->data);
            current = current->next;
        }
        printf("\n");
    }
}

void ENQUEUE(int x)
{
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->data = x;
    newNode->next = NULL;

    if (Q_tail == NULL)
    {
        Q_head = newNode;
        Q_tail = newNode;
    }
    else
    {
        Q_tail->next = newNode;
        Q_tail = newNode;
    }
}

void DEQUEUE()
{
    if (isQ_EMPTY())
    {
        printf("The queue is empty. UNDERFLOW. \n");
        return;
    }

    struct node *temp = Q_head;
    printf("Deleted: %d\n", temp->data);
    Q_head = Q_head->next;
    free(temp);

    if (Q_head == NULL)
    {
        Q_tail = NULL;
    }
}

void PEEK()
{
    if (isQ_EMPTY())
    {
        printf("The queue is empty. UNDERFLOW. \n");
        return;
    }

    printf("The next value which will be deleted is %d: ", Q_head->data);
}

int isQ_EMPTY()
{
    return Q_head == NULL;
}
