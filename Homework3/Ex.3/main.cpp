#include <iostream>
#include <vector>

void merge(std::vector<std::pair<int,int>>& arr,
           std::vector<std::pair<int,int>>& mergeArr, int start, int mid, int end) {
    int left = start;
    int right = mid + 1;

    //sort the elements
    for(int i = start; i <= end; ++i) {
        //this is when the left element is smaller
        if(left <= mid && (right > end || arr[left] < arr[right])) {
            mergeArr[i] = arr[left];
            ++left;
        }
        else {//this is when the right element is smaller
            mergeArr[i] = arr[right];
            ++right;
        }
    }
    //assign the already sorted elements
    for(int i = start; i <= end; ++i) {
        arr[i] = mergeArr[i];
    }
}

void mergeSortRecursion(std::vector<std::pair<int,int>>& arr,
                        std::vector<std::pair<int,int>>& mergeArr, int start, int end) {
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

void mergeSort (std::vector<std::pair<int,int>>& arr, int length) {
    std::vector<std::pair<int,int>> mergeArr(length);//this is the array where we merge
    //this is the recursive function for merging
    mergeSortRecursion(arr, mergeArr, 0, length - 1);
}

void killDemon(std::vector<std::pair<int,int>> const& demons) {
    std::vector<int> kills(demons.size(), 1);
    for (size_t i = 0; i < demons.size(); i++) {
        for (size_t j = 0; j < i; j++) {
            if (demons[j].first < demons[i].first && demons[j].second < demons[i].second) {
                if(kills[i] < (kills[j] + 1)){
                    kills[i] = kills[j] + 1;
                }
                else{
                    continue;
                }
            }
        }
    }

    int result = kills[0];
    for (size_t i = 1; i < demons.size(); i++) {
        if(result < kills[i]){
            result = kills[i];
        }
        else{
            continue;
        }
    }
    std::cout << result;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int demonsSize = 0;
    std::cin >> demonsSize;
    std::vector<std::pair<int,int>> arr(demonsSize);

    for(int i = 0; i < demonsSize; ++i) {
        int def = 0;
        int atk = 0;
        std::cin >> def >> atk;

        arr[i].first = def;
        arr[i].second = atk;
    }
    mergeSort(arr, demonsSize);
    killDemon(arr);
}