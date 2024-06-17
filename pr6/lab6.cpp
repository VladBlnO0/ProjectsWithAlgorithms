#include <iostream>
#include <algorithm>
#include <time.h>

#define arr_size 11
//#define arr_size 100

void print_array(int arr[]) {
    for (int i = 0; i < arr_size; i++) {
        printf("%d ", arr[i]);
    }
}
void bubble_sort(int arr[]) {
    clock_t start, end;
    double cpu_time_used;
    start = clock();
    int pass = 0, comp = 0, chng = 0;
    for (int it = 0; it < arr_size; it++) {
        pass++;
        for (int i = 0; i < arr_size - it; i++) {
            comp++;
            if (arr[i] > arr[i + 1]) {
                chng++;
                std::swap(arr[i], arr[i + 1]);
            }
        }
    }
    end = clock();
    cpu_time_used = ((double)(end - start))/CLOCKS_PER_SEC;
    printf("Passes: %d\nComparisons: %d\nChanges: %d\nTaken time: %f\n",pass,comp,chng,cpu_time_used);
    print_array(arr);
}
void selection_sort(int arr[]) {
    clock_t start, end;
    double cpu_time_used;
    start = clock();
    int pass = 0, comp = 0, chng = 0;
    for (int it = 0; it < arr_size - 1; it++) {
        pass++;
        int min_idx = it;
        for (int i = it + 1; i < arr_size; i++) {
            comp++;
            if (arr[i] < arr[min_idx]) {
                min_idx = i;
            }
        }
        chng++;
        std::swap(arr[min_idx], arr[it]);
    }
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Passes: %d\nComparisons: %d\nChanges: %d\nTaken time: %f\n", pass, comp, chng, cpu_time_used);
    print_array(arr);
}
void insertion_sort(int arr[]) {
    clock_t start, end;
    double cpu_time_used;
    start = clock();
    int pass = 0, comp = 0, chng = 0;
    for (int it = 1; it < arr_size; it++) {
        pass++;
        int key = arr[it];
        int j = it - 1;
        comp++;
        while (key < arr[j] && j >= 0) {
            comp++;
            chng++;
            arr[j + 1] = arr[j];
            --j;
        }
        arr[j + 1] = key;
        chng++;
    }
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Passes: %d\nComparisons: %d\nChanges: %d\nTaken time: %f\n", pass, comp, chng, cpu_time_used);
    print_array(arr);
}
void shell_sort(int arr[]) {
    clock_t start, end;
    double cpu_time_used;
    start = clock();
    int pass = 0, comp = 0, chng = 0;
    for (int interval = arr_size / 2; interval > 0; interval /= 2) {
        pass++;
        for (int i = interval; i < arr_size; i += 1) {
            int temp = arr[i];
            int j;
            comp++;
            for (j = i; j >= interval && arr[j - interval] > temp; j -= interval) {
                arr[j] = arr[j - interval];
            }
            chng++;
            arr[j] = temp;
        }
    }
    end = clock();
    cpu_time_used = ((double)(end - start)) / CLOCKS_PER_SEC;
    printf("Passes: %d\nComparisons: %d\nChanges: %d\nTaken time: %f\n", pass, comp, chng, cpu_time_used);
    print_array(arr);
}
int main() {
    int arr[] = {56,-16,52,20,11,-9,20,54,-2,58,-6,-14};
    /*
    int arr[arr_size];
    for (int i = 0; i < arr_size; i++) {
        arr[i] = rand() % 100;
    }
    */
    print_array(arr);
    printf("\n\nBubble sort\n");
    bubble_sort(arr);
    printf("\n\nSelection sort\n");
    selection_sort(arr);
    printf("\n\nInsertion sort\n");
    insertion_sort(arr);
    printf("\n\nShell sort\n");
    shell_sort(arr);


	return 0;
}