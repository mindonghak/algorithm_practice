#include <iostream>
using namespace std;
int mem;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, i, j, temp, max_ = -1000;
	bool check = false;
	cin >> n;
	for (i = 0, j = 0; i < n; i++) {
		cin >> temp;
		if (temp < 0) {
			if (mem < 0)mem = 0;
			check = false;
		}
		else {
			if (!check) {	//부호가 음수에서 양수 될 때
				if (mem < 0)mem = 0;
			}
			check = true;
		}
		mem += temp;
		if (max_ < mem)max_ = mem;
	}

	cout << max_;
	return 0;
}


