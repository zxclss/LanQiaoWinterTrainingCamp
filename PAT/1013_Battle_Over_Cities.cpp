#include <iostream>
using namespace std;

const int N = 1010, M = N * N;
int n, m, k;
int p[N];
struct Edge {
	int a, b;
}edges[M];

int find(int u) {
	if (p[u] != u) p[u] = find(p[u]);
	return p[u];
}
void kruskal(int id) {
	for (int i = 0; i < m; ++i) {
		if (edges[i].a == id || edges[i].b == id) continue;
		int a = find(edges[i].a), b = find(edges[i].b);
		if (a != b) {
			p[a] = b;
		}
	}
}
int main() {
	cin >> n >> m >> k;
	for (int i = 0; i < m; ++i) cin >> edges[i].a >> edges[i].b;
	while (k--) {
		int id;
		cin >> id;
		for (int i = 1; i <= n; ++i) p[i] = i;
		int cnt = 0;
		kruskal(id);
		for (int i = 1; i <= n; ++i) if (i != id && p[i] == i) ++cnt;
		cout << cnt - 1 << endl;
	}
	return 0;
}