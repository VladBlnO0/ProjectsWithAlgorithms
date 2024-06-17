/*
Завдання: Вводити числа до списку, доки не введено число 999
Тип даних: дійсний
Індивідуальне завдання: Обчислити суму квадратів тих чисел, модуль яких більше 2.5
*/
#include <iostream>
#include <math.h>
#include <string>
using namespace std;

struct Node {
    double data;
    Node* next;
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
    cout << "Input float numbers\nInput 999 to stop" << endl;
    while (x != "999") {
        try {
            cin >> x;
            if (x != "999") {
                size_t pos;
                double num = stod(x, &pos);
                if (pos < x.size()) {
                    throw invalid_argument("Invalid input");
                }
                else {
                    Add_Node(head, end, num);
                }
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
void Calc_Sum(Node* head, Node* end) {
    float sum = 0;
    while (head != NULL) {
        if (fabs(head->data) > 2.5) {
            sum += pow(head->data, 2);
        }
        head = head->next;
    }
    cout << "Sum of squares: " << sum;
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
Calc_Sum(head,end);
Free_Memory(head);

return 0;
}
