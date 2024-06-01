#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <ctype.h>

// Usage:
//
//   gcc -Wall -Wextra -o count_converted count_converted.c
//   echo tænd høje bål | iconv -t ISO_8859-1 | ./count_converted
int main() {
  int c;
  size_t bit_count = 0;

  // Assume that input is in ISO 8859-1 such that æ, ø, and å are one byte each.
  while ((c = getchar()) != EOF) {
    switch (c) {
    case 'a':
    case 'e':
    case 'i':
    case 'o':
    case 'u':
    case 'y':
    case 0xe6: // æ
    case 0xf8: // ø
    case 0xe5: // å
      bit_count += 2;
      break;
    default: // Like ASCII
      // Assume that input contains only non-æøå characters that are also supported in ønæcødæ.
      bit_count += 5;
      break;
    }
  }

  printf("Bits: %lu\nBytes: %lu\n", bit_count, bit_count / 8);
}
