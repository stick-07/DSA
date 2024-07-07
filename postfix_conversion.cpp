#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
#include <string>
#include <unordered_map>

using namespace std;

bool isOperator(char c) {
   if(c == '+' || c == '-' || c == '*' || c == '/') {
      return true;
   }
   return false;
}

string infixToPostfix(string expression) {
   unordered_map<char, int> priority = {{'+', 0}, {'-', 0}, {'*', 1}, {'/', 1}};
   stack<char> s;
   string postfix;
   int len = expression.length();
   for(int i = 0; i < len; i++) {
      if(expression[i] == ' ') {
         continue;
      } else if(isdigit(expression[i])) {
         string operand = "";
         while(i < len && isdigit(expression[i])) {
            operand += expression[i];
            i++;
         }
         operand += ' ';
         postfix += operand;
         i--;
      } else if(isOperator(expression[i])) {
         if(!s.empty() && s.top() != '(' && priority[expression[i]] < priority[s.top()]) {
            while(!s.empty()) {
               postfix += s.top();
               postfix += ' ';
               s.pop();
            }
         }
         s.push(expression[i]);
      } else if(expression[i] == '(') {
         s.push(expression[i]);
      } else if(expression[i] == ')') {
         while(!s.empty() && s.top() != '(') {
               postfix += s.top();
               postfix += ' ';
               s.pop();
         }
         s.pop();
      }
      else {
         return "Error.";
      }
   }
   while(!s.empty()) {
      postfix += s.top();
      postfix += ' ';
      s.pop();
   }
   return postfix;
}

int main() {
   string infix;
   cout << "Infix: ";
   getline(cin, infix);
   string postfix = infixToPostfix(infix);
   cout << "Postfix: " << postfix;
}