```c++
#include <iostream>
using namespace std;

const int N = 1e6 + 10;

int n, m;
int p[N];

int find(int u) {
    if (p[u] != u) p[u] = find(p[u]);
    return p[u];
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 1; i <= n; ++i) p[i] = i;
    
    while (m--) {
        int a, b;
        scanf("%d%d", &a, &b);
        if (find(a) != find(b)) {
            p[find(a)] = p[b];
        }
    }
    
    int sum = 0;
    for (int i = 1; i <= n; ++i) if (p[i] == i) ++ sum;
    printf("%d\n", sum);
    
    return 0;
}
```

