```c++
#include <iostream>
using namespace std;

int main() {
    int T;
    cin >> T;
    while (T--) {
        int x, res = 1;
        cin >> x;
        while (x > 7) {
            x -= 7;
            ++res;
        }
        cout << res << endl;
    }
    return 0;
}
```

