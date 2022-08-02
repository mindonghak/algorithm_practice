#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int i, order[2][6], xmax = -1, ymax = -1, minarea=1, k;
	cin >> k;
	for (i = 0; i < 6; i++) {
		cin >> order[0][i] >> order[1][i];	//����� ����
		if (order[0][i] == 1 || order[0][i] == 2) {	//����
			xmax = xmax < order[1][i] ? order[1][i] : xmax;	//�ִ���̰� �� ��
		}
		else {	//����
			ymax = ymax < order[1][i] ? order[1][i] : ymax;
		}
	}
	for (i = 0; i < 6; i++) {
		if (!i&&order[0][5] == order[0][1]) {	//������ ������ ���� �����̶�� ���̴� ����(i==0)
			minarea *= order[1][0];	//���ο� ���� ���ҰŶ� ���о��� �̸� ���ع���
		}
		else if (i == 5 && order[0][4] == order[0][0]) {	//�ε���ó��
			minarea *= order[1][5];
		}
		else if (order[0][i - 1] == order[0][i + 1]) {
			minarea *= order[1][i];
		}
	}
	cout << (xmax * ymax - minarea) * k;

	return 0;
}