#include <stdio.h>
#include <stdlib.h>
#define N 100
#define M 100

typedef struct {
	int a;
	int b;
} delete_elem;

struct node {
	int index;
	struct node* next;
};
void print_adj_matrix(int n, int matrix_adj[N][N]) {
	printf("Prin the adjacent matrix\n");
	for (int i = 0; i < n; i++) 
	{
		for (int j = 0; j < n; j++)
			printf("%d ", matrix_adj[i][j]);
		printf("\n");
	}
}
void print_graph(struct node graph[], int n) {
	printf("Printing the Graph\n");
	for (int i = 0; i < n; i++) {
		printf("%d ----> ", graph[i].index);
		struct node* current = graph[i].next;
		while (current != NULL) {
			printf("%d | ", current->index);
			current = current->next;
		}
		printf("NULL\n");
	}
}
void add_vertex(struct node** head, int index) {
	struct node* current = NULL;
	struct node* new_node = NULL;
	new_node = (struct node*)malloc(sizeof(struct node));
	if (!new_node)
	{
		printf("Failed at mallocing memmory.\n");
		return;
	}

	new_node->index = index;
	new_node->next = NULL;
	if ((*head) == NULL) {
		*head = new_node;
		return;
	}
	current = *head;
	while (current->next != NULL) {
		current = current->next;
	}
	current->next = new_node;
	return;
}
void deleting(int index, struct node** head) {
	struct node* current = *head;
	struct node* temp = NULL;
	// only one element
	if (current->next == NULL) {
		free(current);
		*head = NULL;
		return;
	}
	else {
		// the first element is the searched one
		if (current->index == index) {
			temp = current->next;
			free(current);
			*head = temp;
			return;
		}
		else {
			while (current != NULL) {
				if (current->next->index == index) {
					temp = current->next->next;
					free(current->next);
					current->next = temp;
					return;
				}
				else
				{
					current = current->next;
				}
			}
		}
	}
}
void delete_edje(int n, int m, struct node* graph, delete_elem* floaded) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (graph[i].index == floaded[j].a) {
				deleting(floaded[j].b, &graph[i].next);
			}
			else if (graph[i].index == floaded[j].b) {
				deleting(floaded[j].a, &graph[i].next);
			}
		}
	}
}
int main() {
	int n = 0, m = 0, matrix_adj[N][N];
	delete_elem floaded[M];
	scanf("%d %d", &n, &m);
	//int N = 0, M = 0;
	//scanf("%d %d", &N, &M);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < n; j++)
			scanf("%d", &matrix_adj[i][j]);
	for (int i = 0; i < m; i++)
		scanf("%d %d", &floaded[i].a, &floaded[i].b);

	node graph[N];
	for (int i = 0; i < n; i++) {
		graph[i].index = i + 1;
		graph[i].next = NULL;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (matrix_adj[i][j] == 1)
				add_vertex(&graph[i].next, j + 1);
		}
	}
	print_graph(graph, n);
	delete_edje(n, m, graph, floaded);
	print_graph(graph, n);
	return 0;
}
