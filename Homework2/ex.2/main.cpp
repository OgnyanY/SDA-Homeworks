#include <iostream>

void merge(char arr[], char mergeArr[], int start, int mid, int end) {
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

void mergeSortRecursion(char arr[], char mergeArr[], int start, int end) {
    if(start < end) {
        int mid = (start + end) / 2;

        mergeSortRecursion(arr, mergeArr, start, mid);
        mergeSortRecursion(arr, mergeArr, mid + 1, end);

        merge(arr, mergeArr, start, mid, end);
    }
}

void mergeSort (char arr[], int length) {
    char* mergeArr = new char[length];
    mergeSortRecursion(arr, mergeArr, 0, length - 1);
    delete[] mergeArr;
}

int main() {
    int size = 0;
    std::cin >> size;
    char* arr = new char [size];
    for (int i = 0; i < size; i++) {
        std::cin >> arr[i];
    }

    for (int i = 0; i < size; i++) {
        if(arr[i] >='0' && arr[i] <= '9'){

        }
        if(arr[i] >='a' && arr[i] <= 'z'){
            arr[i]=arr[i]-32;//push back 1
        }
        else if(arr[i] >='A' && arr[i] <= 'Z'){
            arr[i]=arr[i]+32;
        }
    }
    mergeSort(arr, size);


    for (int i = 0; i < size; i++) {
        std::cout << arr[i];
    }
}
