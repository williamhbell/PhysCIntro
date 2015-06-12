/* W. H. Bell
** This program demonstrates usage of the standard input and standard 
** output together with if, switch and do-while.
*/

#include <stdio.h>

/* Function predeclarations */
void numFingers(int);
void pickColour(void);
int quitTime(void);

int main() {
  do {
    numFingers(3); /* Check an input number against the value provided. */
    printf("\n");
    pickColour(); /* Check an input character */
    printf("\n");
  } while (!quitTime()); /* Loop until ready to quit. */
  return 0;
}

/* A function to check an input number against the number provided */
void numFingers(int answer) {
  int fingers;

  printf("\n How many fingers am I holding up?\n");
  scanf("%d",&fingers); /* Read the number from the standard in */
  getchar(); /* Collect the new line */

  if(fingers==answer) { /* Test the value against the answer */
    printf("\t Correct!\n");
  }
  else if(fingers>10 || fingers<0) { /* Check the value is in range */
    printf("\t That is not possible with two hands!\n");
  }
  else { /* Report a wrong answer */
    printf("\t Wrong.  Try again.\n");
  }
}

/* A function to test an input character and provide a repose where
** implemented. */
void pickColour(void) {
  char colourFlag;

  printf("\n Pick a colour by its first letter.  (E.g. black => b)\n");
  scanf("%c",&colourFlag); /* Read a character from the standard in */
  getchar(); /* Collect the new line */

  /* Check the character value against {y, g, b, and r}. */
  switch (colourFlag) {
  case 'y' : printf(" Custard is yellow.  Best served hot with apple pie.\n"); break;
  case 'g' : printf(" Green blades of grass waving in the wind.\n"); break;
  case 'b' : printf(" As black as the nights sky on a cloudy winters night.\n"); break;
  case 'r' : printf(" Fast cars and hot metal.\n"); break;
  default : printf(" That colour does not sound poetic.\n"); break;
  }
}

int quitTime(void) {
  char quitAnswer;

  printf("\n Would you like to quit? (y/n)\n");
  scanf("%c",&quitAnswer); /* Read a character from the standard in */
  getchar(); /* Collect the new line */

  /* Test the character value and return the appropriate quit status */
  if(quitAnswer=='y' || quitAnswer=='Y') {
    return 1;
  }
  else {
    return 0;
  } 
}
