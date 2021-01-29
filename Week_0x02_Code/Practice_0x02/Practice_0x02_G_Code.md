```c++
#include <iostream>

using namespace std;

//a * b + a + b = a * 1eN + b (N取决于b的位数)
/*
    a * b + a  = a * 1eN
    b - 1 = 1eN
    b = 1eN - 1
    b = 9, 99, 999, ...
*/

typedef long long LL;

int n;
LL a, b;

int main() {
    scanf("%d", &n);
    while (n--) {
        scanf("%lld%lld", &a, &b);
        int cnt = 0, LL = 9;
        while (b >= LL) {
            ++cnt;
            LL = LL * 10 + 9;
        }
        printf("%lld\n", a * cnt);
    }
    return 0;
}
```

