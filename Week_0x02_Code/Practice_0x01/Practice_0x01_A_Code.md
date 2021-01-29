```c++
#include <iostream>
#include <unordered_set>
using namespace std;

const int N = 1e5 + 10;

int n, m;
int a[N];

int main() {
    //in
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) scanf("%d", &a[i]);
    scanf("%d", &m);
    
    //process
    unordered_set<int> hash;
    int left = 1e9, right;
    for (int i = 0; i < n; ++i) {
        int x = a[i], y = m - a[i];
        if (hash.count(y)) {
            if (x > y) swap(x, y);
            if (left > x) left = x, right = y;
        }
        hash.insert(x);
    }
    
    //out
    if (left == 1e9) puts("No");
    else printf("%d %d\n", left, right);
    return 0;
}
```

