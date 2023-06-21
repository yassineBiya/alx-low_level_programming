#include <stdio.h>

long long int evenFibSum(long long int limit) {
  if (limit < 2) {
    return 0;
  }

  long long int ef1 = 0, ef2 = 2, sum = ef1 + ef2;
  while (ef2 <= limit) {
    long long int ef3 = 4 * ef2 + ef1;
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
  long long int limit = 4000000;
  long long int sum = evenFibSum(limit);
  printf("The sum of the even-valued Fibonacci terms less than or equal to %lld is %lld.\n", limit, sum);
  return 0;
}
