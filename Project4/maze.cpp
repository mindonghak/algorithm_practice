#include <iostream>
#include <algorithm>
#include <queue>
#include <utility>
#include <queue>
using namespace std;
int map[10][10];
int pos_R[2];
int pos_B[2];
int pos_O[2];
int N, M;
void print_map(int depth);
int arrtoi();
void itoarr(int result);
int move_left(int result);
int move_right(int result);
int move_down(int result);
int move_up(int result);
int bfs();
bool suceed = false;
bool fail = false;
int check[10000];
int shortest;
queue <int> q;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int i, j;
	cin >> N >> M;
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			char temp;
			cin >> temp;
			if (temp == '#') {
				map[i][j] = 1;
			}
			else if (temp == 'R') {
				pos_R[0] = j;
				pos_R[1] = i;
			}
			else if (temp == 'B') {
				pos_B[0] = j;
				pos_B[1] = i;
			}
			else if (temp == 'O') {
				pos_O[0] = j;
				pos_O[1] = i;
			}
			else if (temp == '.') continue;
			else {
				printf("map_error\n");
			}
		}
	}
	//print_map();
	int ans = bfs();
	cout << (ans > 10 ? -1 : ans);
	return 0;
}
int arrtoi() {
	int result = 0;
	result += pos_B[0] * 1000;
	result += pos_B[1] * 100;
	result += pos_R[0] * 10;
	result += pos_R[1];
	//cout <<"arrtoi : " << result << '\n';
	return result;
}
void itoarr(int result) {
	//cout <<"itoarr : " << result << '\n';
	pos_R[1] = result % 10;
	result /= 10;
	pos_R[0] = result % 10;
	result /= 10;
	pos_B[1] = result % 10;
	result /= 10;
	pos_B[0] = result % 10;
}

int bfs() {
	int cur_pos = arrtoi();
	check[cur_pos] = 1;
	q.push(cur_pos);
	while (!q.empty()) {
		cur_pos = q.front();
		q.pop();
		int temp;
		if ((temp = move_left(cur_pos)) && !fail) {
			//print_map(cur_pos);
			if (suceed)return check[cur_pos];
			if (!check[temp]) {
				//cout << "temp : " << temp;
				q.push(temp);
				check[temp] = check[cur_pos] + 1;
			}
		}
		fail = false;
		if ((temp = move_right(cur_pos)) && !fail) {
			//print_map(cur_pos);
			if (suceed)return check[cur_pos];
			if (!check[temp]) {
				q.push(temp);
				check[temp] = check[cur_pos] + 1;
			}
		}
		fail = false;
		if ((temp = move_down(cur_pos)) && !fail) {
			//print_map(cur_pos);
			if (suceed)return check[cur_pos];
			if (!check[temp]) {
				q.push(temp);
				check[temp] = check[cur_pos] + 1;
			}
		}
		fail = false;
		if ((temp = move_up(cur_pos)) && !fail) {
			//print_map(cur_pos);
			if (suceed)return check[cur_pos];
			if (!check[temp]) {
				q.push(temp);
				check[temp] = check[cur_pos] + 1;
			}
		}
		fail = false;
	}
	return -1;
}

int move_left(int result) {
	int cur_pos = result;
	itoarr(result);
	bool r = false;
	bool b = false;
	while (!map[pos_B[1]][pos_B[0] - 1]) {
		if (pos_B[0] - 1 == pos_R[0] && pos_B[1] == pos_R[1]) r = true;
		if (pos_B[0] - 1 == pos_O[0] && pos_B[1] == pos_O[1]) fail = true;
		pos_B[0]--;
		//cout << "pos_B[0] : " << pos_B[0];
	}
	if (r)pos_B[0]++;

	while (!map[pos_R[1]][pos_R[0] - 1]) {
		if (pos_R[0] - 1 == pos_B[0] && pos_B[1] == pos_R[1]) b = true;
		if (pos_R[0] - 1 == pos_O[0] && pos_R[1] == pos_O[1]) suceed = true;
		pos_R[0]--;
	}
	if (b&&!r)pos_R[0]++;
	result = arrtoi();
	if (result == cur_pos)return 0;
	return result;
}

int move_right(int result) {
	int cur_pos = result;
	itoarr(result);
	bool r = false;
	bool b = false;
	while (!map[pos_B[1]][pos_B[0] + 1]) {
		if (pos_B[0] + 1 == pos_R[0] && pos_B[1] == pos_R[1]) r = true;
		if (pos_B[0] + 1 == pos_O[0] && pos_B[1] == pos_O[1]) fail = true;
		pos_B[0]++;
	}
	if (r)pos_B[0]--;

	while (!map[pos_R[1]][pos_R[0] + 1]) {
		if (pos_R[0] + 1 == pos_B[0] && pos_B[1] == pos_R[1]) b = true;
		if (pos_R[0] + 1 == pos_O[0] && pos_R[1] == pos_O[1]) suceed = true;
		pos_R[0]++;
	}
	if (b&&!r)pos_R[0]--;
	result = arrtoi();
	if (result == cur_pos)return 0;
	return result;
}

int move_down(int result) {
	int cur_pos = result;
	itoarr(result);
	bool r = false;
	bool b = false;
	while (!map[pos_B[1] + 1][pos_B[0]]) {
		if (pos_B[0] == pos_R[0] && pos_B[1] + 1 == pos_R[1]) r = true;
		if (pos_B[0] == pos_O[0] && pos_B[1] + 1 == pos_O[1]) fail = true;
		pos_B[1]++;
	}
	if (r)pos_B[1]--;

	while (!map[pos_R[1] + 1][pos_R[0]]) {
		if (pos_R[0] == pos_B[0] && pos_R[1] + 1 == pos_B[1]) b = true;
		if (pos_R[0] == pos_O[0] && pos_R[1] + 1 == pos_O[1]) suceed = true;
		pos_R[1]++;
	}
	if (b&&!r)pos_R[1]--;
	result = arrtoi();
	if (result == cur_pos)return 0;
	return result;
}

int move_up(int result) {
	int cur_pos = result;
	itoarr(result);
	bool r = false;
	bool b = false;
	while (!map[pos_B[1] - 1][pos_B[0]]) {
		if (pos_B[0] == pos_R[0] && pos_B[1] - 1 == pos_R[1]) r = true;
		if (pos_B[0] == pos_O[0] && pos_B[1] - 1 == pos_O[1]) fail = true;
		pos_B[1]--;
	}
	if (r)pos_B[1]++;

	while (!map[pos_R[1] - 1][pos_R[0]]) {
		if (pos_R[0] == pos_B[0] && pos_R[1] - 1 == pos_B[1]) b = true;
		if (pos_R[0] == pos_O[0] && pos_R[1] - 1 == pos_O[1]) suceed = true;
		pos_R[1]--;
	}
	if (b&&!r)pos_R[1]++;
	result = arrtoi();
	if (result == cur_pos)return 0;
	return result;
}



void print_map(int depth) {
	int i, j;
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			if (pos_R[0] == j && pos_R[1] == i) {
				printf("R");
			}
			else if (pos_B[0] == j && pos_B[1] == i) {
				printf("B");
			}
			else if (pos_O[0] == j && pos_O[1] == i) {
				printf("O");
			}
			else if (!map[i][j]) {
				cout << '.';
			}
			else {
				cout << '#';
			}
		}
		cout << '\n';
	}
	cout << "depth : " << check[depth] << '\n';
}
