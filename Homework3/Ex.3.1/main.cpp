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

int myBinarySearch(std::vector<std::pair<int,int>>& arr, int left, int right, std::pair<int,int> target) {
    while(left <= right) {
        int mid = (left + right) / 2;

        if ((target.first > arr[mid].first && target.second > arr[mid].second)
            && (arr[mid + 1].first > target.first || arr[mid + 1].second > target.second)) {
            return mid+1;
        }
        if (arr[mid].first > target.first && arr[mid].second > target.second) {
            right = mid -1;
        }
        if (arr[mid].first < target.first || arr[mid].second < target.second) {
            left = mid + 1;
        }
    }
    return -1;
}

int LISLength(std::vector<std::pair<int,int>>& arr)
{
    if (arr.size() == 0){
        return 0;
    }

    std::vector<std::pair<int,int>> sequence(arr.size());
    std::vector<int> lengths;

    int length = 1; // always points empty slot in sequence

    sequence[0] = arr[0];
    for (size_t i = 1; i < arr.size(); i++) {
        // new smallest value
        if (arr[i].first < sequence[0].first && arr[i].second < sequence[i].second){
            sequence[0] = arr[i];
        }
            // arr[i] extends largest subsequence
        else if (arr[i].first > sequence[length - 1].first && arr[i].second > sequence[length - 1].second){
            sequence[length++] = arr[i];
        }
        else {
            lengths.push_back(length);
            int newLength = myBinarySearch(sequence, 0, length - 1, arr[i]);
            if(newLength == -1){
                continue;
            }
            sequence[newLength] = arr[i];
            length = newLength + 1;
        }
    }

    int maxLength = lengths[0];
    for (int i : lengths) {
        if(maxLength < i){
            maxLength = i;
        }
    }
    return maxLength;
}

int main() {
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

    std::cout << LISLength(arr);
}