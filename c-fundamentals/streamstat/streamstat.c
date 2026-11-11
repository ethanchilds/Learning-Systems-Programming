#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>
#include <string.h>

const char* STDIN_MARKER= "-";

int main(int argc, char *argv[]){
  FILE* fp;
  char s[1024];
  size_t linecount = 0;
  size_t bytes = 0;
  size_t words = 0;

  int inWord = 0;

  if (argc != 2){
    printf("Incorrect number of arguments\n");
    return EXIT_FAILURE;
  }

  if (strcmp(argv[1], STDIN_MARKER)){
    fp = fopen(argv[1], "r");
  }else{
    fp = stdin;
  }

  if (fp == NULL){
    printf("Failed to open file\n");
    return EXIT_FAILURE;
  }

  char c;
  while(c=fgetc(fp), c!=EOF){
    bytes++;
    if (c=='\n')
      linecount++;

    if (isspace(c)){
      inWord = 0;
    }else if(!inWord){
      inWord = 1;
      words++;
    }
  }

  if (ferror(fp)==0){
    printf("lines: %zu\n", linecount);
    printf("Words: %zu\n", words);
    printf("bytes: %zu\n", bytes);
  }else{
    printf("Failure reading data stream\n");
  }

  if (strcmp(argv[1], STDIN_MARKER))
    fclose(fp);
}

