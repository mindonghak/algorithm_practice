#include <iostream>
#include <algorithm>
using namespace std;
int rgb[1001][3];
int mem[1001][3];
int min_ = 1000000;
int n;
int dfs(int depth, int k) {
	if (mem[depth][k])return mem[depth][k];
	if (depth==n-1) {
		return rgb[depth][k];
	}
	int i, j;
	int temp[2];
	for (i = 0, j = 0; i < 3; i++) {
		if (i == k)continue;
		temp[j++] = dfs(depth + 1, i);
	}
	return mem[depth][k] = rgb[depth][k] + min(temp[0], temp[1]);
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int i, j;
	cin >> n;
	for (i = 0; i < n; i++) {
		for (j = 0; j < 3; j++) {
			cin >> rgb[i][j];
		}
	}
	for (i = 0; i < 3; i++) {
		int temp = dfs(0, i);
		if (min_ > temp)min_ = temp;
	}
	cout << min_;

	return 0;
}


