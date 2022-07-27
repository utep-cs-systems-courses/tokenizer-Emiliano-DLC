#include <stdlib.h>
#include <stdio.h>
#include "tokenizer.h"
#include "history.h"

//Struct defined at history.h

List* init_history()
{
  List* history_list = (List*)malloc(sizeof(List)); //allocate memory
  return history_list; //return linked list
}

/* Add a history item to the end of the list.
   List* list - the linked list
   char* str - the string to store
*/
void add_history(List *list, char *str)
{
  Item* data = (Item*)malloc(sizeof(Item)); //allocates memory for Item
  Item* node = list -> root; //node
  int len = 0, id_index = 0; //variables 
  while(str[len] != '\0'){len++;}//Get the length of the str
  data -> str = copy_str(str, len);//Adds str to data
  data -> next = NULL; //set next pointer
  if(node == NULL)//node empty set the first elements
    {
      data -> id = id_index;//id_index == 0 because node is empty
      list -> root = data;//set data as the root
      return; //terminates add_history
    }
  while(node -> next != NULL)//Iterate node to get to the last element when node is not empty
    {
      node = node -> next; //traverse the list
      id_index++;//increase id index
    }
  id_index++;//increaase id index
  data -> id = id_index;
  node -> next = data;
}

/* Retrieve the string stored in the node where Item->id == id.
   List* list - the linked list
   int id - the id of the Item to find */
char *get_history(List *list, int id)
{
  Item* node = list -> root;
  while(node != NULL)//iterate
    {
      if(node -> id == id)// id node id == to id
	{
	  return node -> str;//return str at the id index
	}
      node = node -> next;//advance on the list
    }
  return "Nothing to return";//when id is invalid
}

/*Print the entire contents of the list. */
void print_history(List *list)
{
  Item *node = list -> root;
  while(node != NULL)//iterate the list
    {
      printf("%s", node -> str);//print node str
      node = node -> next;//advance to the next element
    }
  //printf("done");
}

/*Free the history list and the strings it references. */
void free_history(List *list)
{
  Item* node = list -> root;
  while(list -> root != NULL)
    {
      list -> root = list -> root -> next;//list root is shifted to the next
      free(node -> str);//individually free node -> str
      free(node);//Now free node
      node = list -> root;//point node to the new root
    }
  free(list);//free the list
}

