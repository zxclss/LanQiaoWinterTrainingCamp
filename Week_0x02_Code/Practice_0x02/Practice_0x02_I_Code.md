```c++
#include <iostream>
#include <cmath>
using namespace std;
typedef long long LL;
/*
    p = gcd(a, b)
    n = lcm(a, b) = a * b / p;
*/

LL gcd(LL a, LL b) {
    return b == 0 ? a : gcd(b, a % b);
}
LL lcm(LL a, LL b) {
    return a * b / gcd(a, b);
}

int main() {
    LL n;
    cin >> n;
    LL res = 0;
    //枚举答案
    for (int i = 1; i <= n / i; ++i) {
        if (n % i == 0 && lcm(i, n / i) == n) {
            res = i;
        }
    }
    cout << res << " " << n / res << endl;
    return 0;
}
```

