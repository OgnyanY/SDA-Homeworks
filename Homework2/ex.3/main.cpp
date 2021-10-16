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

    char* num = new char [size];
    int numSize = 0;
    char* bigL = new char [size];
    int bigLSize = 0;
    char* smallL = new char [size];
    int smallLSize = 0;

    for (int i = 0; i < size; i++) {
        if(arr[i] >= '0' && arr[i] <= '9'){
            num[numSize] = arr[i];
            ++numSize;
        }
        else if(arr[i] >='a' && arr[i] <= 'z'){
            smallL[smallLSize] = arr[i];
            ++smallLSize;
        }
        else if(arr[i] >='A' && arr[i] <= 'Z'){
            bigL[bigLSize] = arr[i];
            ++bigLSize;
        }
    }

    mergeSort(num, numSize);
    mergeSort(bigL, bigLSize);
    mergeSort(smallL, smallLSize);

    for (int i = 0; i < numSize; i++) {
        std::cout << num[i];
    }
    for (int i = 0; i < smallLSize; i++) {
        std::cout << smallL[i];
    }
    for (int i = 0; i < bigLSize; i++) {
        std::cout << bigL[i];
    }
    delete[] num;
    delete[] bigL;
    delete[] smallL;
}

