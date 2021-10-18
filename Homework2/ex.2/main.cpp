#include <iostream>
#include <string>
#include <vector>

bool Compare(std::vector<int>& a, std::vector<int>& b){
    for(int i = 5; i >= 0; --i) {
        if(a[i] < b[i]){
            return true;
        }
        else if(a[i] > b[i]){
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

void mergeSortRecursion(std::vector<std::vector<int>>& arr,
                        std::vector<std::vector<int>>& mergeArr, int start, int end) {
    if(start < end) {
        int mid = (start + end) / 2;

        mergeSortRecursion(arr, mergeArr, start, mid);
        mergeSortRecursion(arr, mergeArr, mid + 1, end);

        merge(arr, mergeArr, start, mid, end);
    }
}

void mergeSort (std::vector<std::vector<int>>& arr, int length) {
    std::vector<std::vector<int>> mergeArr(length);
    mergeSortRecursion(arr, mergeArr, 0, length-1);
}
int main() {
    int dataSize = 0;
    std::cin >> dataSize;
    std::vector<std::vector<int>> arr(dataSize);
    for(int i = 0; i < dataSize; ++i){
        if (i == 0) {
            std::string bin;
            getline(std::cin, bin);
        }
        std::string s;
        std::string sTemp;

        std::getline(std::cin,s);
        for(size_t j = 0; j < s.length(); ++j){
            if(j == s.length()-1){
                sTemp += s[j];
                arr[i].push_back(std::stoi(sTemp));
                sTemp.erase();
            }
            else if(s[j] != ':' && s[j] != ' ' && s[j] != '.'){
                sTemp += s[j];
                continue;
            }
            else{
                arr[i].push_back(std::stoi(sTemp));
                sTemp.erase();
            }
        }
        std::swap(arr[i][0],arr[i][2]);
        arr[i].push_back(i + 1);
    }

    mergeSort(arr,dataSize);

    for(auto & i : arr){
        std::cout << i[6] << std::endl;
    }
}
