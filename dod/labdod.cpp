#include <iostream>
#include <algorithm>
#include <time.h>

void print_array(int arr[], int arr_size) {
    for (int i = 0; i < arr_size; i++) {
        printf("%d ", arr[i]);
    }
}
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j < high; j++) {
        if (arr[j] <= pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return (i + 1);
}
void quick_sort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quick_sort(arr, low, pi - 1);
        quick_sort(arr, pi + 1, high);
    }
}
void merge(int *arr, int low, int mid, int high) {
    int i, j, k;
    int* temp = new int[high - low + 1];
    i = low;
    k = 0;
    j = mid + 1;
    while (i <= mid && j <= high) {
        if (arr[i] < arr[j]) {
            temp[k] = arr[i];
            k++;
            i++;
        }
        else {
            temp[k] = arr[j];
            k++;
            j++;
        }
    }
    while (i <= mid) {
        temp[k] = arr[i];
        k++;
        i++;
    }
    while (j <= high) {
        temp[k] = arr[j];
        k++;
        j++;
    }
    for (i = low; i <= high; i++) {
        arr[i] = temp[i - low];
    }
    delete[] temp;
}
void merge_sort(int *arr, int low, int high) {
    int mid;
    if (low < high) {
        mid = (low + high) / 2;
        merge_sort(arr, low, mid);
        merge_sort(arr, mid + 1, high);
        merge(arr, low, mid, high);
    }
}
void count_sort() {
    int array[] = { 4, 2, 2, 8, 3, 3, 1 };
    print_array(array, 7);
    std::cout << std::endl;
    int output[10];
    int count[10];
    int max = array[0];
    for (int i = 1; i < 7; i++) {
        if (array[i] > max) {
            max = array[i];
        }
    }
    for (int i = 0; i <= max; ++i) {
        count[i] = 0;
    }
    for (int i = 0; i < 7; i++) {
        count[array[i]]++;
    }
    for (int i = 1; i <= max; i++) {
        count[i] += count[i - 1];
    }
    for (int i = 7 - 1; i >= 0; i--) {
        output[count[array[i]] - 1] = array[i];
        count[array[i]]--;
    }
    for (int i = 0; i < 7; i++) {
        array[i] = output[i];
    }
    print_array(array, 7);
}
int get_max(int arr[], int arr_size) {
    int max = arr[0];
    for (int i = 1; i < arr_size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;
}
void counting_sort(int array[], int size, int place) {
    const int max = 10;
    int output[8];
    int count[max];
    for (int i = 0; i < max; ++i) {
        count[i] = 0;
    }
    for (int i = 0; i < size; i++) {
        count[(array[i] / place) % 10]++;
    }
    for (int i = 1; i < max; i++) {
        count[i] += count[i - 1];
    }
    for (int i = size - 1; i >= 0; i--) {
        output[count[(array[i] / place) % 10] - 1] = array[i];
        count[(array[i] / place) % 10]--;
    }
    for (int i = 0; i < size; i++) {
        array[i] = output[i];
    }
}
void radix_sort() {
    int array[] = { 42, 22, 12, 8, 32, 43, 51, 82};
    print_array(array, 8);
    int max = get_max(array, 8);
    for (int place = 1; max / place > 0; place *= 10) {
        counting_sort(array, 8, place);
    }
    std::cout << std::endl;
    print_array(array, 8);
}
void heapify(int arr[], int arr_size, int i) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < arr_size && arr[left] > arr[largest]) {
        largest = left;
    }
    if (right < arr_size && arr[right] > arr[largest]) {
        largest = right;
    }
    if (largest != i) {
        std::swap(arr[i], arr[largest]);
        heapify(arr, arr_size, largest);
    }
}
void heap_sort(int arr[], int arr_size) {
    for (int i = arr_size / 2 - 1; i >= 0; i--) {
        heapify(arr, arr_size, i);
    }
    for (int i = arr_size - 1; i >= 0; i--) {
        std::swap(arr[0], arr[i]);
        heapify(arr, i, 0);
    }
}
int main() {
    srand(time(NULL));
    int arr[] = { 56,-16,52,20};
    const int arr_size = sizeof(arr) / sizeof(arr[0]);
    print_array(arr, arr_size);
    printf("\n\nQuick sort\n");
    quick_sort(arr, 0, arr_size - 1);
    print_array(arr, arr_size);
    printf("\n\nMerge sort\n");
    merge_sort(arr, 0, arr_size - 1);
    print_array(arr, arr_size);
    printf("\n\nCount sort\n");
    count_sort();
    printf("\n\nRadix sort\n");
    radix_sort();
    printf("\n\nHeap sort\n");
    heap_sort(arr, arr_size);
    print_array(arr, arr_size);
    return 0;
}
