#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rand_bound()
{
    int l_bound = 10;
    int u_bound = 100;

    int width = (u_bound - l_bound) + 1;
    int val = 0;
    val = rand()%width + l_bound;
    return val;
}

int main(void)
{

/* Random number basic code */

printf("%d\n", rand());
printf("%d\n", rand());
printf("RAND_MAX: %D\n", RAND_MAX); // 2^32/2-1
printf("%d\n",rand_bound());
printf("%d\n", rand_bound());

/*  After seeding */

printf("After seeding: \n");

srand(42);

printf("%d\n", rand());
printf("%d\n", rand());

/* Dynamic 1D array to store 12 numbers */

int *ptr_1D = NULL; // Initialise pointer to integer
ptr_1D = (int *)malloc(12*sizeof(int)); // Allocate dynamic memory and assign base address to the pointer ptr_1D

for (int i = 0; i < 12; i++)
{
    ptr_1D[i] = rand_bound();
}

printf("ptr_1D: ");
for(int i = 0; i < 12; i++)
{
    printf("%d ", ptr_1D[i]);
}
printf("\n");

/* Dynamic 2D array; 3 x 4; random elements */

int **ptr_2D = NULL; // Initialise a double pointer used to store the base addresses of rows
ptr_2D = (int**)malloc(3*sizeof(int*)); // Allocates memory for three integer pointers representing rows

for(int i = 0; i < 3; i++)
{
    ptr_2D[i] = (int*)malloc(4*sizeof(int)); // Allocates memory for an array of four integers (columns)
    // 3 arrays of 4 elements each
}

for(int r = 0; r < 3; r++)
  for(int c = 0; c < 4; c++)
  {
    ptr_2D[r][c] = rand_bound();
  }
printf("ptr_2D: \n");

for(int r = 0; r<3; r++)
{
    for(int c = 0; c<4; c++)
    {
        printf("%3d ", ptr_2D[r][c]);
    }
    printf("\n");
}
/* Free the memory */
free(ptr_1D);

for(int i = 0; i < 3; i++)
  free(ptr_2D[i]);
free(ptr_2D);
}




