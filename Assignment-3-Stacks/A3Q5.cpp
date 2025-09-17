#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;

    int st[1000];
    int top = -1;

    for (int i = 0; s[i] != '\0'; i++) {
        char ch = s[i];

        if (ch >= '0' && ch <= '9') {
            st[++top] = ch - '0';
        } else {
            if (top < 1) {
                cout << "Error\n";
                return 0;
            }

            int b = st[top--];
            int a = st[top--];
            int r;

            if (ch == '+') r = a + b;
            else if (ch == '-') r = a - b;
            else if (ch == '*') r = a * b;
            else if (ch == '/') r = a / b;
            else if (ch == '^') {
                r = 1;
                for (int k = 0; k < b; k++) r = r * a;
            } else {
                cout << "Error\n";
                return 0;
            }

            st[++top] = r;
        }
    }

    if (top == 0) cout << st[top] << "\n";
    else cout << "Error\n";

    return 0;
}
