#include <stdio.h>
#include <stdlib.h>
#include <stack>
#include <unordered_map>
#include <string>
#include <iostream>

using namespace std;

void parentheses_check(string expression) {
   unordered_map<char, char> pmap = {{'(', ')'}, {'[', ']'}, {'{', '}'}};
   stack<char> s;
   int len = expression.length();
   for(int i = 0; i < len; i++) {
      char c = expression[i];
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
   string expression;
   cout << "Expression: ";
   cin >> expression;
   parentheses_check(expression);
   return 0;
}