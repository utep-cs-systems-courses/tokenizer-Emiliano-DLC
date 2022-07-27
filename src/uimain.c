#include <stdlib.h>
#include <stdio.h>
#include "tokenizer.h"
#include "history.h"

#define MAX_STR 100

int main(){
  puts("welcome");

  //Variables
  char userInput[MAX_STR];
  char word[MAX_STR];
  char* pointer = &word[0];
  char** tokens;
  int count = 0;
  char *funTester;
  int temp;
  int wordCounter;
  
  //History
  List *list = init_history();

  //Loop
  while(1)
    {
      printf("Type word to tokenize or 'q' to exit or @[number] to get the history on that index\n");
      fgets(word, MAX_STR, stdin);

      switch(word[0])
	{
	case 'q':
	  printf("Program terminated\n");
	  goto done;
	  break;
	case '@':
	  temp = word[1] - '0'; //Cohercion
	  printf("History at index %c is %s\n", word[1], get_history(list, temp));
	  printf("process terminated");
	  break;
	default:
	  tokens = tokenize(pointer);
	  printf("Tokens\n");
	  print_tokens(tokens);
	  add_history(list, word);
	  printf("-----------\n");
	  printf("Print current History");
	  print_history(list);
	  free_tokens(tokens);
	  printf("___\n");
	}

    }

 done: return 0;
}
