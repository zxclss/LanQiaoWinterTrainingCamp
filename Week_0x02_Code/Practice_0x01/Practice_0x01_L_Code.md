```c++
#include <iostream>
using namespace std;

const int N = 110;
int n;
int a[N];
bool out[N];

int main() {
    cin >> n;
    int idx = 0;
    //迭代删除n - 1个数，剩下的唯一一个就是获胜的老哥
    for (int k = 1; k < n; ++k) {
        for (int i = 0; i < 3; ++i) {
            ++idx;
            while (out[idx]) ++idx;
            if (idx > n) {
                idx = 1;
                while (out[idx]) ++idx;
            }
        }
        out[idx] = true;
    }
    for (int i = 1; i <= n; ++i) {
        if (!out[i]) {
            cout << i << endl;
            break;
        }
    }
    return 0;
}
```

