#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 10
//Array Implementation Of Stack
struct ArrayStack {
   int stack[MAX_SIZE];
   int topPtr = -1;

   void push(int data) {
      if(topPtr == MAX_SIZE - 1) {
         return;
      }
      stack[++topPtr] = data;
   }

   void pop() {
      if(isEmpty()) {
         printf("No elements to pop.\n");
         return;
      }
      topPtr--;
   }

   int top() {
      return stack[topPtr];
   }

   bool isEmpty() {
      if(topPtr == -1) {
         return true;
      }
      return false;
   }

   void printStack() {
      printf("Stack: ");
      for(int i = topPtr; i >= 0; i--) {
         printf("%d ", stack[i]);
      }
      printf("\n");
   }
};
typedef struct ArrayStack AS;

//Linked List Implementation Of Stack
struct Node {
   int data;
   Node* next;
};

struct LinkedListStack {
   Node* topPtr = NULL;

   void push(int data) {
      Node* newNode = new Node;
      newNode->data = data;
      newNode->next = topPtr;
      topPtr = newNode;
   }

   void pop() {
      if(topPtr == NULL) {
         printf("No elements to pop.\n");
         return;
      }
      Node* del = topPtr;
      topPtr = del->next;
      delete del;
   }

   int top() {
      return topPtr->data;
   }

   bool isEmpty() {
      if(topPtr == NULL) {
         return true;
      }
      return false;
   }

   void printStack() {
      Node* temp = topPtr;
      printf("Stack: ");
      while(temp != NULL) {
         printf("%d ", temp->data);
         temp = temp->next;
      }
      printf("\n");
   }      
};
typedef struct LinkedListStack LLS;

int main() {
   AS A;
   A.push(2);
   A.push(3);
   A.push(7);
   A.printStack();
   printf("%d\n", A.isEmpty());

   A.pop();
   A.pop();
   A.printStack();
   A.pop();
   A.printStack();
   A.pop();
   printf("%d\n", A.isEmpty());

   LLS B;
   B.push(2);
   B.push(3);
   B.push(7);
   B.printStack();
   printf("%d\n", B.isEmpty());

   B.pop();
   B.pop();
   B.printStack();
   B.pop();
   B.printStack();
   B.pop();
   printf("%d\n", B.isEmpty());
}