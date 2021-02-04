#include <iostream>
using namespace std;

const int N = 10010;
int n;
int w[N];
int f[N];

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i) cin >> w[i];
    for (int i = 1; i <= n; ++i) f[i] = max(0, f[i - 1]) + w[i];

    int res = -1, l, r;
    for (int i = 1, ltmp = 0; i <= n; ++i) {
        if (f[i] < 0) ltmp = i;
        if (res < f[i]) res = f[i], l = ltmp, r = i;
    }
    if (res < 0) res = 0, l = 0, r = n;
    cout << res << " " << w[l + 1] << " " << w[r] << endl;
    return 0;
}
