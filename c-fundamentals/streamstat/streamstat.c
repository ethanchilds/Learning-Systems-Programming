#include <stdio.h>
#include <ctype.h>
#include <string.h>

char* STDIN_MARKER= "-";

void evaluateWord(char c, int* inWord, int*couldBeWord, size_t* words);

int main(int argc, char *argv[]){
  FILE* fp;
  char s[1024];
  size_t linecount = 0;
  size_t bytes = 0;
  size_t words = 0;

  int inWord = 0;
  int couldBeWord = 1;

  if (argc != 2){
    printf("Incorrect number of arguments\n");
    return -1;
  }

  if (strcmp(argv[1], STDIN_MARKER)){
    fp = fopen(argv[1], "r");
  }else{
    fp = stdin;
  }

  if (fp == NULL){
    printf("Failed to open file\n");
    return -1;
  }

  while(fgets(s, sizeof s, fp) != NULL){
    int i = 0;
    do{
      if (s[i]=='\n')
        linecount++;
      evaluateWord(s[i], &inWord, &couldBeWord, &words);
      i++;
    }while(s[i]!='\0');
    bytes += i;
  }

  printf("lines: %zu\n", linecount);
  printf("Words: %zu\n", words);
  printf("bytes: %zu\n", bytes);

  if (strcmp(argv[1], STDIN_MARKER))
    fclose(fp);
}

void evaluateWord(char c, int* inWord, int*couldBeWord, size_t* words){
  if (isspace(c)){
    if (*inWord){
      (*words)++;
      *inWord = 0;
      *couldBeWord = 1;
    }
  }else{
    if (*couldBeWord){
      *inWord = 1;
      *couldBeWord = 0;
    }
  }
}
