/* Circular Queue: Implementation using Arrays */
#include <stdio.h>
#include <stdlib.h>

/* Global Variable Declarations */

int Q_size = 3;
int Q_head = -1; // Indexes the front element
int Q_tail = -1; // Points to the last element

/* Queue operations */
void display(int[]);
void ENQUEUE(int[], int);
void DEQUEUE(int[]);
void PEEK(int[]);

int isQ_EMPTY();
int isQ_FULL();

int main(void)
{
    int Q[Q_size];
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

            printf("T: %d H: %d\n", Q_tail, Q_head);
            display(Q);

            break;

        case 'I':
            printf("Enter element to insert: ");
            scanf("%d", &x);

            printf("T: %d H: %d\n", Q_tail, Q_head);
            ENQUEUE(Q, x);

            break;

        case 'D':
            printf("T: %d H: %d\n", Q_tail, Q_head);
            DEQUEUE(Q);

            break;

        case 'P':
            printf("T: %d H: %d\n", Q_tail, Q_head);
            PEEK(Q);

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

void display(int Q[])
{
    /* First check whether the Queue is empty or not */
    /* If not empty, start printing from head until i!=tail. 
    Make the increment cyclic, so mod the increment with Q_size. 
    Print the tail separately. */

    if (isQ_EMPTY())
        printf("The queue is empty. \n");
    else
    {
        int i = Q_head;
        while (1)
        {
            printf("%d ", Q[i]);
            i = (i + 1) % Q_size;
            if (i == (Q_tail + 1) % Q_size)
                break; // Exit the loop after printing the last element
        }
        printf("\n");
    }
    return;
}

void ENQUEUE(int Q[], int x)
{
    /* Check for overflow */
    if (isQ_FULL())
    {
        printf("The queue is full. OVERFLOW. \n");
        return;
    }

    if (isQ_EMPTY())
    {
        Q_head = 0;
        Q_tail = 0;
    }
    else
    {
        Q_tail = (Q_tail + 1) % Q_size;
    }

    Q[Q_tail] = x;

    /* Increment the tail but preserve the cyclic nature. */
    return;
}

 
void DEQUEUE(int Q[])
{
    /* Check Underflow */
    if(isQ_EMPTY())
    {
    printf("The queue is empty. UNDERFLOW. \n");
    return;
    }
    int val = Q[Q_head];
    if (Q_head == Q_tail)
    {
        Q_head = -1;
        Q_tail = -1;
    }
    else {
        Q_head = (Q_head + 1) % Q_size;
    }
    printf("Deleted: %d\n", val);
    return;
    /* Remove the item pointed by head, and increment head cyclically. */
    /* Store the deleted item in another variable val. */
    /* If head and tail were same, then there was only one element
     and after deleting, the queue becomes empty.*/
     /* Otherwise increment the head cyclically */
    /* Print the value deleted */
    
}

void PEEK(int Q[])
{
    /* Return the next value which will be deleted. */
    /* This is pointed by head. */
    /* First check whether the queue is empty. */

    if(isQ_EMPTY())
    {
        printf("The queue is empty. UNDERFLOW.");
        return;
    }
    else
    {
        printf("The next value which will be deleted is %d: ", Q[Q_head]);
    }
    
    /* Print the value to delete next. */
    return;

}

int isQ_EMPTY()
{
    /* Check whether head is -1. 
    Return 1 or 0 based on the condition. */

    if(Q_head==-1)
    return 1;
    else
    return 0;


}

int isQ_FULL()
{
    /* Whenever we want to insert an element,
    we increment the tail, and store the value. */
    /* Check whether the next location to insert collides with head in a cyclic manner. */
    /* (tail + 1) % size == head */
    
    if((Q_tail+1)%Q_size==Q_head)
    return 1;
    else
    return 0;
    

}
