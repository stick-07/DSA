#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <stack>
#include <string>
#include <math.h>

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

void evaluatePrefix(string expression) {
   stack<int> s;
   int len = expression.length();
   for(int i = len - 1; i >= 0; i--) {
      if(expression[i] == ' ') {
         continue;
      } else if(isdigit(expression[i])) {
         int operand = 0;
         float power = 0;
         while(i >= 0 && isdigit(expression[i])) {
            operand += (expression[i] - '0') * int(pow(10, power));
            power++;
            i--;
         }
         s.push(operand);
         i++;
      } else if(isOperator(expression[i])) {
         if(s.size() < 2) {
            cout << "Error.";
            return;
         }
         int op1 = s.top();
         s.pop();
         int op2 = s.top();
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
   evaluatePrefix(expression);
   return 0;
}