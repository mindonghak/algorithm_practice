#include <iostream>
#include <algorithm>
using namespace std;
int N;
int map[30][30];
bool check[30][30];
int _count;
int result[1000];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };
void dfs(pair <int, int> p);
int main() {
	int i,j,num=0;
	char temp;
	scanf("%d\n", &N);
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= N; j++) {
			scanf("%c", &temp);
			map[i][j] = temp == '1';
		}
		scanf("%c", &temp);
	}

	for (i = 1; i <= N; i++) {
		for (j = 1; j <= N; j++) {
			if (!map[i][j])continue;
			if (check[i][j])continue;
			_count = 0;
			dfs(make_pair(i, j));
			result[num++] = _count;
		}
	}
	printf("%d\n", num);
	sort(result, result + num);
	for (i = 0; i < num; i++) {
		printf("%d\n", result[i]);
	}

	return 0;
}
void dfs(pair <int,int> p ) {
	check[p.first][p.second] = 1;
	int i,x,y;
	_count++;
	for (i = 0; i < 4; i++) {
		x = p.first + dx[i];
		y = p.second + dy[i];
		if (check[x][y])continue;
		if (!map[x][y])continue;
		dfs(make_pair(x, y));
	}
}