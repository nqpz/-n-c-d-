#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <time.h>
#include <ctype.h>

// Usage: echo tænd høje bål | iconv -t ISO_8859-1 | ./convert
int main() {
  int c;

  // Input must be in ISO 8859-1 such that æ, ø, and å are one byte each.
  while ((c = getchar()) != EOF) {
    switch (c) {
    case 0xe6: // æ
      break;
    case 0xf8: // ø
      break;
    case 0xe5: // å
      break;
    default: // Like ASCII
      break;
    }
  }
}
