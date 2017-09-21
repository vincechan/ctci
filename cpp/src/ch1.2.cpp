#include "third_party/catch.hpp"

/**
 * Reverse a null terminated s tring.
 */
void reverse(char *input) {
  if (input) {
    char *end = input;
    while (*end != '\0') {
      end++;
    }
    end--;

    char *start = input;
    while (start < end) {
      char tmp = *start;
      *start++ = *end;
      *end-- = tmp;
    }
  }
}

TEST_CASE("ch1.2 reverse") {
  char input[] = "abcde";
  reverse(input);
  REQUIRE(strcmp(input, "edcba") == 0);
}
