```c++
#include <iostream>
#include <algorithm>

using namespace std;

const int N = 1e6 + 10;
int n, m;
int list[N];

int binary_search(int x) {
    int l = 0, r = n - 1;
    while (l < r) {
        int mid = l + r >> 1;
        if (list[mid] >= x) r = mid;
        else l = mid + 1;
    }
    return list[r];
}

int main() {
    scanf("%d%d", &n, &m);
    for (int i = 0; i < n; ++i) scanf("%d", &list[i]);
    sort(list, list + n);
    while (m--) {
        int x;
        scanf("%d", &x);
        if (binary_search(x) == x) puts("YES");
        else puts("NO");
    }
    return 0;
}

```

