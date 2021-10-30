#include <iostream>
#include <vector>
#include <algorithm>

//this function compare effectivity
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

    //sort the elements
    for(int i = start; i <= end; ++i) {
        //this is when the left element is bigger
        if(left <= mid && (right > end || Compare(arr[left],arr[right]))){
            mergeArr[i] = arr[left];
            ++left;
        }
        else {//this is when the right element is bigger
            mergeArr[i] = arr[right];
            ++right;
        }
    }
    //assign the already sorted elements
    for(int i = start; i <= end; ++i) {
        arr[i] = mergeArr[i];
    }
}

void mergeSortRecursion(std::vector<std::vector<double>>& arr,
                        std::vector<std::vector<double>>& mergeArr, int start, int end) {
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

void mergeSort (std::vector<std::vector<double>>& arr, int length) {
    std::vector<std::vector<double>> mergeArr(length);//this is the array where we merge
    //this is the recursive function for merging
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
        //push back diameter time and place of the boy
        arr[i].push_back(d);
        arr[i].push_back(t);
        arr[i].push_back(i + 1);
    }

    mergeSort(arr, boysSize);//sort the data

    for (int i = 0; i < boysSize; i++) {
        std::cout << arr[i][2] << " ";
    }
}
