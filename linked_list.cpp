#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

struct Node {
   int data;
   Node* next;
};

void showList(Node* start) {
   printf("Data: %d\nNext Address: %d\n", (*start).data, (*start).next);
   while((*start).next != NULL) {
      start = (*start).next;
      printf("Data: %d\nNext Address: %d\n", (*start).data, (*start).next);
   }
};

void insert(Node* start, int data) {
   while((*start).next != NULL) {
      start = (*start).next;
   }
   Node* temp1 = new Node;
   (*start).next = temp1;
   (*temp1).data = data;
   (*temp1).next = NULL;
};

int main() {
   Node* A = new Node;
   (*A).data = 2;
   (*A).next = NULL;

   insert(A, 4);
   insert(A, 7);

   showList(A);

   insert(A, 10);
   insert(A, 13);
   
   showList(A);
   return 0;
};