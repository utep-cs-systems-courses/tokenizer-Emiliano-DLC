#include <stdlib.h>
#include <stdio.h>
#include "tokenizer.h"
#include "history.h"


int main(){
  puts("welcome");
  //Token 
  char string[100];
  char* pstring;
  char** token;
  //printf("hello world\n");

  while(1)
    {
      fputs("Enter 't' to tokenize, enter 'e' to exit, enter 'h' to show history\n> ", stdout);
      fflush(stdout);/* stdout only flushes automatically on \n */
      int c;
      while ((c = getchar()) == '\n'){if(c==EOF){goto done;}}
      
      switch(c)
	{
	case 'E':
	  puts("program exited");
	  goto done;
	case 'T':
          printf("Enter string");
          scanf("%s", string);
          pstring = string;
          token = tokenize(pstring);
          print_tokens(token);
          free_tokens(token);
          break;
	}
      
    }


 done:return 0; //Terminate program
  
}
