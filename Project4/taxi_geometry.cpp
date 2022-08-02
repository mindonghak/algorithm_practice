#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, i, k, x[6], distance, radius[2];
	cin >> n;
	for (k = 0; k < n; k++) {
		for (i = 0; i < 6; i++) {
			cin >> x[i];
		}
		distance = pow(x[0] - x[3], 2) + pow(x[1] - x[4], 2);
		radius[0] = pow(x[2] + x[5], 2);
		radius[1] = pow(x[2] - x[5], 2);
		if (!distance && x[2] == x[5]) {
			cout << -1;
		}
		else if (!distance) {
			cout << 0;
		}
		else if (distance > radius[0] || distance < radius[1]) {
			cout << 0;
		}
		else if (distance == radius[0] || distance == radius[1]) {
			cout << 1;
		}
		else if (distance < radius[0] || distance > radius[1]) {
			cout << 2;
		}
		cout << '\n';
	}

	return 0;
}