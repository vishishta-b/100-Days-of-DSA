#include <stdio.h>
#include <stdlib.h>

struct Node {
	int data;
	struct Node *next;
};

struct Node* create_node(int val) {
	struct Node *p = malloc(sizeof(struct Node));
	if (!p) {
		fprintf(stderr, "Memory allocation failed\n");
		exit(EXIT_FAILURE);
	}
	p->data = val;
	p->next = NULL;
	return p;
}

struct Node* append_tail(struct Node *head, int val) {
	struct Node *node = create_node(val);
	if (head == NULL) return node;
	struct Node *cur = head;
	while (cur->next) cur = cur->next;
	cur->next = node;
	return head;
}

struct Node* delete_first_occurrence(struct Node *head, int key) {
	if (head == NULL) return NULL;
	if (head->data == key) {
		struct Node *next = head->next;
		free(head);
		return next;
	}
	struct Node *prev = head;
	struct Node *cur = head->next;
	while (cur) {
		if (cur->data == key) {
			prev->next = cur->next;
			free(cur);
			return head;
		}
		prev = cur;
		cur = cur->next;
	}
	return head; 
}

int main(void) {
	int n;
	if (scanf("%d", &n) != 1) return 0;
	struct Node *head = NULL;
	for (int i = 0; i < n; ++i) {
		int x;
		if (scanf("%d", &x) != 1) x = 0;
		head = append_tail(head, x);
	}
	int key;
	if (scanf("%d", &key) != 1) key = 0;
	head = delete_first_occurrence(head, key);

	struct Node *cur = head;
	int first = 1;
	while (cur) {
		if (!first) printf(" ");
		printf("%d", cur->data);
		first = 0;
		cur = cur->next;
	}
	printf("\n");

	while (head) {
		struct Node *tmp = head->next;
		free(head);
		head = tmp;
	}
	return 0;
}
