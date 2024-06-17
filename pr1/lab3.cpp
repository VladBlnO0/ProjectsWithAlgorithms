/*
Умова для введення: Вводити елементи, доки їхня сума не стане від'ємною
Тип даних: дійсний
Індивідуальне завдання: Вставити в список число 1.5 після кожного елемента з додатним значенням
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
int Sum_List(Node* head) {
    Node* c = head;
    float sum = 0;
    while (c != NULL) {
        sum += c->data;
        c = c->next;
    }
    return sum;
}
void Input_Numbers(Node* &head, Node* &end) {
    string x = "0";
    cout << "Input:" << endl;
    do {
        try {
            cin >> x;
            size_t pos;
            double num = stod(x, &pos);
            if (pos < x.size()) {
                throw invalid_argument("Invalid input");
            }
            else {
                Add_Node(head, end, num);
            }
        }
        catch(const exception& e) {
            cout << "Invalid input: " << e.what() << '\n';
        } 
    } while (Sum_List(head) > 0);
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
void Insert_After(Node* head) {
    while (head != NULL) {
        if (head->data > 0) {
            if (head->next == NULL) {
                Node* new_node = new Node;
                new_node->data = 1.5;
                new_node->next = NULL;
                head->next = new_node;
            }
            else {
                Node* new_node = new Node;
                new_node->data = 1.5;
                new_node->next = head->next;
                head->next = new_node;
            }
            head = head->next->next;
        }
        else {
            head = head->next;
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
Node *head = NULL, *end = NULL;
Input_Numbers(head, end);
Print_List(head);

Insert_After(head);
Print_List(head);

Free_Memory(head);

return 0;
}
