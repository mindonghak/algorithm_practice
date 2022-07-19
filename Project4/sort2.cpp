#include <iostream>
#include <algorithm>
using namespace std;
int memo[10001];
int main() {
	int n, i, j, temp;
	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> temp;
		memo[temp]++;
	}
	for (i = 1; i <= 10000; i++) {
		if (!memo[i])continue;
		for (j = 0; j < memo[i]; j++) {
			cout << i << '\n';
		}
	}
	return 0;
}