/*
Нехай N ⎯ невід'ємне ціле число. 
Рекурсивно описати функцію від параметра N, яка знаходить найбільшу цифру числа N.
*/
#include <iostream>
#include <cstdlib>
#include <time.h> 

using namespace std;

int FindMax(int n, int count, int max, int arr[]) {
    if (count == n) {
        cout << max << endl;
        return 0;
    }
    else {
        if (arr[count] >= max) {
            max = arr[count];
        }
        return FindMax(n, count+1, max, arr);
    }
}
int main() {
    srand(time(0));
    int arr[6];
    int value = rand()%88888+1000;
    cout << value << endl;
    int n = 0;
    int temp;
    while (value > 0) {
        arr[n] = value % 10;
        value = value / 10;
        n++;   
    }
    int max_value = 0;
    FindMax(n, 0, max_value, arr);
    return 0;
}