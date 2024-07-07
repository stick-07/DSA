#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
   int* a = new int;
   printf("%d", a);
   delete a;
   printf("%d", a);
}