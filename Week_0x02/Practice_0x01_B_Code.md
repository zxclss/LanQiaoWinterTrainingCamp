```c++
#include <iostream>
#include <unordered_set>

using namespace std;

const int N = 1e5 + 10;
int n, m;
int a[N];

int main() {
    int n, m;
    unordered_set<int> hash;
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    for (int i = 0; i < m; ++i) {
        int x;
        scanf("%d", &x);
        hash.insert(x);
    }
    
    for (int i = 0; i < n; ++i) {
        if (hash.count(a[i])) {
            printf("%d ", a[i]);
        }
    }
    
    return 0;
}
```

