#include <iostream>
#include <queue>
using namespace std;

const int N = 25, M = 12, K = 1010;
int n, m, k, Q;
queue<int> q[N];
int sum[N];
int finish_time[K];

int main() {
	cin >> n >> m >> k >> Q;
	int end_time = 540;
	for (int i = 1; i <= k; ++i) {
		int serve_time;
		cin >> serve_time;
		int t = 0;
		if (i <= n * m) {
			for (int j = 1; j < n; ++j)
				if (q[t].size() > q[j].size())
					t = j;
		}
		else {
			for (int j = 1; j < n; ++j)
				if (q[t].front() > q[j].front())
					t = j;
		}
		if (i > n * m) q[t].pop();
		sum[t] += serve_time;
		q[t].push(sum[t]);
		if (sum[t] - serve_time >= end_time) finish_time[i] = 0;
		else finish_time[i] = sum[t];
	}
	while (Q--) {
		int id;
		cin >> id;
		if (!finish_time[id]) puts("Sorry");
		else printf("%02d:%02d\n", finish_time[id] / 60 + 8, finish_time[id] % 60);
	}
	return 0;
}