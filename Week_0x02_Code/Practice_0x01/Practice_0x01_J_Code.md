```c++
#include <iostream>
#include <cstring>
using namespace std;

const int N = 10;

int T, n, m, sx, sy;
int res = 0;
bool g[N][N];
int dx[] = {2, 2, 1, -1, -2, -2, -1, 1};
int dy[] = {-1, 1, 2, 2, 1, -1, -2, -2};

void dfs(int u, int x, int y) {
    //terminator
    if (u == n * m) {
        ++res;
        return;
    }
    //drill down
    for (int i = 0; i < 8; ++i) {
        int tx = x + dx[i];
        int ty = y + dy[i];
        if (tx < 0 || tx >= n || ty < 0 || ty >= m || g[tx][ty]) continue;
        // cout << tx << " " << ty << endl;
        g[tx][ty] = true;
        dfs(u + 1, tx, ty);
        g[tx][ty] = false;;
    }
}

int main() {
    cin >> T;
    while (T--) {
        memset(g, 0, sizeof g);
        res = 0;
        
        cin >> n >> m >> sx >> sy;
        g[sx][sy] = true;
        dfs(1, sx, sy);
        cout << res << endl;
    }
    
    return 0;
}

```

