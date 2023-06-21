/**
 * main - to find and prints the sum of the even-valued terms,
 * followed by a new line
 *
 * Return: 0 
 */
#include <stdio.h>

long int evenFibSum(long int limit) {
  if (limit < 2) {
    return 0;
  }

  long int ef1 = 0, ef2 = 2, sum = ef1 + ef2;
  while (ef2 <= limit) {
    long int ef3 = 4 * ef2 + ef1;
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
  long int limit = 4000000;
  long int sum = evenFibSum(limit);
  printf("The sum of the even-valued Fibonacci terms less than or equal to %ld is %ld.\n", limit, sum);
  return 0;
}
