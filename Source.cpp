#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node* next;
};

struct node* head = NULL;
void push(int data) {
	struct node* new_node = (struct node*)malloc(sizeof(struct node));
	new_node->data = data;
	new_node->next = head;

	head = new_node;
}

void pop() {
	struct node* temp = head;
	if (head == NULL) {
		printf("nothing to delete\n");
		return;
	}
	else {
		printf("Deleted ellement %d\n", head->data);
		head = head->next;
		free(temp);
	}
}
void printList() {
	struct node* temp = head;
	while (temp != NULL) {
		printf("%d\n", temp->data);
		temp = temp->next;
	}
}
int main() {
	push(2);
	push(1);
	push(0);
	printList();
	pop();
	printList();
	return 0;
}/*
\\ decratation in main function
#include<stdio.h>
#include<stdlib.h>

struct node {
	int data;
	struct node* next;
};

void push(struct node** head, int data) {
	struct node* new_node = (struct node*)malloc(sizeof(struct node));
	new_node->data = data;
	new_node->next = *head;

	*head = new_node;
}

void pop(struct node** head) {
	struct node* temp = *head;
	if (head == NULL) {
		printf("nothing to delete\n");
	}
	else {
		printf("Deleted ellement %d\n", temp->data);
		*head = temp->next;
		free(temp);
	}
}
void printList(struct node** head) {
	struct node* temp = *head;
	while(temp != NULL) {
		printf("%d\n", temp->data);
		temp = temp->next;
	}
}
int main() {
	struct node* head = NULL;
	push(&head, 2);
	push(&head, 1);
	push(&head, 0);
	printList(&head);
	pop(&head);
	printList(&head);
	return 0;
}*/