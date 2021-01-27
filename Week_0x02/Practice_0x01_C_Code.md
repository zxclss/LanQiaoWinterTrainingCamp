```c++
#include <iostream>
#include <algorithm>
using namespace std;

int list[10];

int main() {
    int left = 0, right = 9;
    while (left <= right) {
        int x;
        cin >> x;
        if (x & 1) list[left++] = x;
        else list[right--] = x;
    }
    sort(list, list + left, greater<int>());
    sort(list + left, list + 10);
    for (int i = 0; i < 10; ++i) printf("%d ", list[i]);
    return 0;
}
```

