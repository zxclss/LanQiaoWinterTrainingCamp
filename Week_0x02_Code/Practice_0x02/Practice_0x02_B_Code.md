```c++
#include <iostream>
using namespace std;

typedef long long LL;

int main() {
    LL n, p;
    cin >> n >> p;
    
    if (n == 1) {
        cout << p << endl;
        return 0;
    }
    
    LL res = 1;
    for (int i = 2; i <= p / i; ++i) {
        int sum = 0;
        while (p % i == 0) {
            ++sum;
            p /= i;
        }
        for (int j = 0; j < sum / n; ++j) res *= i;
    }
    cout << res << endl;
    return 0; 
}
```

