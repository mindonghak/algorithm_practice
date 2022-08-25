#include <iostream>
#include <algorithm>
using namespace std;
int mem[101][10];
int n;
int dfs(int depth, int k) {
	if (k < 0 || k > 9)return 0;
	if (depth == 1) return 1;
	if (mem[depth][k])return mem[depth][k];
	return mem[depth][k] = (dfs(depth - 1, k - 1) + dfs(depth - 1, k + 1))%1000000000;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n;
	if (n == 1) {
		cout << 9;
		return 0;
	}
	int result = 0;
	for (int i = 1; i <= 9; i++) {
		result += dfs(n, i);
		result %= 1000000000;
	}
	cout << result % 1000000000;
	return 0;
}


