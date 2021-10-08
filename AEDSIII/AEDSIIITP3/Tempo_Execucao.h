#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/resource.h>
#include<unistd.h>
double tempo_Execucao(){
  struct timeval tv;
  gettimeofday(&tv,0);
  return tv.tv_sec + tv.tv_usec/1e6;
}
void tempo_sistema_usuario(){
  struct rusage usage;
  getrusage(RUSAGE_SELF, &usage);
  printf("Tempo CPU : %ld.%06ld seg (USER),%ld.%06ld seg (SYSTEM)\n",usage.ru_utime.tv_sec,usage.ru_utime.tv_usec,usage.ru_stime.tv_sec,usage.ru_stime.tv_usec);
}
