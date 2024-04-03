#include <stdio.h>
#include <stdlib.h>

/* Global Variable Declarations */
struct node
{
  int key;
  struct node *next;
};

struct node *L_head = NULL; // Empty List

/* List operations */
void printList();
void LIST_PREPEND(int);     // Inserting a new first element.
void LIST_APPEND(int);      // Inserting a new last element.
void LIST_INSERT(int, int); // inserts x next to y.
void LIST_DELETE(int);      // Find the node containing value and remove the node.
struct node *LIST_SEARCH(int); // Find the node containing the data.
struct node *createNode(int);  // Creates a new node and initialize the key.

int main(void)
{
  char option = '\0';

  printf("------------------------\n");
  printf("---Singly Linked List---\n");
  printf("Show: S\n");
  printf("LIST-PREPEND: 1\n");
  printf("LIST-APPEND: 2\n");
  printf("LIST-INSERT: 3\n");
  printf("LIST-DELETE: 4\n");
  printf("EXIT: E\n");
  printf("------------------------\n");

  while (1)
  {

    printf("Enter your option: ");
    scanf(" %c", &option);

    switch (option)
    {
    case 'S':
      printf("Displaying the list\n\n");
      printList();

      break;

    case '1':
      printf("Enter the element to prepend the list: ");
      int x = 0;
      scanf("%d", &x);
      LIST_PREPEND(x);

      break;

    case '2':
      printf("Enter the element to append the list: ");
      x = 0;
      scanf("%d", &x);
      LIST_APPEND(x);

      break;

    case '3':
      printf("Enter the value after:");
      int y = 0;
      scanf("%d", &y);

      x = 0;
      printf("Enter the new value to insert: ");
      scanf("%d", &x);

      LIST_INSERT(x, y); // insert x next to y

      break;

    case '4':
      printf("Enter the value to delete:");
      y = 0;
      scanf("%d", &y);

      LIST_DELETE(y); // Find the node containing y and delete it.

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

void printList()
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
      printf("[%p] --> %d --> %p\n",
             tmpHead, tmpHead->key, tmpHead->next);
      tmpHead = tmpHead->next;
    }
    printf("\n");
  }

  return;
}

struct node *createNode(int x)
{
  struct node *newNode = (struct node *)malloc(1 * sizeof(struct node));
  newNode->key = x;
  newNode->next = NULL;

  return newNode;
}

void LIST_PREPEND(int x)
{
  struct node *newNode = createNode(x);

  newNode->next = L_head;
  L_head = newNode;

  printf("First element: %d\n", L_head->key);
}

void LIST_APPEND(int x)
{
  struct node *newNode = createNode(x);

  if (L_head == NULL)
  {
    L_head = newNode;
    return;
  }

  struct node *lastNode = L_head;
  while (lastNode->next != NULL)
  {
    lastNode = lastNode->next;
  }

  lastNode->next = newNode;

  return;
}

void LIST_INSERT(int x, int y)
{
  struct node *yNode = LIST_SEARCH(y);

  if (yNode == NULL)
  {
    printf("The value %d do not exist in list\n", y);
    return;
  }

  struct node *newNode = createNode(x);
  newNode->next = yNode->next;
  yNode->next = newNode;

  return;
}

struct node *LIST_SEARCH(int y)
{
  struct node *yNode = L_head;

  if (L_head == NULL)
  {
    printf("Empty list\n");
    return NULL;
  }
  else
  {
    while (yNode != NULL && yNode->key != y)
    {
      yNode = yNode->next;
    }

    return yNode;
  }
}

void LIST_DELETE(int y)
{
  struct node *prevNode = NULL;
  struct node *currentNode = L_head;

  while (currentNode != NULL && currentNode->key != y)
  {
    prevNode = currentNode;
    currentNode = currentNode->next;
  }

  if (currentNode == NULL)
  {
    printf("The value %d does not exist\n", y);
    return;
  }

  if (prevNode != NULL)
  {
    prevNode->next = currentNode->next;
  }
  else
  {
    L_head = currentNode->next;
  }

  free(currentNode);

  return;
}
