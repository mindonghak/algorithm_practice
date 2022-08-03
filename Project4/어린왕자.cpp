#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;
int Count;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int i, j, n, x[2], y[2], k, c[2], r;
	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> x[0] >> y[0] >> x[1] >> y[1];
		cin >> k;
		for (j = 0; j < k; j++) {
			cin >> c[0] >> c[1] >> r;
			if ((pow(x[0] - c[0], 2) + pow(y[0] - c[1], 2) - pow(r, 2)) * (pow(x[1] - c[0], 2) + pow(y[1] - c[1], 2) - pow(r, 2)) < 0) {
				Count++;
			}	//(x-x0)^2+(y-y0)^2-r^2의 부호에 따라 원의 내부인지 외부인지가 달라지고 곱해서 음수 즉, 부호가 다르면 내부 외부가 다름.
		}
		cout << Count<<'\n';
		Count = 0;
	}
	return 0;
}