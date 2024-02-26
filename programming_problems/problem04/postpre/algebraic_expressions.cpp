#include <string>
using std::string;

#include <iostream>

#include <cctype> // for isalpha

#include "algebraic_expressions.hpp"

#include <stack>
#include <vector>

bool isoperator(char ch) {
  return ((ch == '+') || (ch == '-') || (ch == '/') || (ch == '*'));
}

int endPost(string s, int last) {
  int first = 0;

  if ((first > last)) {
    return -1;
  }

  char ch = s[last];
  if (isalpha(ch)) {
    return last;
  } else {
    if (isoperator(ch)) {
      int lastEnd = endPost(s, last - 1);
      if (lastEnd > -1) {
        return endPost(s, lastEnd - 1);
      } else {
        return -1;
      }
    } else {
      return -1;
    }
  }
}

bool isPost(string s) {
  int firstChar = endPost(s, s.size() - 1);

  return (firstChar == 0);
}

void convert(std::string &postfix, std::string &prefix) {
  std::stack<std::string, std::vector<std::string>> stack;


  for (std::string::iterator it = postfix.begin(); it != postfix.end(); ++it) {
    char ch = *it;
    if (isalpha(ch)) {
      stack.push(std::string(1, ch));
    } else if (isoperator(ch)) {
      if (stack.size() < 2) {
        return;
      }
      std::string operand2 = stack.top();
      stack.pop();
      std::string operand1 = stack.top();
      stack.pop();

      std::string newOperand = ch + operand1 + operand2;

      stack.push(newOperand);
    } else {
      return;
    }
  }

  if (!stack.empty()) {
    prefix = stack.top();
  } else {
    return;
  }
}