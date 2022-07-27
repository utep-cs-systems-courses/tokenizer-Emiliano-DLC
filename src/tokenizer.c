#include <stdlib.h>
#include <stdio.h>
#include "tokenizer.h"
#include "history.h"

int space_char(char c)
{
  if(c == ' ' || c == '\t')
    {
      return 1;
    }//Return true if c is ' ' or '\t' (tab)
  else
    return 0;
}

int non_space_char(char c)
{
  if(c == ' ' || c == '\t' || c == '\0')
    {
      return 1;
    }
  else
    return 0;
}

char *word_start(char *str)
{
  //int index = 0;
  while(space_char(*str) == 1 && *str != '\0'){
    str++;
  }//Iterates str and increments index by one
  return str; //Return addres str[index]
}

char *word_terminator(char *word)
{
  word = word_start(word);
	while(non_space_char(*word) == 1 && *word != '\0')
	{
		word++;
	}
	return word;
}

int count_words( char *str)
{
  int count = 1;
  str = word_start(str);
  while(*str != '\0')//While str out of bounce
    {
      if(space_char(*str)==1)
	{
	  count++;
	}
      str++;
    }
  //printf("This is the count: %d", count);
  return count;
}

char *copy_str(char *inStr, short len)
{
  char *str = (char*)malloc((len+1) * sizeof(char));
  int i;
  for(i = 0; i < len; i++)
    {
      str[i] = inStr[i];
    }
  str[i] = '\0';
  return str;
}

char **tokenize(char* str)
{
  int tkn_num = count_words(str);
  char **token = (char**) malloc((tkn_num+1) * sizeof(char*));
  char *end;
  int i;
  for(i = 0; i < tkn_num; i++)
    {
      str = word_start(str);
      end = word_terminator(str);
      token[i] = copy_str(str, (end - str));
      str = word_terminator(str);
    }
  token[i] = '\0';
  return token;
}

void print_tokens(char **tokens) //Print
{
  int i;
  for(i = 0; tokens[i] != NULL; i++)
  {
      printf("token[%d]: %s\n", i, tokens[i]);
 
  }
}

void free_tokens(char **tokens) //free
{
  int index = 0;
  while(tokens[index])
    {
      free(tokens[index]);
      index++;
    }
  free(tokens[index]);//clears '\0'
  free(tokens);
}



  
