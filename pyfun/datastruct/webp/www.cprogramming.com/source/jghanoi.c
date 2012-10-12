#include <stdio.h>
// We will be moving from peg 0 to peg 3.
int peg[8] = {};
#define MASK(A,B) ((A) & (1 << (B)))
void hanoi (int numplates);
int main (void)
{
 int numPlates;
 
 printf ("How many plates in the tower? ");
 
 // Obfuscation station. 
 for (; !scanf ("%d", &numPlates);) for (; getchar() != '\n';);
 hanoi (numPlates);
 return 0;
}
void hanoi (int numPlates)
{
 unsigned int count = 1;
 unsigned int currPlate;
 
 for (; !MASK(count,numPlates); count++)
 {
  // Determine which plate to move...
  for (currPlate = 0; !MASK(count, currPlate); currPlate++);
  printf ("Plate moved from %d ", peg[currPlate]); 
  // Determine which direction to move plate.
  // And moves it.
  if ((numPlates ^ currPlate) & 1)
  {
   peg[currPlate] = (peg[currPlate] + 2) % 3;
   printf ("to %d.\n", peg[currPlate]);
  }
  else
  {
   peg[currPlate] = (peg[currPlate] + 1) % 3;
   printf ("to %d.\n", peg[currPlate]);
  }
 }
 return;
} 
  
