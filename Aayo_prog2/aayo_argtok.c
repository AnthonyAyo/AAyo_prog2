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
  if((c < 33 || c > 126 )){
    return 0;
  }else
    return 1;
}



// find the start of the next word

int find_word_start(char *p, int pos){
  char *counter = p + pos;
  while(*counter) {
    if(is_valid_character(*counter) == '1' && is_valid_character(*(counter-1)) == '0') {
      return counter - p;
    } else {
      ++counter;
    }
  }
}



//gets the starting position from find_word_start and continues on until a space is found



int find_word_end(char *p, int pos){
  
  char *pp = p + pos;
  while(*pp) {
    if(is_valid_character(*pp) == '1' && is_valid_character(*(pp+1)) == '0') {
      return pp - p;
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
  char **pp = p;
  int pos = 0;
  int size = 0;
  int count = 0;
  
  while(pp[pos] != NULL) {
    char *word = pp[pos];
    while(*word) {
      printf("%c", pp[pos][count]);
      count++;
      ++word;
    }
    printf("\n");
    pos++;
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



char** argtok(char *str){
  int size = count_words(str);
  char **tokens = malloc(sizeof(char*) * (size) + 1);
  char *counter = str;

  for(int i = 0; i < size; i++) {
    int start = find_word_start(str, counter - str);
    int end = find_word_end(str, counter - str) + 1;
    tokens[i] = malloc((sizeof(char) * (end - start + 1)));
    int place = 0;
    char *stopPoint = str + end;
    counter = str + start;
    while(*counter != *stopPoint) {
      tokens[i][place] = *counter;
      place++;
      ++counter;
    }
    tokens[i][place+1] ='\0';
    counter = counter + 1;
  }
  return tokens;
}


