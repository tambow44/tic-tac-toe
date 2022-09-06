#include <stdio.h>
#include <stdlib.h>
#include "pause.h"
#include "player.h"
#include "board.h"
#include "score.h"

char play_again;
int result = 0;
int players_turn = 1;
bool game_ended = false;

void GAME_START()
{
   result = 0;
   players_turn = 1;
   game_ended = false;

   for ( int i = 0; i < SIZE_BOARD; i++ )
      BOARD[i] = i + '0'; // Make a `char`
}

void GAME_PLAY()
{
   GAME_START();
   int move;
   
   while( !game_ended ) {
      
      DRAW_BOARD();
      printf( "Player %d, enter a number: ", PLAYERS_TURN( players_turn ) );
      scanf( "%d", &move );

      printf("input as int: %d\tinput as char: %c\n", move, move+0);
      
      if ( CHECK_VALID_MOVE( move ) ) {
         move += '0'; /* adding '0' convert to char */
         PLACE_TILE_ON_BOARD( move, players_turn );
         players_turn++;
      } else {
         printf( "==> Invalid move, try again. " );
         PAUSE();
      }
      
      result = SCORE_RESULT();
      if ( result > 0 )
         game_ended = true;
      }
      
      GAME_END();
   }

void GAME_END()
{
   DRAW_BOARD();
   
   int winner = result;
   
   if ( winner == 3 )
      printf( "Game is a draw.\n" );
   else
      printf( "==> Player %d wins.\n", winner );
   
   GAME_AGAIN();
}

void GAME_AGAIN()
{
        printf( "\n\n\n Play Again? [Y/N]: " );
                scanf( " %c", &play_again ); // white-space required to capture `char` with `scanf`

        if ( play_again == 'Y' || play_again == 'y' )
                GAME_PLAY();
}

int main()
{
   GAME_PLAY();

   return EXIT_SUCCESS;
}
