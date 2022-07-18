#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

char grid[64][64];
int main() {
	int n, i, j;
	char tr;
	scanf("%d%c", &n, &tr);
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			scanf("%c", grid[i] + j);
		}
		scanf("%c", &tr);
	}
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			printf("%c", grid[i][j]);
		}
		printf("\n");
	}

	return 0;
}

