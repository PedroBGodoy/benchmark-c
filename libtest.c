#include "benchmark.h"
#include <stdio.h>

void test_function() {
  int i;
  for (i=0; i < 1000000; i++) {
    i = i + 1;
  }
}

int main(void) {
  long elapsed;
  
  elapsed = bench_function(test_function, 100);

  printf("elapsed: %ld ms\n", elapsed);
  printf("Memory usage: %ld\n", get_mem_usage());

  return 0;
}