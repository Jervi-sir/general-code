#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

int main(void) {
  srand(time(NULL));
 time_t t;
 
  srand ((unsigned)time(&t));
  int r = rand() % 10 + 1;
  bool correct = false; 
  int guess; 
  int counter = 0; 

  while(!correct)
  {
    printf("Guess my number! "); 
    scanf("%d", &guess);
    getchar();

    if (guess < r) {
        printf("Your guess is too low. Guess again.\n");
    }
    else if (guess > r) { 
        printf("Your guess is too high. Guess again.\n");
    }
    else /* if (guess == r) */ {
        printf("You guessed correctly in %d tries! Congratulations!\n", counter); 
        correct = true; 
    }

    counter++;
  } /* while(!correct) */

  return 0;   
}