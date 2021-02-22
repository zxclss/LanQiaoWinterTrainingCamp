#include <iostream>
using namespace std;

bool is_prime(int n) {
	if (n < 2) return false;
	for (int i = 2; i <= n / i; ++i) {
		if (n % i == 0) return false;
	}
	return true;
}
bool check(int n, int k) {
	if (!is_prime(n)) return false;

	int r = 0;
	while (n) {
		r = r * k + n % k;
		n /= k;
	}
	return is_prime(r);
}
int main() {
	int n, k;
	while (cin >> n >> k, n >= 1) {
		if (check(n, k)) puts("Yes");
		else puts("No");
	}
	return 0;
}