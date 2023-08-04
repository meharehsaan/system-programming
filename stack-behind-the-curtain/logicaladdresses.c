#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

extern int etext, edata, end;

int I = 54;        // initialized global variable
int J;            // uninitialize global variable
int *x = NULL;   // global pointer

int main(int argc, char *argv[])
{
  int i = 10;         // stack variable
  int *ii = &i;      // stack variable
  printf("Page size: %d\n\n", getpagesize());

  printf("main   = %p\n", main);
  printf("&etext = %p\n\n", &etext);

  printf("&I(initialized var)     = %p\n", &I);

  printf("&edata = %p\n", &edata);

  printf("&J(uninitialized var)     = %p\n", &J);
  printf("&x global pointer    = %p\n", &x);
  
  printf("&end   = %p\n\n", &end);

  ii = (int *)malloc(sizeof(int));    //allocated on heap
  printf("ii (Address of heap)     = %p\n\n", ii);

  printf("&argc  = %p\n", &argc);
  printf("&i     = %p\n", &i);
  printf("&ii    = %p\n", &ii);

  return 0;
}
