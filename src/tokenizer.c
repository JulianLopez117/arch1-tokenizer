#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

int space_char(char c){
  if (c==' '||c=='\t')
    return 1;
  return 0;
}
int non_space_char(char c){
  if(c!=' ' && c!='\t' && c!='\0')
    return 1;
  return 0;
}
char *token_start(char *str){
  for(char *p = str; *p!='\0';p++){
    if(non_space_char(*p)==1)
      return p;
  }
  return 0;
}
char *token_terminator(char *token){
  for(char *n = token; *n!='\0';n++){
    if(*n==' '||*n=='\t'||*n=='\0')
      return n;
  }
  return n;
}
int count_tokens(char *str){
  int count=0;
  char *p=str;
  char *start;
  while((start=token_start(p))!=0){
    count++;
    p = token_terminator(start);
    }
  return count;
}
char *copy_str(char *inStr, short len){
  char *copy = malloc(len +1);
  int i;
  for(i=0;i<len;i++)
    copy[i]=inStr[i];
  copy[i]='\0';
  return copy
}
char **tokenize(char **tokens){
  int n = count_tokens(str);
  char **tokens = malloc((n+1) * sizeof(char *));
  char *p =str;

  for(int i = 0; i<n;i++){
    char *start = token_start(p);
    char *end = token_terminator(start);
    tokens[i] = copy_str(start, end-start);
    p = end;
  }
  tokens[n] = 0;
  return tokens;
}
void print_tokens(char **tokens){
  for(int i = 0;tokens[i]!=0;i++)
    printf("%s\n, tokens[i]);
}
void free_tokens(char **tokens){
  for(int i = 0; tokens[i]!=0;i++)
    free(tokens[i]);
  free(tokens);
}

