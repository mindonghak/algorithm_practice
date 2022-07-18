#include <iostream>
using namespace std;
char memo[10000][10000];
void star(int n);
int main() {
	cin.tie(nullptr);
	ios::sync_with_stdio(false);
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			memo[i][j] = ' ';
		}
	}
	star(n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << memo[i][j];
		}
		cout << '\n';
	}
	return 0;
}

void star(int n) {
	if (n == 3) {
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				if (i * j == 1)continue;
				memo[i][j] = '*';
			}
		}
		return;
	}
	star(n / 3);
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (!i && !j)continue;
			if (i * j == 1)continue;
			for (int k = 0; k < n / 3; k++) {
				for (int u = 0; u < n / 3; u++) {
					memo[i * n / 3 + k][j * n / 3 + u] = memo[k][u];
				}
			}
		}
	}
}