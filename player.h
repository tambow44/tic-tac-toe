#define PLAYER_ONE 1
#define PLAYER_TWO 2
#define PLAYER_ONE_TILE 'X'
#define PLAYER_TWO_TILE 'O'

char PLAYERS_TILE( int tile )
{
   return ( (tile % 2) == 0 ) ? PLAYER_TWO_TILE : PLAYER_ONE_TILE ;
}

int PLAYERS_TURN( int turn )
{
   return ( (turn % 2) == 0 ) ? PLAYER_TWO : PLAYER_ONE ;
}