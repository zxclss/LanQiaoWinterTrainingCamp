```c++
#include <iostream>
#include <cstring>

using namespace std;

/*
    f[i][0|1]: 只考虑前i家店的情况，0表示不偷第i店，1表示偷
             : 最大值
    f[i][0] = max(f[i-1][1], f[i-1][0]);
    f[i][1] = f[i-1][0] + cnt[i];
*/

const int N = 1e5 + 10;

int T, n;
int cnt[N];
int f[N][2];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) scanf("%d", &cnt[i]);
        
        for (int i = 1; i <= n; ++i) {
            f[i][0] = max(f[i - 1][1], f[i - 1][0]);
            f[i][1] = f[i - 1][0] + cnt[i];
        }
        printf("%d\n", max(f[n][0], f[n][1]));
    }
    return 0;
}
```

