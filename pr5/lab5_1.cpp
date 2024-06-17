/*
Введіть масив із 12 цілих чисел і одне число. 
Напишіть програму для лінійного та бінарного пошуків цього числа в масиві 
(дві функції в одній програмі). 
Програма має повернути індекс елемента, якщо він у масиві
Програма має повідомити про відсутність, якщо немає
Обчисліть кількість ітерацій (витків циклу) і порівнянь елементів.
*/
#include <iostream>
#include <time.h> 

#define len 12

void print(int num, int i) {
    printf("%d at %d\n", num, i);
}
void linear_search(int num, int arr[]) {
    int it = 0;
    int comp = 0;
    for(int i = 0; i < len; i++) {
        it++;
        if (arr[i] == num) {
            comp++;
            print(num, i);
            printf("Iterations: %d",it);
            printf("\nComparisons: %d",comp);
            return;
        }
        comp++; 
    }
    printf("Not in array!\n");
}
void binary_search(int num, int arr[]) {
    int l = 0;
    int r = len - 1;
    int it = 0;
    int comp = 0;
    while (l <= r) {
        it++;
        int m = l + (r - l) / 2;
        if (arr[m] == num) {
            comp++;
            print(num, m);
            printf("Iterations: %d",it);
            printf("\nComparisons: %d",comp);
            return;
        }
        comp++;
        if (arr[m] < num) {
            l = m + 1;
            comp++;
        }
        else if (arr[m] > num) {
            r = m - 1;
            comp++;
        }
    }
    printf("Not in array!\n");
}
int main() {
    srand(time(0));
    int arr[len] = {-61, -56, -37, -31, -29, -17, 25, 36, 46, 89, 109, 110};
    int x = rand() % (11 - (0) + 1) + (0);
    int num = arr[x];
    for(int i = 0; i < len; i++) {
        printf("%d - %d\n", i, arr[i]);
    }
    printf("\n%d\n", num);
    printf("\nLinear search\n");
    linear_search(num, arr);
    printf("\n\nBinary search\n");
    binary_search(num, arr);
    return 0;
}