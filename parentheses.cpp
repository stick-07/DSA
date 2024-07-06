#include <stdio.h>
#include <stdlib.h>
#include <stack>
#include <unordered_map>

using namespace std;

void parentheses_check(char string[]) {
   unordered_map<char, char> pmap = {{'(', ')'}, {'[', ']'}, {'{', '}'}};
   stack<char> s;
   int len = 0;
   while(string[len] != '\0') {
      len++;
   }
   for(int i = 0; i < len; i++) {
      char c = string[i];
      if(c == '(' || c == '[' || c == '{') {
         s.push(c);
      } else if(c == ')' || c == ']' || c == '}') {
         if(s.empty() || c != pmap[s.top()]) {
            printf("Parentheses Unbalanced");
            return;
         }
         s.pop();
      }
   }
   if(s.empty()) {
      printf("Parantheses Balanced");
      return;
   }
   printf("Parentheses Unbalanced");
}

int main() {
   char string[50];
   printf("String: ");
   scanf("%s", &string);
   parentheses_check(string);
   return 0;
}