#include <stdlib.h>
#include <stdio.h>

int space_char(char c)
{
  if(c == ' ' || c == '\t'){return 1;}//Return true if c is ' ' or '\t' (tab)
  return 0;
}

int non_space_char(char c)
{
  if(c != ' ' || c != '\t'){ return 1;} //return true if c is not ' ' or '\t' (tab)
  return 0;
}

char *word_start(char *str)
{
  int index = 0;
  while(space_char(str[index]) == 1){index++;}//Iterates str and increments index by one
  return &str[index]; //Return addres str[index]
}

char *word_terminator(char *str)
{
  str = word_start(str); //set str to the first word calling word_start
  int index = 0;
  while(non_space_char(str[index]) == 1){index++;} // Iterates loop and increments index
  return &str[index]; //return addres of word_terminator
}

int count_words( char *str)
{
  int count = 0;
  while(str != word_terminator(str))//While str != word_terminator iterate the loop
    {
      str = word_terminator(str); //addvance on the number of words
      count++;// increase occurences
    }
  count ++; // If is a one word string
  return count;
}

char *copy_str(char *inStr, short len)
{
  int index = 0;
  char *mallocarray = (char *)malloc(sizeof(char) * (len + 1)); //allocates memory 
  while(index < len)
    {
      mallocarray[index] = inStr[index]; //copy into mallocarray
      index++;
    }
  mallocarray[index] = '\0'; //End of the array
  return mallocarray; //return malloc
}

char **tokenize(char* str)
{
  int token_count = count_words(str); //get the number of tokens
  int count = 0;
  char ** malloc2darray = malloc(sizeof(char *) * (token_count)); //Creates a 2d malloc array
  char *begin = word_start(str);
  char *end = word_terminator(str);

  while(count < token_count)
    {
      malloc2darray[count] = copy_str(begin, (end - begin));
      begin = word_start(end);
      end = word_terminator(begin);
    }
  malloc2darray[count] = '\0';
  return malloc2darray;
}

void print_tokens(char **tokens) //Print
{
  int index = 0;
  while(tokens[index] != '\0')
    {
      printf("token[%d] = %s" , index, tokens[index]);
      index++;
    }
}

void free_tokens(char **tokens) //free
{
  int index = 0;
  while(tokens[index] != '\0')
    {
      free(tokens[index];
      index++;
    }
  free(tokens[index]//clears '\0'
  free(tokens);
}



  
