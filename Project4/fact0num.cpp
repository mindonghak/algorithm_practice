#include <iostream>

using namespace std;
int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, result = 0;
	cin >> n;
	result += n / 5;	//0�ǰ����� 10�� ��� ������������ ���� ��������.
	result += n / 25;	//10�� ����� 2�� 5�� ������ ��������.
	result += n / 125;	//2�� �׻� 5�� �������� ����. 
	cout<< result;		//���� 5�� ��� ���������� ���ش�.
	return 0;
}
