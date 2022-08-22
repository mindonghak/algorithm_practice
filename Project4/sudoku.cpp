#include <iostream>
#include <utility>
#include <set>
using namespace std;
typedef pair <int, int> p;
set <p> s;
int sdk[10][10];

void dfs(set<p>::iterator iter) {
	int n, i, j;
	if (iter == s.end()) {
		for (i = 1; i < 10; i++) {
			for (j = 1; j < 10; j++) {
				cout << sdk[i][j] << ' ';
			}
			cout << '\n';
		}
		exit(0);
	}
	p ff = *iter;
	bool check;
	for (n = 1; n <= 9; n++) {
		check = false;
		for (i = 1; i <= 9; i++) {
			if (n == sdk[ff.first][i]) {
				check = true;
				break;
			}
		}
		if (check)continue;
		for (i = 1; i <= 9; i++) {
			if (n == sdk[i][ff.second]) {
				check = true;
				break;
			}
		}
		if (check)continue;
		for (i = ((ff.first - 1) / 3) * 3 + 1; i < ((ff.first - 1) / 3) * 3 + 4; i++) {
			for (j = ((ff.second - 1) / 3) * 3 + 1; j < ((ff.second - 1) / 3) * 3 + 4; j++) {
				if (n == sdk[i][j]) {
					check = true;
					break;
				}
			}
		}
		if (check)continue;
		sdk[ff.first][ff.second] = n;
		dfs(next(iter,1));
	}
	sdk[ff.first][ff.second] = 0;
}
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int i, j;
	for (i = 1; i < 10; i++) {
		for (j = 1; j < 10; j++) {
			cin >> sdk[i][j];
			if (!sdk[i][j]) {
				s.insert({ i,j });
			}
		}
	}
	dfs(s.begin());
	cout << '\n';
	

	return 0;
}


