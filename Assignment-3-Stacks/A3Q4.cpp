#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cout << "Enter infix expression: ";
    cin >> s;

    char st[1000];
    int top = -1;
    string out = "";

    for (int i = 0; s[i] != '\0'; i++) {
        char ch = s[i];

        if ((ch >= '0' && ch <= '9') || (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z')) {
            out = out + ch;
        }
        else if (ch == '(') {
            st[++top] = ch;
        }
        else if (ch == ')') {
            while (top != -1 && st[top] != '(') {
                out = out + st[top--];
            }
            if (top != -1 && st[top] == '(') 
            top--;
        }
        else {
            int p;
            if (ch == '+' || ch == '-') 
            p = 1;
            else if (ch == '*' || ch == '/') 
            p = 2;
            else if (ch == '^') 
            p = 3;
            else 
            p = 0;

            while (top != -1 && st[top] != '(') {
                int q;
                if (st[top] == '+' || st[top] == '-') 
                q = 1;
                else if (st[top] == '*' || st[top] == '/') 
                q = 2;
                else if (st[top] == '^') 
                q = 3;
                else 
                q = 0;

                if (q >= p) {
                    out = out + st[top--];
                } else 
                break;
            }
            st[++top] = ch;
        }
    }

    while (top != -1) {
        if (st[top] != '(')
         out = out + st[top];
        top--;
    }

    cout << "Postfix: " << out << "\n";
    return 0;
}
