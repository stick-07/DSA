#include <stdio.h>
#include <stdlib.h>

struct Node {
   int data;
   Node* next;
};

void printForward(Node* head) {
   printf("Linked List: ");
   while(head != NULL) {
      printf("%d ", head->data, head->next);
      head = head->next;
   }
   printf("\n");
}

Node* insertEnd(Node* head, int data) {
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
   return head;
}

Node* insertStart(Node* head, int data) {
   Node* newNode = new Node;
   newNode->data = data;
   newNode->next = head;
   head = newNode;
   return head;
}

Node* Insert(Node* head, int data, int n) {
   if(n == 0) {
      head = insertStart(head, data);
   } else {
      Node* temp = head;
      for(int i = 0; i < n-1; i++) {
         temp = temp->next;
         if(temp == NULL) {
            printf("Index Out Of Bound\n");
            return head;
         }
      }
      Node* newNode = new Node;
      newNode->next = temp->next;
      newNode->data = data;
      temp->next = newNode;
   }
   return head;
}

Node* Delete(Node* head, int n) {
   Node* temp = head;
   if(n == 0) {
      head = temp->next;
      delete temp;
   } else {
      for(int i = 0; i < n-1; i++) {
         temp = temp->next;
         if(temp->next == NULL) {
            printf("Index Out Of Bound\n");
            return head;
         }
      }
      Node* del = temp->next;
      temp->next = del->next;
      delete del;
   }
   return head;
}

Node* Reverse(Node* head) {
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
   return head;
}

Node* R(Node* head) {
   Node* a = head;
   if(a->next == NULL) {
      head = a;
      return head;
   }
   R(a->next);
   Node* b = a->next;
   b->next = a;
   a->next = NULL;
   return head;
}

int main() {
   Node* head = NULL;

   printForward(head);
   head = insertEnd(head, 7);
   head = insertStart(head, 4);

   printForward(head);
   head = insertStart(head, 2);
   head = insertEnd(head, 10);
   head = insertEnd(head, 13);

   printForward(head);
   head = Insert(head, 6, 2);
   head = Insert(head, 100, 6);
   head = Insert(head, 1, 0);

   printForward(head);
   head = Delete(head, 2);
   head = Delete(head, 0);

   printForward(head);
   head = Insert(head, 9, 3);
   printForward(head);

   head = Delete(head, 6);
   printForward(head);

   head = Delete(head, 6);
   head = Reverse(head);
   printForward(head);
   head = R(head);
   printForward(head);
   return 0;
}