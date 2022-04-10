#ifndef __BENCHMARK_H__
#define __BENCHMARK_H__

#include <time.h>

long get_mem_usage();
long time_diff(clock_t t1, clock_t t2);
long bench_function(void (*func)(void), int iterations);

#endif