/**
 * main - to find and prints the sum of the even-valued terms,
 * followed by a new line
 *
 * Return: 0 
 */
#include <stdio.h>

unsigned long evenFibSum(unsigned long limit) {
  if (limit < 2) {
    return 0;
  }

  unsigned long ef1 = 0, ef2 = 2, sum = ef1 + ef2;
  while (ef2 <= limit) {
    unsigned long ef3 = 4 * ef2 + ef1;
    if (ef3 > limit) {
      break;
    }

    ef1 = ef2;
    ef2 = ef3;
    sum += ef2;
  }

  return sum;
}

int main() {
  unsigned long limit = 4000000;
  unsigned long sum = evenFibSum(limit);
  printf("The sum of the even-valued Fibonacci terms less than or equal to %lu is %lu.\n", limit, sum);
  return 0;
}
