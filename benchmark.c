#include "benchmark.h"
#include <sys/resource.h>

long get_mem_usage() {
  struct rusage myusage;
  getrusage(RUSAGE_SELF, &myusage);
  return myusage.ru_maxrss;
}

long timediff(clock_t t1, clock_t t2) {
  long elapsed;
  elapsed = ((double)t2 - t1) / CLOCKS_PER_SEC * 1000;
  return elapsed;
}

long bench_function(void (*func)(void), int iterations) {
  clock_t t1, t2;
  int i;
  t1 = clock();
  for (i=0; i < iterations; i++) {
    func();
  }
  t2 = clock();
  return timediff(t1, t2);
}