```c++
#include <iostream>
#include <cstring>
using namespace std;

typedef long long LL;

const int N = 1e5 + 10;
int T, n;
LL sum[N], q[N];

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        for (int i = 1; i <= n; ++i) {
            scanf("%lld", &sum[i]);
            sum[i] += sum[i - 1];
        }
        //单调队列DP
        LL res = 0;
        memset(q, 0, sizeof q);
        int hh = 0, tt = 0;
        for (int i = 1; i <= n; ++i) {
            if (q[hh] < i - n + 1) ++hh;
            res = max(res, sum[i] - sum[q[hh]]);
            while (hh <= tt && sum[q[tt]] >= sum[i])  --tt;
            q[++tt] = i;
        }
        if (res < sum[n]) puts("YES");
        else puts("NO");
    }
    return 0;
}
```

