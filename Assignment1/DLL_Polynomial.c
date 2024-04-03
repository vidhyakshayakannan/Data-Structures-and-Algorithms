#include <stdio.h>
#include <stdlib.h>

/* Global Variable Declarations */
struct node
{
  int coeff;
  int degree;
  struct node *prev;
  struct node *next;
};

/* List operations */
void printList(struct node *);
void LIST_APPEND(struct node **, int, int); // Inserting a new last element.
void addPolynomials(struct node *, struct node *, struct node **);
struct node *createNode(int, int); // Creates a new node and initialize the key.

int main(void)
{
  struct node *p_head1 = NULL;
  LIST_APPEND(&p_head1, 5, 3);
  LIST_APPEND(&p_head1, 4, 2);
  LIST_APPEND(&p_head1, 6, 1);

  printf("Polynomial P1:\n");
  printList(p_head1);

  struct node *p_head2 = NULL;
  LIST_APPEND(&p_head2, 6, 5);
  LIST_APPEND(&p_head2, 3, 2);
  LIST_APPEND(&p_head2, 4, 1);

  printf("Polynomial P2:\n");
  printList(p_head2);

  struct node *result = NULL;
  addPolynomials(p_head1, p_head2, &result);

  printf("Result of polynomial addition (P3):\n");
  printList(result);

  return 0;
}

void printList(struct node *L_head)
{
  if (L_head == NULL)
  {
    printf("List is empty\n");
  }
  else
  {
    printf("List elements:\n");
    struct node *tmpHead = L_head;

    while (tmpHead != NULL)
    {
      printf("%dx^%d ", tmpHead->coeff, tmpHead->degree);
      tmpHead = tmpHead->next;
    }
    printf("\n");
  }
}

struct node *createNode(int coeff, int degree)
{
  struct node *newNode = (struct node *)malloc(1 * sizeof(struct node));
  newNode->coeff = coeff;
  newNode->degree = degree;
  newNode->prev = NULL;
  newNode->next = NULL;

  return newNode;
}

void LIST_APPEND(struct node **L_head, int coeff, int degree)
{
  struct node *newNode = createNode(coeff, degree);

  if (*L_head == NULL)
  {
    *L_head = newNode;
    return;
  }

  struct node *lastNode = *L_head;
  while (lastNode->next != NULL)
  {
    lastNode = lastNode->next;
  }

  lastNode->next = newNode;
  newNode->prev = lastNode;
}

void addPolynomials(struct node *p1, struct node *p2, struct node **result)
{
  while (p1 != NULL && p2 != NULL)
  {
    if (p1->degree == p2->degree)
    {
      LIST_APPEND(result, p1->coeff + p2->coeff, p1->degree);
      p1 = p1->next;
      p2 = p2->next;
    }
    else if (p1->degree > p2->degree)
    {
      LIST_APPEND(result, p1->coeff, p1->degree);
      p1 = p1->next;
    }
    else
    {
      LIST_APPEND(result, p2->coeff, p2->degree);
      p2 = p2->next;
    }
  }

  while (p1 != NULL)
  {
    LIST_APPEND(result, p1->coeff, p1->degree);
    p1 = p1->next;
  }

  while (p2 != NULL)
  {
    LIST_APPEND(result, p2->coeff, p2->degree);
    p2 = p2->next;
  }
}
