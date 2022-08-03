#include <iostream>
#include <cstdlib>
#include <cmath>
#include <set>
using namespace std;
set <int> s, m;
set <int, greater<int>> g;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int i, n, a[100], remainder, temp, gcd, small;
	cin >> n;
	for (i = 0; i < n; i++) {
		cin >> temp;
		s.insert(temp);
	}
	temp = -1000000000;	//첫 원소에서 앞에 뺐을때 무의미한 값이 나오도록.
	for (auto j : s) {
		m.insert(j - temp);	// 원소간 차이. 이중 가장 작은 것보다 작을수밖에 없음
		temp = j;
	}
	small = *(m.begin());
	for (i = small; i >=2; i--) {
		if (small % i != 0)continue;	//차이의 약수들만 m이 될 수 있음 (am+k, bm+k, ...)
		temp = 1;	//다음 for문의 처음을 나타내주는 변수
		gcd = 1;	//i가 해당하는지를 나타내는 변수
		for (auto j : s) {
			if (temp) {		//맨처음
				remainder = j % i;
				temp = 0;
			}
			else {	//두번째부턴 나머지가 같은지 체크
				if (j % i != remainder) {
					gcd = 0;
					break;
				}
			}
		}
		if (gcd) {
			gcd = i;	//M이 될수 있는 가장 큰 수를 찾는다.
			break;
		}
	}
	for (i = 2; i*i < gcd; i++) {	//그 최대 M의 약수들은 모두 해당한다.
		if (gcd % i != 0)continue;
		g.insert(i);
		cout << i << ' ';
	}
	if (i * i == gcd) cout << i << ' ';
	for (auto j : g) {
		cout << gcd / j << ' ';
	}
	cout << gcd;

	return 0;
}