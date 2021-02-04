#include <iostream>

using namespace std;

const int N = 1010;

double a[N], b[N], c[2 * N];

void input(double a[]) {
    int k;
    cin >> k;
    while (k--) {
        int n;
        double v;
        cin >> n >> v;
        a[n] = v;
    }
}

int main() {
    input(a);
    input(b);

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            c[i + j] += b[i] * a[j];
        }
    }

    int k = 0;
    for (int i = 0; i < 2 * N; ++i)
        if (c[i])
            ++k;

    cout << k;
    for (int i = 2 * N - 1; i >= 0; --i) {
        if (c[i]) {
            printf(" %d %.1lf", i, c[i]);
        }
    }

    return 0;
}

作者：彩色铅笔
链接：https://www.acwing.com/activity/content/code/content/677434/
来源：AcWing
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
