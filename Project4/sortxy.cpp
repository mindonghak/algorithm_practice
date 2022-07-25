#include <iostream>
#include <algorithm>
using namespace std;
struct XY {
	int x;
	int y;
};
XY xy[100000];
bool compare(XY a, XY b) {
	if (a.x == b.x)return a.y < b.y;
	return a.x < b.x;
}
int main() {
	int n, i, y;
	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> xy[i].x >> xy[i].y;
	}
	sort(xy, xy + n, compare);
	for (i = 0; i < n; i++) {
		cout << xy[i].x <<' '<< xy[i].y<<'\n';
	}

	return 0;
}