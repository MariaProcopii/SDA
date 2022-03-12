#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node* next;
};
struct node* front = NULL;
struct node* rear = NULL;
void enqueue(int data) {
	struct node* new_node = (struct node*)malloc(sizeof(struct node));
	new_node->data = data;
	new_node->next = NULL;
	if (front == NULL && rear == NULL) {
		front = rear = new_node;
		return;
	}
	else {
		rear->next = new_node;
		rear = new_node;
	}
}

void dequeue() {
	struct node* temp = front;
	if (front == NULL) {
		printf("List is empty");
		return;
	}
	else {
		front = front->next;
		if (front == NULL) {
			rear = NULL;
		}
		free(temp);
	}
}

void printList() {
	struct node* temp = front;
	while (temp != NULL) {
		printf("%d\n", temp->data);
		temp = temp->next;
	}
}
int main() {
	enqueue(1);
	enqueue(2);
	enqueue(3);
	printList();
	printf("After dequeue:\n");
	dequeue();
	printList();
	return 0;
}
/*include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node* next;
};
void enqueue(struct node** front, struct node** rear, int data) {
	struct node* new_node = (struct node*)malloc(sizeof(struct node));
	new_node->data = data;
	new_node->next = NULL;
	if (*front == NULL && *rear == NULL) {
		*front = *rear = new_node;
		return;
	}
	else {
		(*rear)->next = new_node;
		*rear = new_node;
	}
}

void dequeue(struct node** front, struct node** rear) {
	struct node* temp = *front;
	if (front == NULL) {
		printf("List is empty\n");
		return;
	}
	else {
		*front = (*front)->next;
		if (front == NULL) {
			rear = NULL;
		}
		free(temp);
	}
}

void printList(struct node** front) {
	struct node* temp = *front;
	while (temp != NULL) {
		printf("%d\n", temp->data);
		temp = temp->next;
	}
}
int main() {
	struct node* front = NULL;
	struct node* rear = NULL;
	enqueue(&front, &rear, 1);
	enqueue(&front, &rear, 2);
	enqueue(&front, &rear, 3);
	printList(&front);
	printf("After dequeue:\n");
	dequeue(&front, &rear);
	printList(&front);
	return 0;
}*/
