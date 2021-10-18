#include <iostream>
#include <string>
#include <vector>

//this function compare dates
bool Compare(std::vector<int>& a, std::vector<int>& b) {
    for(int i = 5; i >= 0; --i) {//compare from year to seconds
        if(a[i] < b[i]) {
            return true;
        }
        else if(a[i] > b[i]) {
            return false;
        }
        else{
            continue;
        }
    }
    return true;
}

void merge(std::vector<std::vector<int>>& arr,
           std::vector<std::vector<int>>& mergeArr, int start, int mid, int end) {
    int left = start;
    int right = mid + 1;

    //sort the elements
    for(int i = start; i <= end; ++i) {
        //this is when the left element is smaller
        if(left <= mid && (right > end || Compare(arr[left],arr[right]))) {
            mergeArr[i] = arr[left];
            ++left;
        }
        else {//this is when the left element is smaller
            mergeArr[i] = arr[right];
            ++right;
        }
    }
    //assign the already sorted elements
    for(int i = start; i <= end; ++i) {
        arr[i] = mergeArr[i];
    }
}

void mergeSortRecursion(std::vector<std::vector<int>>& arr,
                        std::vector<std::vector<int>>& mergeArr, int start, int end) {
    //if there is only one element return
    if(start < end) {
        int mid = (start + end) / 2;

        //divide the array by two and continue until there is only two elements in the array
        //and then merge them
        mergeSortRecursion(arr, mergeArr, start, mid);
        mergeSortRecursion(arr, mergeArr, mid + 1, end);

        merge(arr, mergeArr, start, mid, end);
    }
}

void mergeSort (std::vector<std::vector<int>>& arr, int length) {
    std::vector<std::vector<int>> mergeArr(length);//this is the array where we merge
    //this is the recursive function for merging
    mergeSortRecursion(arr, mergeArr, 0, length - 1);
}

void FromDateToInt(std::vector<int>& arr, std::string str) {
    //a temporary string in which I
    //save the current element from the date
    std::string strTemp;
    for(size_t j = 0; j < str.length(); ++j) {
        if(j == str.length() - 1) {//this is when we reach the last element
            strTemp += str[j];
            arr.push_back(std::stoi(strTemp));
            strTemp.erase();
        }
        else if(str[j] != ':' && str[j] != ' ' && str[j] != '.') {//form the number of the element
            strTemp += str[j];
            continue;
        }
        else{//push back the element in the vector
            arr.push_back(std::stoi(strTemp));
            strTemp.erase();
        }
    }
    std::swap(arr[0],arr[2]);//swap hours with seconds
}

int main() {
    int dataSize = 0;
    std::cin >> dataSize;
    std::vector<std::vector<int>> arr(dataSize);

    for(int i = 0; i < dataSize; ++i) {
        if (i == 0) {//removing the remaining '\n'
            std::string bin;
            getline(std::cin, bin);
        }
        std::string str;
        std::getline(std::cin, str);

        FromDateToInt(arr[i], str);
        arr[i].push_back(i + 1);//insert in index 6 place of the date
    }
     mergeSort(arr,dataSize);//sort the dates

    for(auto & i : arr) {
    std::cout << i[6] << std::endl;
    }
}