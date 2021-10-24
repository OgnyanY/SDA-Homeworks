#include <iostream>
#include <vector>

void merge(std::vector<int>& arr, std::vector<int>& mergeArr, int start, int mid, int end) {
    int left = start;
    int right = mid + 1;

    for(int i = start; i <= end; ++i) {
        if(left <= mid && (right > end ||arr[left] <=arr[right])){
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

void mergeSortRecursion(std::vector<int>& arr, std::vector<int>& mergeArr, int start, int end) {
    if(start < end) {
        int mid = (start + end) / 2;

        mergeSortRecursion(arr, mergeArr, start, mid);
        mergeSortRecursion(arr, mergeArr, mid + 1, end);

        merge(arr, mergeArr, start, mid, end);
    }
}

void mergeSort (std::vector<int>& arr, int length) {
    std::vector<int> mergeArr(length);
    mergeSortRecursion(arr, mergeArr, 0, length - 1);
}


std::vector<int> myBinarySearch(std::vector<int>& arr, int length, int target) {
    int left = 0;
    int right = length - 1;
    std::vector<int> twoPossible(2);

    while(left <= right) {
        int mid = (left + right) / 2;

        if (mid == left) {
            twoPossible[0] = arr[left];
            twoPossible[1] = arr[right];
            return twoPossible;
        }
        if (arr[mid] == target) {
            twoPossible[0] = arr[mid];
            twoPossible[1] = -100;
            return twoPossible;
        }
        if (arr[mid] > target) {
            right = mid;
        }
        if (arr[mid] < target) {
            left = mid;
        }
    }
    return twoPossible;
}

int main() {

    int teamsSize = 0;
    int themesSize = 0;
    std::cin >> themesSize >> teamsSize;
    std::vector<int> teams;
    std::vector<int> themes;

    for(int i = 0; i < themesSize; ++i) {
        int theme = 0;
        std::cin >> theme;
        themes.push_back(theme);
    }
    for(int i = 0; i < teamsSize; ++i) {
        int team = 0;
        std::cin >> team;
        teams.push_back(team);
    }

    mergeSort(themes, themesSize);

    for(int i = 0; i < teamsSize; ++i) {
        std::vector<int> twoPossible = myBinarySearch(themes, themesSize, teams[i]);
        if(twoPossible[1] == -100){
            std::cout << twoPossible[0] << std::endl;
            continue;
        }
        if(twoPossible[0] == teams[i]){
            std::cout << twoPossible[0] << std::endl;
            continue;
        }
        if(twoPossible[1] == teams[i]){
            std::cout << twoPossible[1] << std::endl;
            continue;
        }

        if((twoPossible[1] - teams[i]) >= (teams[i] - twoPossible[0])){
            std::cout << twoPossible[0] << std::endl;
            continue;
        }
        else {
            std::cout << twoPossible[1] << std::endl;
            continue;
        }
    }
}
