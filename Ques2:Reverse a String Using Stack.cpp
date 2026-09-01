#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    string str;

    cout << "Enter a string: ";
    cin >> str;

    stack<char> s;

    // Push each character into stack
    for (char ch : str) {
        s.push(ch);
    }

    cout << "Reversed string: ";

    // Pop characters to get reverse order
    while (!s.empty()) {
        cout << s.top();
        s.pop();
    }

    return 0;
}
