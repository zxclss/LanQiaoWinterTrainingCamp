#include <iostream>
#include <cstring>
using namespace std;

const int N = 510;
int n, m, c1, c2;
int g[N][N];
int people[N], sum_people[N], dist[N], cnt[N];
bool st[N];

void dijkstra() {
    memset(dist, 0x3f, sizeof dist);
    cnt[c1] = 1, sum_people[c1] = people[c1], dist[c1] = 0;
    for (int i = 0; i < n; ++i) {
        int t = -1;
        for (int j = 0; j < n; ++j)
            if (!st[j] && (t == -1 || dist[j] < dist[t]))
                t = j;
        st[t] = true;
        for (int j = 0; j < n; ++j) {
            if (dist[j] > dist[t] + g[t][j]) {
                dist[j] = dist[t] + g[t][j];
                cnt[j] = cnt[t];
                sum_people[j] = sum_people[t] + people[j];
            } else if (dist[j] == dist[t] + g[t][j]) {
                cnt[j] += cnt[t];
                if (sum_people[j] < sum_people[t] + people[j]) {
                    sum_people[j] = sum_people[t] + people[j];
                }
            }
        }
    }
}

int main() {
    memset(g, 0x3f, sizeof g);
    cin >> n >> m >> c1 >> c2;
    for (int i = 0; i < n; ++i) cin >> people[i];
    while (m--) {
        int a, b, c;
        cin >> a >> b >> c;
        g[a][b] = g[b][a] = c;
    }
    dijkstra();
    printf("%d %d\n", cnt[c2], sum_people[c2]);
    return 0;
}
