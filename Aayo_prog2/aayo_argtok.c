//
//	EE 4374 Assignment # 1 Argument Tokenizer
//	Author: Anthony Ayo




#include <stdio.h>

#include <stdlib.h>

#include "aayo_argtok.h"



//Count the number of chars in the string.

int string_length(char *p){
  char *pp = p;
  while(*p){
    p++;
  }
  return p-pp;
}


//checks to see if the character being looked at is valid

char is_valid_character(char c){
  if((c >= 33|| c <= 126 )){
    return 1;
  }else
    return 0;
}



// find the start of the next word

int find_word_start(char *p, int pos){
  
  char *pp = p + pos;
  while(*pp) {

    if(is_valid_character(*pp) == '1' && is_valid_character(*(pp-1)) == '0') {
      return pp - pos;
    } else {
      ++pp;
      
    }
  }
}



//gets the starting position from find_word_start and continues on until a space is found



int find_word_end(char *p, int pos){
  
  char *pp = p + pos;
  while(*pp) {
    if(is_valid_character(*pp) == '1' && is_valid_character(*(pp+1)) == '0') {
      return pp - pos;
    } else {
      ++pp;

    }
  }
}



int count_words(char *p){

  int wordCount = 0;
  char *pp = p;
  int length = 0;
  while(*pp){
    if(*pp == ' ')
      length = 0;
    else if (++length == 1)
      wordCount++;
    *pp++;
  }

  return wordCount;

}

void print_tokens(char **p){
  char **temp = p;
  while(*temp != NULL){
    printf("The tokenized words are :%c\n",*temp);
    temp++;
  }
}




// free the space used up by malloc

void free_tokens(char **p){
  int i = 0;

  while(p[i] != NULL) {
    free(p[i]);
    i++;
  }
  free(p);
  }

}

char** argtok(char *p){

  int number_of_words = count_words(p);
  int count = 0;
  int start;
  int end;
  int position = 0;
  int i = 0;
  int j = 0;
  
  char ** tokens = (char **)malloc((number_of_words+1)*sizeof(char*));// creates the array of pointer based on # of tokens
  char *pp = p;
  for( i = 0; i < number_of_words; i++){

    start = find_word_start(p,pp-p);
    end = find_word_end(p,pp-p);
    
    char *endpoint = p + end;
    while(*pp !=* endpoint){
    tokens[i][position] = *pp;
    position++;
    ++pp;
    }
  tokens[i][position+1] = '\0'
    pp = pp+1;
  }
  return tokens;
}
