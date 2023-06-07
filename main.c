//  CSCI 4100
//  Tyler Nelson
//  Reads and prints .txt files
//
//
//

#include <stdio.h>
#include <stdlib.h>

void display_stream(FILE *stream);

int main(int argc, const char *argv[]) {
  if (argc == 1) {
    char *input = NULL;
    size_t input_size = 0;
    getline(&input, &input_size, stdin);
    printf(input);
    exit(0);
  }
  if (argc > 1) {
    FILE *stream;
    for (int i = 1; i <= argc; i++) {
      stream = fopen(argv[i], "r");
      if (stream != NULL) {
        display_stream(stream);
        exit(0);
      }

      else {
        perror("Error. File not found.");
        exit(1);
      }
    }
  } 
}

void display_stream(FILE *stream) {
  char c;
  while ((c = fgetc(stream)) != EOF) {
    putchar(c);
  }
  fclose(stream);
}
