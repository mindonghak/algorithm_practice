#include <iostream>
#include <algorithm>
using namespace std;
int memo[1000];
int main() {
	int n, i;
	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> memo[i];
	}
	sort(memo, memo + n);
	for (i = 0; i < n; i++) {
		cout << memo[i] << '\n';
	}
	return 0;
}