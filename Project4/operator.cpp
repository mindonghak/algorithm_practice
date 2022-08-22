#include <iostream>
#include <utility>
#include <set>
using namespace std;
int num[11];
int oper[4];
int n, Max = -1000000000, Min = 1000000000;
void dfs(int value, int k) {
	if (k == n) {
		if (value > Max)Max = value;
		if (value < Min)Min = value;
		return;
	}
	int i, temp;
	for (i = 0; i < 4; i++) {
		if (!oper[i])continue;
		oper[i]--;
		if (i == 0) {
			dfs(value + num[k], k + 1);
		}
		else if (i == 1) {
			dfs(value - num[k], k + 1);
		}
		else if (i == 2) {
			dfs(value * num[k], k + 1);
		}
		else if (i == 3) {
			dfs(-((-value) / num[k]), k + 1);
		}
		oper[i]++;
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int i;
	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> num[i];
	}
	for (i = 0; i < 4; i++) {
		cin >> oper[i];
	}
	dfs(num[0],1);
	cout << Max << '\n' << Min;
	return 0;
}


