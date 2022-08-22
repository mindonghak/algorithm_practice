#include <iostream>
#include <cstdlib>
using namespace std;
int score[20][20];
int member[10], rest_member[10];
int n, total, min_=1000000000;
void dfs(int depth, int k) {
	int i, j, temp1=0, temp2;
	if (depth == n / 2) {
		for (i = 0; i < n / 2; i++) {
			for (j = 0; j < n / 2; j++) {
				if (i==j || i>j)continue;
				temp1 += score[member[i]][member[j]];
			}
		}
		for (i = 0, j = 0, temp2=0; i < n; i++) {
			if (i == member[temp2]) {
				temp2++;
				continue;
			}
			rest_member[j++] = i;
		}
		temp2 = 0;
		for (i = 0; i < n / 2; i++) {
			for (j = 0; j < n / 2; j++) {
				if (i == j || i > j)continue;
				temp2 += score[rest_member[i]][rest_member[j]];
			}
		}
		if ((temp1 = abs(temp1-temp2)) < min_)min_ = temp1;	
		return;
	}
	for (i = k; i < n;) {
		member[depth] = i;
		dfs(depth + 1, ++i);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int i, j, temp;
	cin >> n;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			cin >> temp;
			if (i == j)continue;
			if (i > j)score[j][i] += temp;
			else score[i][j] += temp;
		}
	}
	for (i = 0; i < n / 2; i++) {
		member[0] = i;
		dfs(1, i+1);
	}
	cout << min_;
	return 0;
}


