#include <iostream>

void merge(char arr[], char mergeArr[], int start, int mid, int end) {
    int left = start;
    int right = mid + 1;
    //sort the elements
    for(int i = start; i <= end; ++i) {
        //this is when the left element is smaller
        if(left <= mid && (right > end || arr[left] <= arr[right])){
            mergeArr[i] = arr[left];
            ++left;
        }else {//this is when the right element is smaller
            mergeArr[i] = arr[right];
            ++right;
        }
    }
    //assign the already sorted elements
    for(int i = start; i <= end; ++i) {
        arr[i] = mergeArr[i];
    }
}

void mergeSortRecursion(char arr[], char mergeArr[], int start, int end) {
    //if there is only one element - return
    if(start < end) {
        int mid = (start + end) / 2;

        //divide the array by two and continue until there is only two elements in the array
        //and then merge them
        mergeSortRecursion(arr, mergeArr, start, mid);
        mergeSortRecursion(arr, mergeArr, mid + 1, end);

        merge(arr, mergeArr, start, mid, end);
    }
}

void mergeSort (char arr[], int length) {
    char* mergeArr = new char[length];//this is the array where we merge
    //this is the recursive function for merging
    mergeSortRecursion(arr, mergeArr, 0, length - 1);
    delete[] mergeArr;
}

int main() {
    int size = 0;
    std::cin >> size;
    char* arr = new char [size];
    for (int i = 0; i < size; ++i) {
        std::cin >> arr[i];
    }

    //create arrays for numbers, big letters and small letters
    char* num = new char [size];
    int numSize = 0;
    char* bigLetters = new char [size];
    int bigLettersSize = 0;
    char* smallLetters = new char [size];
    int smallLettersSize = 0;

    //assign the elements where they have to go
    for (int i = 0; i < size; ++i) {
        if(arr[i] >= '0' && arr[i] <= '9'){
            num[numSize] = arr[i];
            ++numSize;
        }
        else if(arr[i] >='a' && arr[i] <= 'z'){
            smallLetters[smallLettersSize] = arr[i];
            ++smallLettersSize;
        }
        else if(arr[i] >='A' && arr[i] <= 'Z'){
            bigLetters[bigLettersSize] = arr[i];
            ++bigLettersSize;
        }
    }
    //merge the separate arrays
    mergeSort(num, numSize);
    mergeSort(bigLetters, bigLettersSize);
    mergeSort(smallLetters, smallLettersSize);

    //cout the arrays in the correct order
    for (int i = 0; i < numSize; ++i) {
        std::cout << num[i];
    }
    for (int i = 0; i < smallLettersSize; ++i) {
        std::cout << smallLetters[i];
    }
    for (int i = 0; i < bigLettersSize; ++i) {
        std::cout << bigLetters[i];
    }
    delete[] num;
    delete[] bigLetters;
    delete[] smallLetters;
}

