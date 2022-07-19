#include <iostream>
using namespace std;
char chess[50][50];
char check[2][8][8];
int main() {
	int n, m, i, j, u,v,k, Count=10000, temp;
	char tr;
	cin >> n >> m;
	for (i = 0; i < n; i++) {
		for (j = 0; j < m; j++) {
			cin >> chess[i][j];
		}
	}
	k = 0;
	for (i = 0; i < 8; i++) {
		for (j = 0; j < 8; j++) {
			if (k)check[0][i][j] = 'W';
			else check[0][i][j] = 'B';
			k = 1 - k;
		}
		k = 1 - k;
	}
	k = 1;
	for (i = 0; i < 8; i++) {
		for (j = 0; j < 8; j++) {
			if (k)check[1][i][j] = 'W';
			else check[1][i][j] = 'B';
			k = 1 - k;
		}
		k = 1 - k;
	}
	for (i = 0; i < n-7; i++) {
		for (j = 0; j < m-7; j++) {
			for (k = 0; k < 2; k++) {
				temp = 0;
				for (u = 0; u < 8; u++) {
					for (v = 0; v < 8; v++) {
						if (check[k][u][v] != chess[i + u][j + v])temp++;
					}
				}
				if (Count > temp)Count = temp;
			}
		}
	}
	cout << Count;
	return 0;
}