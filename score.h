#include <stdio.h>
#include <stdbool.h>

int X_WINS = ( 'X' * 3 ); /* Requires three-in-a-row to win */ 
int O_WINS = ( 'O' * 3 );
int DRAW_AVERAGE = ( 'X' * 5 ) + ( 'O' * 4 ); /* total possible score after a full game */
int SCORE = 0;

enum OUTCOMES { None , Player_X , Player_O , Draw };

char SCORE_RESULT()
{
   /* Calculate all of the row/horizontal scores */
   
   int R_ONE = BOARD[1] + BOARD[2] + BOARD[3];
   int R_TWO = BOARD[4] + BOARD[5] + BOARD[6];
   int R_THR = BOARD[7] + BOARD[8] + BOARD[9];

   /* Calculate all of the column/vertical scores */
   int C_ONE = BOARD[1] + BOARD[4] + BOARD[7];
   int C_TWO = BOARD[2] + BOARD[5] + BOARD[8];
   int C_THR = BOARD[3] + BOARD[6] + BOARD[9];
   
   /* Calculate all of the diagonal scores */
   int TL_BR = BOARD[1] + BOARD[5] + BOARD[9]; // Top left -> bottom right
   int TR_BL = BOARD[3] + BOARD[5] + BOARD[7]; // Top right -> bottom left

   int BOARD_RESULTS[8] =  { R_ONE , R_TWO , R_THR, C_ONE , C_TWO , C_THR , TL_BR , TR_BL };

   size_t SIZE_RESULTS = sizeof( BOARD_RESULTS ) / sizeof( BOARD_RESULTS[0] );

   enum OUTCOMES result; /* default result should no conditions pass */

   SCORE = 0;
   for ( int i = 1 ; i < SIZE_BOARD ; i++ )
      SCORE += BOARD[i];

   result = ( SCORE >= DRAW_AVERAGE ) ? Draw : None ;

   for ( int i = 0 ; i < SIZE_RESULTS ; i++ ) {
   
      if ( X_WINS == BOARD_RESULTS[i] )
         result = Player_X;
         
      if ( O_WINS == BOARD_RESULTS[i] )
         result = Player_O;

   }

   return result;
}
