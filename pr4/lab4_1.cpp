/*
Напишіть програму для виведення на екран елементів введеного масиву за допомогою рекурсії.
*/
#include <iostream>
#include <cstdlib>
#include <time.h> 

using namespace std;

void Print(int i, int arr[]) {
    if (i == 5) {
        return;
    }
    else {
        cout << arr[i] << endl;
        return Print(i+1, arr);
    }
}
int main() {
    srand(time(0));
    int arr[5];
    for(int i = 0; i < 5; i++) {
        arr[i] = rand()%20+1;
    }
    Print(0, arr);
    return 0;
}