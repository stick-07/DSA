#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

struct Node {
   int data;
   Node* next;
};

struct Node* head = NULL;

void printList() {
   if(head != NULL) {
      Node* temp = head;
      printf("Linked List: ");
      while(temp != NULL) {
         printf("%d ", temp->data, temp->next);
         temp = temp->next;
      }
   }
   printf("\n");
};

void insertEnd(int data) {
   if(head == NULL) {
      head = new Node;
      head->data = data;
      head->next = NULL;
   } else {
      Node* temp = head;
      while(temp->next != NULL) {
         temp = temp->next;
      }
      Node* newNode = new Node;
      temp->next = newNode;
      newNode->data = data;
      newNode->next = NULL;
   }
};

void insertStart(int data) {
   Node* newNode = new Node;
   newNode->data = data;
   if(head != NULL) {
      newNode->next = head;
   } else {
      newNode->next = NULL;
   }
   head = newNode;
}

int main() {
   printList();
   insertEnd(7);
   insertStart(4);

   printList();
   insertStart(2);
   insertEnd(10);
   insertEnd(13);
   
   printList();
   return 0;
};