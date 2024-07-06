#include <stdio.h>
#include <stdlib.h>

struct Node {
   int data;
   Node* prev;
   Node* next;
};

struct DoublyLinkedList {
   Node* head = NULL;

   void printForward() {
      Node* temp = head;
      printf("Doubly Linked List: ");
      while(temp != NULL) {
         printf("%d ", temp->data);
         temp = temp->next;
      }
      printf("\n");
   }

   void printReverse() {
      Node* temp = head;
      printf("Doubly Linked List: ");
      while(temp->next != NULL) {
         temp = temp->next;
      }
      while(temp != NULL) {
         printf("%d ", temp->data);
         temp = temp->prev;
      }
      printf("\n");
   }

   void insertStart(int data) {
      Node* newNode = new Node;
      newNode->data = data;
      newNode->prev = NULL;
      newNode->next = head;
      if(head != NULL) {
         head->prev = newNode;
      }
      head = newNode;
   }

   void insertEnd(int data) {
      if(head == NULL) {
         head = new Node;
         head->data = data;
         head->prev = NULL;
         head->next = NULL;
      }
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
};
typedef DoublyLinkedList DLL;

int main() {
   DLL A;

   A.insertEnd(2);
   A.insertEnd(7);
   A.printForward();
   A.printReverse();

   A.insertEnd(8);
   A.insertEnd(9);
   A.printForward();
   A.printReverse();

   A.insertStart(0);
   A.insertStart(-7);
   A.printForward();
   A.printReverse();
   return 0;
}