#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>

/* Global Variable Declarations */
struct node
{
  char data;
  struct node *prev;
  struct node *next;
};

/* Stack operations */
void push(struct node **top, char data);
char pop(struct node **top);
char peek(struct node *top);
bool is_empty(struct node *top);

/* Infix to Postfix conversion */
void infix_to_postfix(char *infix, char *postfix);

int precedence(char op);

int main(void)
{
  char infix[100], postfix[100];

  printf("Enter infix expression: ");
  scanf("%s", infix);

  infix_to_postfix(infix, postfix);

  printf("Postfix expression: %s\n", postfix);

  return 0;
}

void infix_to_postfix(char *infix, char *postfix)
{
  struct node *stack = NULL; // Stack to hold operators
  int i = 0, j = 0;

  while (infix[i] != '\0')
  {
    if (isalnum(infix[i]))
    {
      postfix[j++] = infix[i++];
    }
    else if (infix[i] == '(')
    {
      push(&stack, infix[i]);
      i++;
    }
    else if (infix[i] == ')')
    {
      while (!is_empty(stack) && peek(stack) != '(')
      {
        postfix[j++] = pop(&stack);
      }
      pop(&stack); // Discard the '('
      i++;
    }
    else
    {
      while (!is_empty(stack) && precedence(infix[i]) <= precedence(peek(stack)))
      {
        postfix[j++] = pop(&stack);
      }
      push(&stack, infix[i]);
      i++;
    }
  }

  while (!is_empty(stack))
  {
    postfix[j++] = pop(&stack);
  }

  postfix[j] = '\0'; // Null-terminate the postfix string
}

void push(struct node **top, char data)
{
  struct node *newNode = (struct node *)malloc(sizeof(struct node));
  newNode->data = data;
  newNode->prev = NULL;
  newNode->next = *top;

  if (*top != NULL)
  {
    (*top)->prev = newNode;
  }

  *top = newNode;
}

char pop(struct node **top)
{
  if (*top == NULL)
  {
    printf("Stack underflow!\n");
    exit(EXIT_FAILURE);
  }

  struct node *temp = *top;
  char data = temp->data;
  *top = (*top)->next;

  if (*top != NULL)
  {
    (*top)->prev = NULL;
  }

  free(temp);
  return data;
}

char peek(struct node *top)
{
  if (top == NULL)
  {
    printf("Stack is empty!\n");
    exit(EXIT_FAILURE);
  }
  return top->data;
}

bool is_empty(struct node *top)
{
  return top == NULL;
}

int precedence(char op)
{
  switch (op)
  {
  case '+':
  case '-':
    return 1;
  case '*':
  case '/':
    return 2;
  default:
    return 0;
  }
}
