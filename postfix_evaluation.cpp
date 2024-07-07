#include <stdio.h>
#include <stdlib.h>
#include <stack>
#include <string>
#include <iostream>

using namespace std;

bool isOperator(char c) {
   if(c == '+' || c == '-' || c == '*' || c == '/') {
      return true;
   }
   return false;
}

int performOperation(int a, int b, char c) {
   if(c == '+') {
      return a + b;
   } else if(c == '-') {
      return a - b;
   } else if(c == '*') {
      return a * b;
   } else {
      return a / b;
   }
}

void evaluatePostfix(string expression) {
   stack<int> s;
   int len = expression.length();
   for(int i = 0; i < len; i++) {
      if(expression[i] == ' ') {
         continue;
      } else if(isdigit(expression[i])) {
         int operand = 0;
         while(i < len && isdigit(expression[i])) {
            operand = operand * 10 + (expression[i] - '0');
            i++;
         }
         s.push(operand);
         i--;
      } else if(isOperator(expression[i])) {
         if(s.size() < 2) {
            printf("Error.");
            return;
         }
            int op2 = s.top();
            s.pop();
            int op1 = s.top();
            s.pop();
            s.push(performOperation(op1, op2, expression[i]));
      } else {
         cout << "Error.";
         return;
      }
   }
   if(s.size() > 1) {
      cout << "Error.";
      return;
   }
   cout << "Result: " << s.top();
}

int main() {
   string expression;
   cout << "Expression: ";
   getline(cin, expression);
   evaluatePostfix(expression);
   return 0;
}