#include <iostream>
void merge(int arr[], int mergeArr[], int start, int mid, int end) {
    int left = start;
    int right = mid + 1;

    for(int i = start; i <= end; ++i) {
        if(left <= mid && (right > end || arr[left] <= arr[right])){
            mergeArr[i] = arr[left];
            ++left;
        }else {
            mergeArr[i] = arr[right];
            ++right;
        }
    }

    for(int i = start; i <= end; ++i) {
        arr[i] = mergeArr[i];
    }
}

void mergeSortRecursion(int arr[], int mergeArr[], int start, int end) {
    if(start < end) {
        int mid = (start + end) / 2;

        mergeSortRecursion(arr, mergeArr, start, mid);
        mergeSortRecursion(arr, mergeArr, mid + 1, end);

        merge(arr, mergeArr, start, mid, end);
    }
}

void mergeSort (int arr[], int length) {
    int* mergeArr = new int[length];
    mergeSortRecursion(arr, mergeArr, 0, length - 1);
    delete[] mergeArr;
}

int main() {
    int size = 0;
    std::cin >> size;

    int* prizes = new int [size];
    for (int i = 0; i < size; i++) {
        std::cin >> prizes[i];
    }

    int employees = 0;
    std::cin >> employees;

   mergeSort(prizes, size);

    long long int answer = 0;
    for (int i = 0; i < employees; i++) {
        answer += prizes[i];
    }
    delete[] prizes;
    std::cout << answer;
}
