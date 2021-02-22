#include <iostream>
using namespace std;

int main() {
    double res = 1;
    for (int i = 0; i < 3; ++i) {
        char ch;
        double a, b, c, s;
        cin >> a >> b >> c;
        s = max(a, max(b, c));
        if (s == a) ch = 'W';
        else if (s == b) ch = 'T';
        else ch = 'L';
        cout << ch << " ";
        res *= s;
    }
    printf("%.2lf\n", (res * 0.65 - 1) * 2);
    return 0;
}
