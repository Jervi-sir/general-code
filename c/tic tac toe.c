#include <stdio.h> 
int main() 
{ int i = 0; /* my main loop counter */
 int player = 0; /* represents a play */ 
 int turn = 0; /* How you select your square when it's your turn */ 
 int row = 0; /* a row for the squares */ 
 int column = 0; /* colomuns for the squares */ 
 int line = 0; /* check for winner */
  int victor = 0; 
  char board[3][3] = { /* The board */ {'1','2','3'}, {'4','5','6'}, {'7','8','9'} }; 
  
  for ( i = 0; i<9 && victor==0; i++) /* The loop for the game that ends if all nine moves are made */
   { /* as long as someone is not declared the victor prior */ 
   printf("\n"); 
   printf(" %c | %c | %c\n", board[0][0], board[0][1], board[0][2]); /* creates the top row */ 
   printf(" %c | %c | %c\n", board[1][0], board[1][1], board[1][2]); /* creates the middle row */ 
   printf(" %c | %c | %c\n", board[2][0], board[2][1], board[2][2]); /* creates the bottom row */ player = i%2 + 1; /* selects the player */ 
   do { 
   printf("\nPlayer %d select the number of the square where you want to place your %c: ", player,(player==1)?'X':'O'); scanf("%d", &turn); 
   row = --turn/3; /* Get row of square */ column = turn%3; /* Get column of square */ }
   while(turn<0 || turn>9 || board[row][column]>'9'); /* do while it is less than the max number of turns */ 
   board[row][column] = (player == 1) ? 'X' : 'O'; /* put player symbol in square */ 
   if((board[0][0] == board[1][1] && board[0][0] == board[2][2]) || /* Check for a winning diagonals*/ (board[0][2] == board[1][1] && board[0][2] == board[2][0])) 
   victor = player; 
   else for(line = 0; line <= 2; line ++) /* Check for a winning lines/columns*/ 
   if((board[line][0] == board[line][1] && board[line][0] == board[line][2])|| (board[0][line] == board[1][line] && board[0][line] == board[2][line])) 
   victor = player;
    }
     printf("\n"); 
   printf(" %c | %c | %c\n", board[0][0], board[0][1], board[0][2]); /* creates the top row */ 
   printf(" %c | %c | %c\n", board[1][0], board[1][1], board[1][2]); /* creates the middle row */ 
   printf(" %c | %c | %c\n", board[2][0], board[2][1], board[2][2]); /* creates the bottom row */ 
   if(victor==0) /* Display result message */ printf("\nIt's a cat scratch\n"); 
   else printf("\nWinner Winner Chicken Dinner Congrats, Player %d, YOU ARE THE WINNER!\n", victor);
    return 0;
     }