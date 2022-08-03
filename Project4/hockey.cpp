#include <iostream>
#include <cstdlib>
#include <cmath>
using namespace std;
int Count;
bool condition[3];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int i, w, h, x, y, n, c[2], xr[2], yr[2], r;
	cin >> w >> h >> x >> y >> n;
	r = h / 2;	//반지름
	xr[0] = x;	//왼쪽 원 중심
	yr[0] = y + r;
	xr[1] = x + w;	//오른쪽 원 중심
	yr[1] = y + r;
	for (i = 0; i < n; i++) {
		cin >> c[0] >> c[1];
		condition[0] = pow(xr[0] - c[0], 2) + pow(yr[0] - c[1], 2) - pow(r, 2) <= 0 ? 1 : 0; //왼쪽 원 안에있는지
		condition[1] = c[0] >= x && c[1] >= y && c[0] <= x + w && c[1] <= y + h;	//직사각형 안에 있는지
		condition[2] = pow(xr[1] - c[0], 2) + pow(yr[1] - c[1], 2) - pow(r, 2) <= 0 ? 1 : 0; //오른쪽 원 안에있는지
		Count += condition[0] || condition[1] || condition[2];
	}
	cout << Count;
	
	return 0;
}