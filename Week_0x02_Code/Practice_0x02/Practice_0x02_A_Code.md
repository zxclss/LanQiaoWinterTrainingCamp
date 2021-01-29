```C++
#include <iostream>
using namespace std;

int main() {
    int n;
    scanf("%d", &n);
    while (n--) {
        int x;
        scanf("%d", &x);
        int sum = 0, lid = 0, bottle = 0;
        while (x--) {
            ++sum, ++lid, ++bottle;
            if (lid % 3 == 0) ++x;
            if (bottle % 4 == 0) ++x;
        }
        printf("%d\n", sum);
    }
    return 0;
}
```

