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

   void enqueue(int data) {
      if((rear + 1) % MAX_SIZE == front) {
         printf("Queue is full.\n");
         return;
      } else if(isEmpty()) {
         front = 0;
         rear = 0;
      } else {
         rear = (rear + 1) % MAX_SIZE;
      }
      queue[rear] = data;
   }

   void dequeue() {
      if(isEmpty()) {
         printf("Queue is empty.\n");
      } else if(front == rear) {
         front = -1;
         rear = -1;
      } else {
         front = (front + 1) % MAX_SIZE;
      }
   }

   int f() {
      return queue[front];
   }

   void printQueue() {
      printf("Queue: ");
      if(!isEmpty()) {
         for(int i = front; i != rear + 1; i++) {
            printf("%d -> ", queue[i % MAX_SIZE]);
         }
      }
      printf("\n");
   }
};
typedef struct ArrayQueue AQ;

//Linked List Implementation Of Queue
struct Node {
   int data;
   Node* next;
};

struct LinkedListQueue {
   Node* front = NULL;
   Node* rear = NULL;

   bool isEmpty() {
      if(front == NULL && rear == NULL) {
         return true;
      }
      return false;
   }

   void enqueue(int data) {
      Node* newNode = new Node;
      newNode->data = data;
      newNode->next = NULL;
      if(isEmpty()) {
         front = rear = newNode;
         return;
      }
      rear->next = newNode;
      rear = newNode;
   }

   void dequeue() {
      if(isEmpty()) {
         printf("Queue is empty.\n");
         return;
      }
      Node* del = front;
      if(front == rear) {
         front = rear = NULL;
      } else {
         front = front->next;
      }
      delete del;
   }
   
   int f() {
      return front->data;
   }

   void printQueue() {
      printf("Queue: ");
      if(!isEmpty()) {
         Node* temp = front;
         while(temp != NULL) {
            printf("%d -> ", temp->data);
            temp = temp->next;
         }
      }
      printf("\n");
   }
};
typedef struct LinkedListQueue LLQ;

int main() {
   AQ A;
   A.enqueue(2);
   A.enqueue(3);
   A.enqueue(7);
   A.printQueue();

   A.dequeue();
   A.dequeue();
   A.dequeue();
   A.printQueue();
   A.dequeue();

   for(int i = 0; i <= 20; i+=2) {
      A.enqueue(i);
   }
   A.printQueue();

   LLQ B;
   B.enqueue(2);
   B.enqueue(3);
   B.enqueue(7);
   B.printQueue();

   B.dequeue();
   B.dequeue();
   B.dequeue();
   B.printQueue();
   B.dequeue();

   for(int i = 0; i <= 20; i+=2) {
      B.enqueue(i);
   }
   B.printQueue();
   return 0;
}