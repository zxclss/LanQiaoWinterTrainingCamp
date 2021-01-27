```c++
#include <iostream>
#include <cstring>
using namespace std;

const int N = 110;
int n, k;
int f[N][N];

int main() {
    scanf("%d%d", &n, &k);
    memset(f, -0x3f, sizeof f);
    f[0][0] = 0;
    for (int i = 1; i <= n; ++i) {
        int w;
        scanf("%d", &w);
        for (int j = 0; j < k; ++j)
            f[i][j] = max(f[i - 1][j], f[i - 1][(j + k - w % k) % k] + w);
    }
    printf("%d\n", f[n][0]);
    return 0;
}

```

