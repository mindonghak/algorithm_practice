#include <iostream>
int n, k;
int a[9];
using namespace std;
void dfs(int cnt, int st) {
	if (cnt == k) {
		for (int i = 0; i < cnt; i++) {
			cout << a[i] << ' ';
		}
		cout << '\n';
		return;
	}
	for (int i = st; i <= n; i++) {
		a[cnt] = i;
		dfs(cnt + 1,i);
	}
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin >> n >> k;
	dfs(0,1);

	return 0;
}


