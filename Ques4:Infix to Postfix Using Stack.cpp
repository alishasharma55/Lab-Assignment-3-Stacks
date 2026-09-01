#include <iostream>
#include <stack>
#include <string>
using namespace std;

// Function to return precedence of operators
int precedence(char op) {
    if (op == '^')
        return 3;
    else if (op == '*' || op == '/')
        return 2;
    else if (op == '+' || op == '-')
        return 1;
    else
        return 0;
}

// Function to check whether character is an operand
bool isOperand(char ch) {
    return (ch >= 'A' && ch <= 'Z') ||
           (ch >= 'a' && ch <= 'z') ||
           (ch >= '0' && ch <= '9');
}

int main() {
    string infix, postfix = "";
    stack<char> s;

    cout << "Enter an infix expression: ";
    cin >> infix;

    for (char ch : infix) {

        // If operand, add directly to postfix
        if (isOperand(ch)) {
            postfix += ch;
        }

        // If opening parenthesis
        else if (ch == '(') {
            s.push(ch);
        }

        // If closing parenthesis
        else if (ch == ')') {

            while (!s.empty() && s.top() != '(') {
                postfix += s.top();
                s.pop();
            }

            if (!s.empty())
                s.pop();
        }

        // If operator
        else {
            while (!s.empty() &&
                   s.top() != '(' &&
                   precedence(s.top()) >= precedence(ch)) {

                postfix += s.top();
                s.pop();
            }

            s.push(ch);
        }
    }

    // Pop remaining operators
    while (!s.empty()) {
        postfix += s.top();
        s.pop();
    }

    cout << "Postfix expression: " << postfix;

    return 0;
}
