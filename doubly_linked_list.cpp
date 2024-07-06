#include <stdio.h>
#include <stdlib.h>

struct Node {
   int data;
   Node* prev;
   Node* next;
};

void printForward(Node* head) {
   printf("Doubly Linked List: ");
   while(head != NULL) {
      printf("%d ", head->data);
      head = head->next;
   }
   printf("\n");
}

void printReverse(Node* head) {
   printf("Doubly Linked List: ");
   while(head->next != NULL) {
      head = head->next;
   }
   while(head != NULL) {
      printf("%d ", head->data);
      head = head->prev;
   }
   printf("\n");
}

Node* insertStart(Node* head, int data) {
   Node* newNode = new Node;
   newNode->data = data;
   newNode->prev = NULL;
   newNode->next = head;
   if(head != NULL) {
      head->prev = newNode;
   }
   head = newNode;
   return head;
}

Node* insertEnd(Node* head, int data) {
   if(head == NULL) {
      head = new Node;
      head->data = data;
      head->prev = NULL;
      head->next = NULL;
   } else {
      Node* temp = head;
      while(temp->next != NULL) {
         temp = temp->next;
      }
      Node* newNode = new Node;
      newNode->data = data;
      newNode->prev = temp;
      newNode->next = NULL;
      temp->next = newNode;
   }
   return head;
}

int main() {
   Node* A = NULL;
   A = insertEnd(A, 2);
   A = insertEnd(A, 7);
   printForward(A);
   printReverse(A);

   A = insertEnd(A, 8);
   A = insertEnd(A, 9);
   printForward(A);
   printReverse(A);

   A = insertStart(A, 0);
   A = insertStart(A, -7);
   printForward(A);
   printReverse(A);
   return 0;
}