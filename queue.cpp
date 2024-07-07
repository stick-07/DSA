#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10
//Array Implementation Of Queue
struct ArrayQueue {
   int queue[MAX_SIZE];
   int front = -1;
   int rear = -1;

   bool isEmpty() {
      if(front == -1 && rear == -1) {
         return true;
      }
      return false;
   }
};
typedef struct ArrayQueue AQ;

int main() {
   AQ a;
   return 0;
}