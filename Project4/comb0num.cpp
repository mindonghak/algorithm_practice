#include <iostream>

using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	long long int n, m, result = 0,result2=0, i;
	cin >> n >> m;
	for (i = 5; i <= n; i *= 5) {	//n������ 5�� ��� ����������
		result += n / i;
	}
	for (i = 5; i <= n - m; i *= 5) {	//n-m���� 5�� ��� ����������
		result -= (n - m) / i;
	}
	for (i = 5; i <= m; i *= 5) {	//m���� 5�� ��� ������ �ִ���
		result -= m / i;
	}
	for (i = 2; i <= n; i *= 2) {	//n������ 2�� ��� ����������
		result2 += n / i;
	}
	for (i = 2; i <= n - m; i *= 2) {	//n-m���� 2�� ��� ����������
		result2 -= (n - m) / i;
	}
	for (i = 2; i <= m; i *= 2) {	//m���� 2�� ��� ������ �ִ���
		result2 -= m / i;
	}
	cout << min(result, result2);		//���� 2�� 5�� �� ���� ���� ��� ���������� ���ش�.
	return 0;
}
