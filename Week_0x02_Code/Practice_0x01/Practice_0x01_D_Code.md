```c++
#include <iostream>
#include <unordered_map>
using namespace std;

int main() {
    int n, res = 0;
    unordered_map<int, int> cnt;
    scanf("%d", &n);
    for (int i = 0; i < n; ++i) {
        int x;
        scanf("%d", &x);
        ++cnt[x];
        if (cnt[res] < cnt[x] || cnt[res] == cnt[x] && x < res) res = x;
    }
    printf("%d\n", res);
    return 0;
}
```

