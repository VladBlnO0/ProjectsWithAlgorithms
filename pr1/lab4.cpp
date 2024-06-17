/*
Умова для введення: Вводити елементи, доки кількість від’ємних менша за 5
Тип даних: дійсний
Індивідуальне завдання: Вилучити зі списку всі від’ємні елементи
*/
#include <iostream>
#include <string>
using namespace std;

struct Node {
    double data;
    Node *next;
};

void Add_Node(Node* &head, Node* &end, double x) {
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
    int count = 0;
    cout << "Input:" << endl;
    while (count < 5) {
        try {
            cin >> x;
            size_t pos;
            double num = stod(x, &pos);
            if (pos < x.size()) {
                throw invalid_argument("Invalid input");
            }
            else {
                Add_Node(head, end, num);
                if (num < 0) {
                    count++;
                }
            }
        }
        catch(const exception& e) {
            cout << "Invalid input: " << e.what() << endl;
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
void Delete_Node_Ptr(Node* &head, Node* &end, Node* &ptr) {
    Node* c = head;
    if (ptr == head) {
        head = c->next;
        delete c;
        return;
    }
    c = head;
    while (c->next != ptr) {
        c = c->next;
    }
    c->next = ptr->next;
    if (ptr == end) {
        end = c;
    }
    delete ptr;
}
void Make_Positive_List(Node* &head, Node* &end) {
    Node* c = head, *ptr;
    while (c != NULL) {
        if (c->data < 0) {
            ptr = c;
            c = c->next;
            Delete_Node_Ptr(head, end, ptr);
        }
        else {
            c = c->next;
        }
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

Make_Positive_List(head, end);
Print_List(head);

Free_Memory(head);

return 0;
}
