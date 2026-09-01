#include <iostream>
#include <stack>
using namespace std;

bool isMatching(char open, char close) {
    return (open == '(' && close == ')') ||
           (open == '{' && close == '}') ||
           (open == '[' && close == ']');
}

int main() {
    string expression;
    
    cout << "Enter an expression: ";
    cin >> expression;

    stack<char> s;
    bool balanced = true;

    for (char ch : expression) {

        // If opening bracket, push into stack
        if (ch == '(' || ch == '{' || ch == '[') {
            s.push(ch);
        }

        // If closing bracket
        else if (ch == ')' || ch == '}' || ch == ']') {

            if (s.empty() || !isMatching(s.top(), ch)) {
                balanced = false;
                break;
            }

            s.pop();
        }
    }

    // Stack must be empty at the end
    if (!s.empty()) {
        balanced = false;
    }

    if (balanced)
        cout << "Expression has balanced parentheses.";
    else
        cout << "Expression does not have balanced parentheses.";

    return 0;
}
