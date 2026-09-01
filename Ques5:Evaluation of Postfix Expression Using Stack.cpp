#include <iostream>
#include <stack>
#include <cmath>
using namespace std;

int main() {
    string postfix;

    cout << "Enter postfix expression: ";
    cin >> postfix;

    stack<int> s;

    for (char ch : postfix) {

        // If character is an operand
        if (ch >= '0' && ch <= '9') {
            s.push(ch - '0');
        }

        // If character is an operator
        else {
            int b = s.top();
            s.pop();

            int a = s.top();
            s.pop();

            int result;

            switch (ch) {
                case '+':
                    result = a + b;
                    break;

                case '-':
                    result = a - b;
                    break;

                case '*':
                    result = a * b;
                    break;

                case '/':
                    result = a / b;
                    break;

                case '^':
                    result = pow(a, b);
                    break;

                default:
                    cout << "Invalid operator!";
                    return 0;
            }

            s.push(result);
        }
    }

    cout << "Result = " << s.top();

    return 0;
}
