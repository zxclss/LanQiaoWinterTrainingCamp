#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;

    int res = 0, prev = 0;
    while (n--) {
        int next;
        cin >> next;
        if (next >= prev) res += (next - prev) * 6 + 5;
        else res += (prev - next) * 4 + 5;
        prev = next;
    }
    cout << res << endl;
    return 0;
}
