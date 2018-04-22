

///////////////////////////////////////////////
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>  //define getcwd and chdir
#define PATH_MAX 1024 

char* scan_line(char* buffer, int buffer_size);

char* scan_line(char* buffer, int buffer_size) {
   char* p = buffer;
   int count = 0;
   do {
       char c;
       scanf("%c", &c); // scan a single character
       // break on end of line, string terminating NUL, or end of file
       if (c == '\r' || c == '\n' || c == 0 || c == EOF) {
           *p = 0;
           break;
       }
       *p++ = c; // add the valid character into the buffer
   } while (count < buffer_size - 1);  // don't overrun the buffer
   // ensure the string is null terminated
   buffer[buffer_size - 1] = 0;
   return buffer;
}



int main()
{	
    FILE *fp; 
    char string[PATH_MAX];
    while( 1 )
    {
       strncpy( string, "" , PATH_MAX );
       printf("Enter a string: ");
       scan_line( string , PATH_MAX);
       printf("got: \"%s\"\n\n", string );

       fp = fopen( "soleil.html" , "ab+"); 
	 fputs( string ,  fp );
	 fputs( " <br>\n", fp );
       fclose( fp );
    }
    return 0;
}


