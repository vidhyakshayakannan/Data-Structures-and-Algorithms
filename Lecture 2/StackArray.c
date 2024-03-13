/* Stack Implementation using Arrays */
#include <stdio.h>
#include <stdlib.h>

/* Global Variable Declarations */

int S_size = 5;
int S_top = -1;

/* Stack operations */
void display(int[]);
void PUSH(int[], int);
int POP(int[]);
int STACK_EMPTY(int[]);
void PEEK(int[]);

int main(void)
{
    int S[5] = {};
    int x = 0;

    char option = '\0';

    printf("-----------------\n");
    printf("---STACK  Menu---\n");
    printf("Show: S\n");
    printf("PUSH: I\n");
    printf("POP : D\n");
    printf("PEEK : L\n");
    printf("EXIT: E\n");
    printf("-----------------\n");

    while (1)
    {

        printf("Enter your option: ");
        scanf(" %c", &option);

        switch (option)
        {
        case 'S':
            printf("Displaying Stack\n");
            display(S);

            break;

        case 'I':
            printf("Enter element to insert: ");
            scanf("%d", &x);
            PUSH(S, x);

            break;

        case 'D':
            x = POP(S);

            break;

        case 'L':
            PEEK(S);
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

void display(int S[])
{
    /* First, check whether stack is empty (underflow). */
    /* If it is not empty, then print the contents of stack */
    if (S_top == -1)
    printf("There are no elements to display. The stack is empty. UNDERFLOW. \n");
    else
    { for(int i = 0; i<=5; i++)
        {
            printf("%d ", S[i]);
        }
        printf("\n"); }
}

void PUSH(int S[], int x)
{
    /* Check whether stack is full (overflow). */
    /* If not full, we can push the data. */
    if(S_top == S_size)
    printf("Cannot insert element. The stack is full. OVERFLOW. \n");
    else {
        S_top += 1;
        S[S_top] = x;
    }

}

int STACK_EMPTY(int S[])
{
    /* Check S_top is -1 */
    if(S_top==-1) {
        printf("The stack is empty. UNDERFLOW.");
        return 1; }
    else {
        return 0; }

}

int POP(int S[])
{
    /* Check whether stack is empty (underflow) */
    /* If not empty, then we can pop the top element */
    /* Note: The top element is present at S_top - 1 */

    if (STACK_EMPTY(S)==1)
    {
        printf("Cannot pop element. The stack is empty. UNDERFLOW."); }
    else
    {
        S[S_top] = 0;
        S_top = S_top - 1; 
    }
}

void PEEK(int S[])
{
    if(STACK_EMPTY(S))
    printf("The stack is empty. There is no top element.");
    else
    printf("The top element is %d. \n", S[S_top]);

    /* Check whether stack is empty. */
    /* If not empty, then print then print the top element */
  
}
