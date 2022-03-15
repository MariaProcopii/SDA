#include <stdio.h>
#include <stdlib.h>

int arr[100][100], b[100], n, count = 0;
struct del_node {
	int f;
	int s;
}del_arr[100];

int DFS(int s)
{
	int i;
	b[s] = 1;
	for (i = 1; i <= n; i++)
		if (arr[s][i] != 0
			&& b[i] == 0)
			DFS(i);
	printf("%d ", s);
	return 0;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			scanf("%d", &arr[i][j]);
		}
	}
	DFS(1);// starting fron vertex 1

	/*for (int i = 1; i <= n; i++) { //if graph is disconnected
		if (b[i] == 0) {
			DFS(i);
			count += 1; //how many times the DFS was used
		}
	}*/
}
