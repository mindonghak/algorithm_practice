#include <iostream>
using namespace std;
int x[50], y[50], Count[50];
int main() {
	int n, i, j;
	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> x[i] >> y[i];
	}
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			if (x[i] < x[j] && y[i] < y[j]) {
				Count[i]++;
			}
		}
	}
	for (i = 0; i < n; i++) {
		cout << Count[i] + 1 << ' ';
	}
	return 0;
}