/*
Створити циклічний список цілих чисел. 
Продублювати в ньому всі парні числа
*/
#include <iostream>
using namespace std;

struct Node {
	int data;
	Node* next;
};
Node* Init_List(int x) {
	Node* c = new Node;
	c->next = c;
	c->data = x;
	return c;
}
Node* Add_After(Node*& ptr, int x) {
	Node* c = new Node;
	c->next = c;
	c->data = x;
	if (ptr == NULL) {
		return NULL;
	}
	else {
		c->next = ptr->next;
		ptr->next = c;
		ptr = c;
		return c->next;
	}
}
void Input_Numbers(Node* &head, Node* &end) {
	int num;
	cout << "Input:" << endl;
	for (int i = 0; i < 5; i++) {
		cin >> num;
		if (head == NULL) {
			head = end = Init_List(num);
		}
		else {
			Add_After(end, num);
		}
	}
}
void Print_List(Node* head) {
	cout << endl << "List:" << endl;
	Node* c = head;
	do {
		if (c) {
			printf("C: %d\n", c->data);
			c = c->next;
		}
	} while (c != head);
	if (c == head) {
		printf("Head/C: %d\n", c->data);
	}
}
void Free_Memory(Node* head, Node* end)
{
	if (head == NULL) {
		return;
	}
	Node* node = head;
	end->next = NULL;
	while (node != NULL) {
		head = head->next;
		delete node;
		node = head;
	}
}
void Double_Node(Node* head) {
	Node* c = head;
	do {
		if (c->data % 2 == 0) {
			Add_After(c, c->data);
		}
		c = c->next;
	} while (c != head);
}
int main() {
	Node* head = NULL, *end = NULL;
	Input_Numbers(head, end);
	Print_List(head);
	Double_Node(head);
	Print_List(head);
	Free_Memory(head, end);
	return 0;
}