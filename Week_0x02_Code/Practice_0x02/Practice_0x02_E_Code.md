# 利用STL

```c++
#include <iostream>
using namespace std;
//不是这题，“输入有多组测试数据”就不能粗体打出来吗
int n, m;

int main() {
    while (cin >> n >> m) {
        string a, b;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                char ch;
                cin >> ch;
                a += tolower(ch);
            }
        }
        cin >> b;
        for (auto& ch: b) ch = tolower(ch);
        
        int pos = a.find(b);
        if (pos >= 0 && pos < a.size()) puts("YES");
        else puts("NO");
    }
    return 0;
}
```



# KMP算法

```c++
#include <iostream>
#include <cstring>
using namespace std;
//不是这题，“输入有多组测试数据”就不能粗体打出来吗
int n, m;
const int N = 910;
int prefix[N];

int main() {
    while (cin >> n >> m) {
        string a = " ", b;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                char ch;
                cin >> ch;
                a += tolower(ch);
            }
        }
        cin >> b;
        for (auto& ch: b) ch = tolower(ch);
        b = " " + b;
        
        //KMP
        memset(prefix, 0, sizeof prefix);
        for (int i = 2, j = 0; i < b.size(); ++i) {
            while (j != 0 && b[i] != b[j + 1]) j = prefix[j];
            if (b[i] == b[j + 1]) ++j;
            prefix[i] = j;
        }
        bool success = false;
        for (int i = 1, j = 0; i < a.size(); ++i) {
            while (j != 0 && a[i] != b[j + 1]) j = prefix[j];
            if (a[i] == b[j + 1]) ++j;
            if (j == b.size() - 1) {
                puts("YES");
                success = true;
                break;
            }
        }
        if (!success) puts("NO");
    }
    return 0;
}
```



# 字符串前缀哈希

```c++
#include <iostream>
#include <cstring>
using namespace std;
//不是这题，“输入有多组测试数据”就不能粗体打出来吗
const int N = 910, P = 13331;
typedef unsigned long long ULL;

int n, m;
ULL h[N], h2[N], p[N];

ULL get_hash(int l, int r, ULL h[]) {
    return h[r] - h[l-1] * p[r - l + 1];
}

int main() {
    while (cin >> n >> m) {
        string a = " ", b;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                char ch;
                cin >> ch;
                a += tolower(ch);
            }
        }
        cin >> b;
        for (auto& ch: b) ch = tolower(ch);
        b = " " + b;
        
        //字符串前缀哈希
        p[0] = 1;
        for (int i = 1; i < a.size(); ++i) {
            h[i] = h[i - 1] * P + a[i];
            p[i] = p[i - 1] * P;
        }
        for (int i = 1; i < b.size(); ++i) h2[i] = h2[i - 1] * P + b[i];
        
        bool success = false;
        ULL aim = get_hash(1, b.size() - 1, h2);
        ULL aim1 = get_hash(1, b.size() - 1, h);
        // cout << aim << " " << aim1 << endl;
        
        for (int i = 1; i + b.size() - 2 < a.size(); ++i) {
            int l = i, r = i + b.size() - 2;
            if (get_hash(l, r, h) == aim) {
                // cout << l << " " << r << endl;
                // cout << a.substr(l, b.size() - 1) << endl;
                puts("YES");
                success = true;
                break;
            }
        }
        if (!success) puts("NO");
    }
    return 0;
}
```

