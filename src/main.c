#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

int main()
{
  List *history = init_history();
  char line[256];
  while(true){
    printf("$ ");
    */read line if it returns 0 break*/
    */ if it starts with ! fetch entry with the trailing number if*/
    */ if it doesnt exist return message*/
    free_history(history);
    return 0;
