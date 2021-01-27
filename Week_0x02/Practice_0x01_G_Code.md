```c++
#include <iostream>
#include <queue>
using namespace std;

typedef pair<int, int> PII;
const int N = 21;

int n, m;
int sx, sy; //startX, startY
char g[N][N];

int bfs() {
    int res = 0;
    queue<PII> q;
    q.push({sx, sy});
    
    int dx[] = {1, 0, -1, 0}, dy[] = {0, 1, 0, -1};
    
    while (!q.empty()) {
        ++res;
        int len = q.size();
        for (int i = 0; i < len; ++i) {
            auto t = q.front();
            q.pop();
            int x = t.first, y = t.second;
            // cout << x << " " << y << endl;
            
            for (int d = 0; d < 4; ++d) {
                int tx = x + dx[d], ty = y + dy[d];
                if (tx < 0 || tx == n || ty < 0 || ty == m || g[tx][ty] == '#') continue;
                if (g[tx][ty] == '*') return res;
                q.push({tx, ty});
                g[tx][ty] = '#';
            }
        }
        
    }
    
    return -1;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> g[i][j];
            if (g[i][j] == '@')
                sx = i, sy = j;
        }
    }
    cout << bfs() << endl;
    return 0;
}
```

