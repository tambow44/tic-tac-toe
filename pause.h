/*
This is my condensed take on the popular `https://faq.cprogramming.com/cgi-bin/smartfaq.cgi?answer=1042856625&id=1043284385`
*/

#include <termios.h>
#include <unistd.h>

void PAUSE()
{
   FILE *in = stdin;
   int ch;
   
   while ( ch != EOF && ch != '\n' )
      ch = fgetc ( in );

   clearerr ( in );
   fflush ( stdout );
   getchar();
}