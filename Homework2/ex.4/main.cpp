#include <iostream>
#include <vector>
#include <algorithm>

bool Compare(std::vector<double>& a, std::vector<double>& b){
    if((a[0] * a[0] / a[1]) > (b[0] * b[0] / b[1])) {
        return true;
    }
    if((a[0] * a[0] / a[1]) == (b[0] * b[0] / b[1]) && (a[0] < b[0])) {
        return false;
    }
    if((a[0] * a[0] / a[1]) == (b[0] * b[0] / b[1]) && (a[0] > b[0])){
        return true;
    }
    else{
        return false;
    }
}

void merge(std::vector<std::vector<double>>& arr,
           std::vector<std::vector<double>>& mergeArr, int start, int mid, int end) {
    int left = start;
    int right = mid + 1;

    for(int i = start; i <= end; ++i) {
        if(left <= mid && (right > end || Compare(arr[left],arr[right]))){
            mergeArr[i] = arr[left];
            ++left;
        }
        else {
            mergeArr[i] = arr[right];
            ++right;
        }
    }

    for(int i = start; i <= end; ++i) {
        arr[i] = mergeArr[i];
    }
}

void mergeSortRecursion(std::vector<std::vector<double>>& arr,
                        std::vector<std::vector<double>>& mergeArr, int start, int end) {
    if(start < end) {
        int mid = (start + end) / 2;

        mergeSortRecursion(arr, mergeArr, start, mid);
        mergeSortRecursion(arr, mergeArr, mid + 1, end);

        merge(arr, mergeArr, start, mid, end);
    }
}

void mergeSort (std::vector<std::vector<double>>& arr, int length) {
    std::vector<std::vector<double>> mergeArr(length);
    mergeSortRecursion(arr, mergeArr, 0, length-1);
}

int main() {

    int boysSize = 0;
    std::cin >> boysSize;
    std::vector<std::vector<double>> arr(boysSize);
    for(int i = 0; i < boysSize; ++i) {
        double d = 0;
        double t = 0;
        std::cin >> d >> t;
        arr[i].push_back(d);
        arr[i].push_back(t);
        arr[i].push_back(i + 1);
    }

    mergeSort(arr, boysSize);

    for (int i = 0; i < boysSize; i++) {
        std::cout << arr[i][2] << " ";
    }
}
