#include <iostream>
using namespace std;

typedef long long LL;

int get(char ch) {
    if (isdigit(ch)) return ch - '0';
    return 10 + ch - 'a';
}

LL calc(string n, LL r) {
    LL res = 0;
    for (auto ch: n) {
        if ((double) res * r + get(ch) > 1e18) return 1e18;
        res = (LL)res * r + get(ch);
    }
    return res;
}

int main() {
    string n1, n2;
    int tag, radix;
    cin >> n1 >> n2 >> tag >> radix;

    if (tag == 2) swap(n1, n2);
    LL target = calc(n1, radix);

    LL l = 1, r = target + 1;
    for (auto ch: n2) l = max(l, (LL)get(ch) + 1);

    while (l < r) {
        LL mid = l + r >> 1;
        if (calc(n2, mid) >= target) r = mid;
        else l = mid + 1;
    }
    if (calc(n2, l) != target) puts("Impossible");
    else cout << l << endl;
    return 0;
}
