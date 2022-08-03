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
	temp = -1000000000;	//ù ���ҿ��� �տ� ������ ���ǹ��� ���� ��������.
	for (auto j : s) {
		m.insert(j - temp);	// ���Ұ� ����. ���� ���� ���� �ͺ��� �������ۿ� ����
		temp = j;
	}
	small = *(m.begin());
	for (i = small; i >=2; i--) {
		if (small % i != 0)continue;	//������ ����鸸 m�� �� �� ���� (am+k, bm+k, ...)
		temp = 1;	//���� for���� ó���� ��Ÿ���ִ� ����
		gcd = 1;	//i�� �ش��ϴ����� ��Ÿ���� ����
		for (auto j : s) {
			if (temp) {		//��ó��
				remainder = j % i;
				temp = 0;
			}
			else {	//�ι�°���� �������� ������ üũ
				if (j % i != remainder) {
					gcd = 0;
					break;
				}
			}
		}
		if (gcd) {
			gcd = i;	//M�� �ɼ� �ִ� ���� ū ���� ã�´�.
			break;
		}
	}
	for (i = 2; i*i < gcd; i++) {	//�� �ִ� M�� ������� ��� �ش��Ѵ�.
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