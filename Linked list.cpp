#include <stdio.h>
#include <stdlib.h>
struct list {
	int data;
	struct list* next;
};
void print(struct list* head_r) {
	while (head_r != NULL)
	{
		printf("%d\n", head_r->data);
		head_r = head_r->next;
	}
}
void push(struct list** hear_r, int info) {
	struct list* newnode = (struct list*)malloc(sizeof(struct list));
	newnode->data = info;
	newnode->next = *hear_r;
	*hear_r = newnode;
}
void node(struct list* prew_node, int info) {
	struct list* newnode = (struct list*)malloc(sizeof(struct list));
	if (prew_node == NULL) {
		printf("It cannot be NULL");
		return;
	}
	newnode->data = info;
	newnode->next = prew_node->next;
	prew_node->next = newnode;
}
void append(struct list** head_r, int info) {
	struct list* newnode = (struct list*)malloc(sizeof(struct list)), * temp = *head_r;
	newnode->data = info;
	newnode->next = NULL;
	if (temp == NULL) {
		temp = newnode;
	}
	while (temp->next != NULL) {
		temp = temp->next;
	}
	temp->next = newnode;
}
void delete_by_info(struct list** head_r, int info) {
	struct list* temp = *head_r;
	struct list* prew = NULL;
	if (temp != NULL && temp->data == info) {
		*head_r = temp->next;
		free(temp);
	}
	while (temp != NULL && temp->data != info) {
		prew = temp;
		temp = temp->next;
	}
	if (temp == NULL)
		return;
	prew->next = temp->next;
	free(temp);
}
void delete_by_order(struct list** head_r, int position) {
	struct list* temp = *head_r;
	if (position == 0) {
		*head_r = temp->next;
		free(temp);
		return;
	}
	else {
		for (int i = 0; i < position - 1; i++) {
			temp = temp->next;
		}
		struct list* del = temp->next;
		temp->next = temp->next->next;
		free(del);
	}
}


int main() {
	struct list* head = NULL;
	push(&head, 2);
	node(head, 3);
	append(&head, 4);
	delete_by_order(&head, 0);
	print(head);
}
