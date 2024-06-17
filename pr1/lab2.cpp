/*
Завдання: Ввести 10 елементів
Тип даних: цілий
Індивідуальне завдання: Замінити всі непарні елементи списку одиницями
*/
#include <iostream>
#include <string>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void Add_Node(Node* &head, Node* &end, int x) {
    Node* c = new Node;
    c->next = NULL;
    c->data = x;
    if (head == NULL) {
        head = c; 
        end = c;
    }
    else {
        end->next = c;
        end = c;
    }
}
void Input_Numbers(Node* &head, Node* &end) {
    string x = "0";
    cout << "Input:" << endl;
    for (int i = 0; i < 10;) {
        try {
            cin >> x;
            size_t pos;
            int num = stoi(x, &pos);
            if (pos < x.size()) {
                throw invalid_argument("Invalid input");
            }
            else {
                Add_Node(head, end, num);
                i++;
            }
        }
        catch(const exception& e) {
            cout << "Invalid input: " << e.what() << '\n';
        } 
    }
}
void Print_List(Node* head) {
    cout << "The list:" << endl;
    Node* c = head;
    while (c != NULL) {
        cout << c->data << " ";
        c = c->next;
    }
    cout << endl;
}
void Change_Num(Node* head, Node* end) {
    while (head != NULL) {
        if (head->data % 2 != 0) {
            if (head->data < 0) {
                head->data = -1;
            }
            else {
                head->data = 1;
            }
        }
        head = head->next;
    }
}
void Free_Memory(Node* head) {
    Node* c = head;
    while (c != NULL) {
        head = head->next;
        delete c;
        c = head;
    }
}

int main() {
Node* head = NULL, *end = NULL;
Input_Numbers(head, end);
Print_List(head);
Change_Num(head,end);
Print_List(head);
Free_Memory(head);

return 0;
}
