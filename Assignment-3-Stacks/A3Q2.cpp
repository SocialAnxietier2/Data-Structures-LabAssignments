#include <iostream>
#include <string>
using namespace std;

int main() {
    string s;
    cin >> s;

    char st[1000];
    int top = -1;

    int i = 0;
    while (s[i] != '\0') {
        st[++top] = s[i];
        i++;
    }

    string out = "";
    while (top != -1) {
        out = out + st[top--];
    }

    cout << out << "\n";
    return 0;
}
