#include <stdio.h>
#include <stdlib.h>

struct Node {
   int data;
   Node* next;
};

struct LinkedList {
   Node* head = NULL;

   void printForward() {
      Node* temp = head;
      printf("Linked List: ");
      while(temp != NULL) {
         printf("%d ", temp->data, temp->next);
         temp = temp->next;
      }
      printf("\n");
   }

   void insertEnd(int data) {
      if(head == NULL) {
         head = new Node;
         head->data = data;
         head->next = NULL;
         return;
      }
      Node* temp = head;
      while(temp->next != NULL) {
         temp = temp->next;
      }
      Node* newNode = new Node;
      temp->next = newNode;
      newNode->data = data;
      newNode->next = NULL;
   }

   void insertStart(int data) {
      Node* newNode = new Node;
      newNode->data = data;
      newNode->next = head;
      head = newNode;
   }

   void Insert(int data, int n) {
      if(n == 0) {
         insertStart(data);
         return;
      }
      Node* temp = head;
      for(int i = 0; i < n-1; i++) {
         temp = temp->next;
         if(temp == NULL) {
            printf("Index Out Of Bound\n");
         }
      }
      Node* newNode = new Node;
      newNode->next = temp->next;
      newNode->data = data;
      temp->next = newNode;
   }

   void Delete(int n) {
      Node* temp = head;
      if(n == 0) {
         head = temp->next;
         delete temp;
         return;
      }
      for(int i = 0; i < n-1; i++) {
         temp = temp->next;
         if(temp->next == NULL) {
            printf("Index Out Of Bound\n");
            return;
         }
      }
      Node* del = temp->next;
      temp->next = del->next;
      delete del;
   }
   
   void Reverse() {
      Node* curr = head;
      Node* next;
      Node* prev = NULL;
      while(curr != NULL) {
         next = curr->next;
         curr->next = prev;
         prev = curr;
         curr = next;
      }
      head = prev;
   }

   void R(Node* a) {
      if(a->next == NULL) {
         head = a;
         return;
      }
      R(a->next);
      Node* b = a->next;
      b->next = a;
      a->next = NULL;
   }
};
typedef struct LinkedList LL;

int main() {
   LL head;

   head.printForward();
   head.insertEnd(7);
   head.insertStart(4);

   head.printForward();
   head.insertStart(2);
   head.insertEnd(10);
   head.insertEnd(13);

   head.printForward();
   head.Insert(6, 2);
   head.Insert(100, 6);
   head.Insert(1, 0);

   head.printForward();
   head.Delete(2);
   head.Delete(0);

   head.printForward();
   head.Insert(9, 3);
   head.printForward();

   head.Delete(6);
   head.printForward();

   head.Delete(6);
   head.Reverse();
   head.printForward();
   head.R(head.head);
   head.printForward();
   return 0;
}