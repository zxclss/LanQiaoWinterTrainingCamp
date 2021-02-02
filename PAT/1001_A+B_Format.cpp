#include <iostream>
using namespace std;

int main() {
    int a, b;
    cin >> a >> b;
    string res, sum(to_string(a + b));
    for (int i = sum.size() - 1, t = 0; i >= 0; --i, ++t) {
        //特判负数的符号位
        if (t == 3 && sum[i] != '-') {
            res = "," + res;
            t = 0;
        }
        res = sum[i] + res;
    }
    cout << res << endl;
    return 0;
}
