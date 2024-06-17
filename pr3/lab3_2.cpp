/*
Створити чергу з цілих непарних чисел від 45 до 99
Всі числа з черги витягувати по одному і ті, що менш як 77, вставляти в стек
Інші виводити на екран
Числа зі стека виймати по одному і виводити на екран
*/
#include <iostream>

int Stack[20], top = 0, size = 20;
struct Queue {
    int data;
    Queue* next;
};
void Push_Stack(int item) {
    Stack[top] = item;
    top++;
}
void Push_Queue(Queue*& head, Queue*& tail, int x) {
    Queue* element = new Queue;
    element->data = x;
    element->next = NULL;
    if (head == NULL) {
        head = element;
    }
    else {
        tail->next = element;
    }
    tail = element;
}
void Pop_Stack() {
    top--;
}
void Pop_Queue(Queue* &head) {
    if (head == NULL) {
        return;
    }
    else {
        Queue* c = head;
        head = head->next;
        delete c;
    }
}
void Print_Stack() {
    std::cout << "\n\nStack:\n";
    for (int i = size-1; i >= 0; i--) {
        if (Stack[i] == 0) {
            i--;
        }
        else {
            printf("%d ", Stack[i]);
        }
    }
}
void Print_Queue(Queue* &head) {
    Queue* element = new Queue;
    element = head;
    std::cout << "Queue:\n";
    while (element != NULL) {
        std::cout << element->data << ' ';
        element = element->next;
    }
    std::cout << '\n';
}
int main() {
    Queue* head = NULL, *end = NULL;
    for (int i = 45; i <= 99; i += 2) {
        Push_Queue(head, end, i);
    }
    Print_Queue(head);
    std::cout << "\n";
    Queue* element = new Queue;
    element = head;
    while (element != NULL) {
        if (element->data < 77) {
            Push_Stack(element->data);
        }
        else {
            printf("%d ", element->data);
        }
        Pop_Queue(head);
        element = head;
    }
    Print_Stack();
    while (top != 0) {
        Pop_Stack();
    }
    return 0;
}