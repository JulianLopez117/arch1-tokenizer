#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

int main()
{
  
  List *history = init_history();
  char line[256];

  while(1){
    printf("$ ");
    if(fgets(line,256,stdin)==0)
       break;
       
    for(char *p = line; *p!='\0';p++)
      if(*p=='\n')
	*p='\0';

    if(line[0] == 'h' && line[1]=='\0'){
      print_history(history);
      continue;
         }
    char *input = line;
      if(line[0]=='!'){
	input = get_history(history,atoi(line+1));
	if(input==0){
	  printf("No history with that entry\n");
	  continue;
	 }
       }else{
	add_history(history,line);
       }

       char **tokens = tokenize(input);
       print_tokens(tokens);
       free_tokens(tokens);
       }
    free_history(history);
    return 0;
	   
    /*read line if it returns 0 break*/
    /* if it starts with ! fetch entry with the trailing number if*/
    /* if it doesnt exist return message*/
  }
