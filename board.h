#include <stdio.h>
#include <stdbool.h>

#define CLEAR_SCREEN printf( "\033[H\033[J" ); /* Works on *NIX* -- I do not use Windows, so cannot confirm */

char BOARD[10] = { '0' , '1' , '2' , '3' , '4' , '5' , '6' , '7' , '8' , '9' };
size_t SIZE_BOARD = sizeof( BOARD ) / sizeof( BOARD[0] );

void DRAW_BOARD()
{
   CLEAR_SCREEN;

    printf(
    "                                \n"
    "                                \n"
    "         TIC TAC TOE            \n"
    "                                \n"
    "Player 1 (X)  -  Player 2 (O)   \n"
    "                                \n"
    "           |     |              \n"
    "        %c  |  %c  |  %c        \n"
    "      _____|_____|_____         \n"
    "           |     |              \n"
    "        %c  |  %c  |  %c        \n"
    "      _____|_____|_____         \n"
    "           |     |              \n"
    "        %c  |  %c  |  %c        \n"
    "           |     |              \n"
    "                                \n"
    , BOARD[1], BOARD[2], BOARD[3], BOARD[4], BOARD[5], BOARD[6], BOARD[7], BOARD[8], BOARD[9]
    );
}

void PLACE_TILE_ON_BOARD( int tile, int player )
{
   char player_tile = PLAYERS_TILE( player );

   for ( int i = 0; i < SIZE_BOARD; i++ )
     BOARD[i] = ( BOARD[i] == tile ) ? player_tile : BOARD[i] ;
}

bool CHECK_VALID_MOVE( int move )
{
        bool result = false;

        if ( move >= 0 && move <= 10 )
                result = true;

        if ( BOARD[move] == 'X' || BOARD[move] == 'O' )
                result = false;

        return result;
}