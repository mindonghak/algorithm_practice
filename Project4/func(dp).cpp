#include <iostream>
#include <cstdlib>
using namespace std;
int mem[51][51][51];
bool check[51][51][51];

int w(int a, int b, int c) {
	if (a <= 0 || b <= 0 || c <= 0) return 1;
	if (a > 20 || b > 20 || c > 20) {
		if (check[20][20][20])return mem[20][20][20];
		mem[a][b][c] = w(20, 20, 20);
		check[20][20][20] = true;
		return mem[a][b][c];
	}
	if (check[a][b][c])return mem[a][b][c];
	check[a][b][c] = true;
	if (a < b && b < c) {
		return mem[a][b][c] = w(a, b, c - 1) + w(a, b - 1, c - 1) - w(a, b - 1, c);
	}
	return mem[a][b][c] = w(a - 1, b, c) + w(a - 1, b - 1, c) + w(a - 1, b, c - 1) - w(a - 1, b - 1, c - 1);
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int a, b, c;
	while (cin>>a>>b>>c) {
		if (!(a + 1) && !(b + 1) && !(c + 1))break;
		printf("w(%d, %d, %d) = %d\n", a, b, c, w(a, b, c));
	}
	return 0;
}


