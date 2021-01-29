```c++
#include <iostream>

using namespace std;

typedef long long LL;

LL por, psum;

int main() {
    cin >> por >> psum;
    if (por > psum) puts("Impossible");
    else {
        LL pand = psum - por;
        if ((pand & por) == pand) puts("Possible");
        else puts("Impossible");
    }
    return 0;
}
```

