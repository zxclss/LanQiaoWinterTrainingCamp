```c++
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    while (n--) {
        int x, res = -1;
        cin >> x;
        while (x) {
            ++res;
            if (x & 1 && x != 1) ++res;
            x >>= 1;
        }
        cout << res << endl;
    }
    return 0;
}
```

