#include <iostream>
int n, k;
int a[9];
using namespace std;
void dfs(int cnt) {
	if (cnt == k) {
		for (int i = 0; i < cnt; i++) {
			cout << a[i] << ' ';
		}
		cout << '\n';
		return;
	}
	for (int i = 1; i <= n; i++) {
		a[cnt] = i;
		dfs(cnt + 1);
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> k;
	dfs(0);

	return 0;
}


