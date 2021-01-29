```c++
#include <iostream>

using namespace std;

const int N = 10010, M = 110;
int n, m;
int w[N];
int q[M];

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) scanf("%d", &w[i]);
    
    for (int i = 0; i < n; ++i) {
        int t = -1;
        for (int j = 0; j < m; ++j) {
            if (t == -1 || q[j] < q[t]) {
                t = j;
            }
        }
        q[t] += w[i];
    }
    int res = 0;
    for (int i = 0; i < m; ++i) res = max(res, q[i]);
    
    printf("%d\n", res);
    return 0;
}

```

