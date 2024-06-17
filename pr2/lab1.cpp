/*
Створити лінійний двозв'язний список з цілих чисел. 
Визначити суму елементів списку зі значеннями більше або рівними 15. 
Вилучити зі списку всі значення, які менше 5
*/
#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
    Node* prev;
};
Node* Init_List(int num) {
    Node* node = new Node;
    node->next = NULL;
    node->prev = NULL;
    node->data = num;
    return node;
}
void Add_After(Node*& ptr, int x) {
    if (ptr == NULL) {
        return;
    }
    else {
        Node* c = new Node;
        c->data = x;
        c->next = ptr->next;
        c->prev = ptr;
        if (ptr->next != NULL) {
            ptr->next->prev = c;
        }
        ptr->next = c;
        ptr = c;
    }
}
void Input_Numbers(Node*& head, Node*& end) {
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
void Print_List(Node* head, Node* end) {
    cout << endl << "Forward" << endl;
    while (head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl << "Reverse" << endl;
    while (end != NULL) {
        cout << end->data << " ";
        end = end->prev;
    }
}
void Sum_Count(Node* head) {
    Node* node = head;
    int sum = 0;
    while (node != NULL) {
        if (node->data >= 15) {
            sum = sum + node->data;
        }
        node = node->next;
    }
    cout << endl << sum << endl;
}
Node* Delete_C(Node* c) {
    Node* q = c->prev;
    if (c->next != NULL) {
        c->next->prev = q;
        if (q) {
            q->next = c->next;
            delete c;
            return q->next;
        }
        else {
            q = c->next;
            delete c;
            return q;
        }
    }
    else {
        q->next = NULL;
        delete c;
        return q;
    }
}
void Free_Memory(Node* head) {
    if (head == NULL) {
        return;
    }
    Node* node = head;
    while (node != NULL) {
        head = head->next;
        delete node;
        node = head;
    }
}
void Delete_Node(Node* &head, Node* &end) {
    Node* c = head;
    while (c != NULL) {
        if (c->data < 5) {
            if (c == head) {
                if (head == end) {
                    cout << endl << "List is empty" << endl;
                    Free_Memory(head);
                    head = NULL;
                    end = NULL;
                    return;
                }
                else {
                    head = c = Delete_C(c);
                }
            }
            else {
                if (c == end) {
                    end = c = Delete_C(c);
                }
                else {
                    c = Delete_C(c);
                }
            }
        }
        else {
            c = c->next;
        }
    }
}
int main() {
    Node* head = NULL, *end = NULL;
    Input_Numbers(head, end);
    Print_List(head, end);

    cout << endl << "After" << endl;

    Sum_Count(head);

    Delete_Node(head, end);

    if (head == NULL) {
        return 0;
    }
    else {
        Print_List(head, end);
        Free_Memory(head);
        return 0;
    }
}