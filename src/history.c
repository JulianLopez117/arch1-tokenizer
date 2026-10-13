#include <stdio.h>
#include <stdlib.h>
#include "history.h"
#include "tokenizer.h"

List *init_history(){
  /*malloc list, root=0 return*/
  List *list = malloc(sizeof(List));
  list->root = 0;
  return list;
}
void add_history(List *list, char *str)
{
  /*create item:ID, copy of the string, next=0 go to end of list and add*/
  int len = 0;
  while(str[len]!='\0')
    len++;

  Item *item = malloc(sizeof(Item));
  item->str = copy_str(str,len);
  item->next = 0;

  if(list->root==0){
    item->id = 1;
    list->root = item;
    return;
}
  Item *last = list->root;
  while(last->next!=0)
    last = last->next;
  item->id = last->id + 1;
  last->next = item;
}
char *get_history(List *list, int id){
  /*return str of the node whose id matches
    return 0 if it doesn't exist*/
  for(Item *cur = list->root; cur!=0;cur=cur->next){
    if(cur->id==id)
      return cur->str;
  }
  return 0;
}
void print_history(List *list){
  /*print each node as id and string*/
  for(Item *cur = list->root;cur!=0; cur = cur->next)
    printf("%d. %s\n", cur->id, cur->str);
}
void free_history(List*list)
{
  Item *cur = list->root;
  while(cur!=0){
    Item *next=cur->next;
    free(cur->str);
    free(cur);
    cur = next;
  }
  free(list);
}
