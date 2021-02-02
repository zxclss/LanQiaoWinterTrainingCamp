#include <iostream>
using namespace std;

const int N = 1010;

int n, m, s;
double a[N], b[N], c[N];

int main() {
    cin >> n;
    while (n--) {
        int p;
        double x;
        cin >> p >> x;
        a[p] = x;
    }
    cin >> m;
    while (m--) {
        int p;
        double x;
        cin >> p >> x;
        b[p] = x;
    }
    for (int i = 0; i < N; ++i) c[i] = a[i] + b[i];
    for (int i = 0; i < N; ++i) if (c[i]) ++s;
    printf("%d", s);
    for (int i = N - 1; i >= 0; --i)
        if (c[i])
            printf(" %d %.1lf", i, c[i]);
    printf("\n");
    return 0;
}
