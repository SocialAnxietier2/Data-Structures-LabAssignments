#include <iostream>
using namespace std;

int main() {
    const int N = 50;
    int quea[N], queb[N];
    int fa = 0, ra = 0, na = 0;
    int fb = 0, rb = 0, nb = 0;
    int ch, x;

    do {
        cout << "1 Push\n";
        cout << "2 Pop\n";
        cout << "3 Top\n";
        cout << "4 Display\n";
        cout << "5 Exit\n";
        cin >> ch;

        switch (ch) {
            case 1: {
                cin >> x;
                if (nb == N) {
                    cout << "Full\n";
                } else {
                    queb[rb] = x; rb = (rb + 1) % N; 
                    nb = nb + 1;
                    while (na > 0) {
                        int y = quea[fa]; fa = (fa + 1) % N;
                         na = na - 1;
                        queb[rb] = y; rb = (rb + 1) % N; 
                        nb = nb + 1;
                    }
                    while (nb > 0) {
                        int z = queb[fb]; fb = (fb + 1) %N; 
                        nb = nb - 1;
                        quea[ra] = z; ra = (ra + 1) % N; 
                        na = na + 1;
                    }
                    cout << "OK\n";
                }
                break;
            }
            case 2: {
                if (na == 0) {
                    cout << "Empty\n";
                } else {
                    int v = quea[fa]; fa = (fa + 1) % N; 
                    na = na - 1;
                    cout << v << "\n";
                }
                break;
            }
            case 3: {
                if (na == 0) {
                    cout << "Empty\n";
                } else {
                    cout << quea[fa] << "\n";
                }
                break;
            }
            case 4: {
                if (na == 0) {
                    cout << "Empty\n";
                } else {
                    for (int i = 0; i < na; i = i + 1) {
                        int idx = (fa + i) % N;
                        cout << quea[idx] << "\n";
                    }
                }
                break;
            }
            case 5: {
                break;
            }
            default: {
                cout << "invalid\n";
            }
        }
    } while (ch != 5);
    return 0;
}
