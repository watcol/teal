#include "teal.h"
#include <stdio.h>
#include <stdlib.h>

#define MAX_INPUT 50000

int main() {
  // Read STDIN.
  char buf2[MAX_INPUT + 1] = "";
  read_stdin(buf2, MAX_INPUT);

  // debug: Print the buffer.
  // fprintf(stderr, "%s", buf);

  // Convert char[] to char*
  char *buf = buf2;

  // debug: Print a receved number.
  // fprintf(stderr, "%d\n", n);

  // Write assembly.
  puts(".intel_syntax noprefix");
  puts(".globl main");
  puts("main:");

  // Read a number.
  printf("  mov rax, %ld\n", strtol(buf, &buf, 10));

  // Addition and subtraction.
  while(*buf) {
    if (*buf == '+') {
      buf++;
      printf("  add rax, %ld\n", strtol(buf, &buf, 10));
    } else if (*buf == '-') {
      buf++;
      printf("  sub rax, %ld\n", strtol(buf, &buf, 10));
    } else if (*buf == '\n' || *buf == ' ') {
      // Skip token.
      buf++;
    } else {
      fprintf(stderr, "Unexpected token: '%c'\n", *buf);
      return 1;
    }
  }

  puts("  ret");

  return 0;
}
