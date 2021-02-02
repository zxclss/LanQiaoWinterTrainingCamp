#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

const int N = 110;
int n, m;
vector<int> child[N];
int cnt[N], maxdepth;

void dfs(int u, int depth) {
    maxdepth = max(depth, maxdepth);
    if (child[u].empty()) {
        ++cnt[depth];
        return;
    }
    for (auto it: child[u]) {
        dfs(it, depth + 1);
    }
}

int main() {
    cin >> n >> m;
    while (m--) {
        int a, b, c;
        cin >> a >> b;
        while (b--) {
            cin >> c;
            child[a].push_back(c);
        }
    }
    dfs(1, 0);
    cout << cnt[0];
    for (int i = 1; i <= maxdepth; ++i) cout << " " << cnt[i];
    return 0;
}


