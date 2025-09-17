#include <iostream>
#include<string>
using namespace std;

int main() {
    string input;
    cout << "Enter an expression: ";
    cin >> input;   

    char stack[1000];
    int top = -1;

    for (int i = 0; input[i] != '\0'; i++) {
        char ch = input[i];

        if (ch == '(' || ch == '[' || ch == '{') {
            stack[++top] = ch;   
        }
        else if (ch == ')' || ch == ']' || ch == '}') {
            if (top == -1) {   // empty stack
                cout << "Not Balanced\n";
                return 0;
            }
            char t = stack[top--];   // pop
            if ((t == '(' && ch != ')') ||
                (t == '[' && ch != ']') ||
                (t == '{' && ch != '}')) {
                cout << "Not Balanced\n";
                return 0;
            }
        }
    }

    if (top == -1)
        cout << "Balanced\n";
    else
        cout << "Not Balanced\n";

    return 0;
}
