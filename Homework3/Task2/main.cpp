#include <iostream>
#include <vector>

void merge(std::vector<int>& arr, std::vector<int>& mergeArr, int start, int mid, int end) {
    int left = start;
    int right = mid + 1;

    //sort the elements
    for(int i = start; i <= end; ++i) {
        //this is when the left element is smaller
        if(left <= mid && (right > end ||arr[left] <=arr[right])){
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

void mergeSortRecursion(std::vector<int>& arr, std::vector<int>& mergeArr, int start, int end) {
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

void mergeSort (std::vector<int>& arr, int length) {
    std::vector<int> mergeArr(length);//this is the array where we merge
    //this is the recursive function for merging
    mergeSortRecursion(arr, mergeArr, 0, length - 1);
}

//this is binary search and return two possible elements for theme
std::vector<int> myBinarySearch(const std::vector<int>& arr, int length, int target) {
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

void getTheme(const std::vector<int>& teams, const std::vector<int>& themes){
    for(int team : teams) {
        std::vector<int> twoPossible = myBinarySearch(themes, themes.size(), team);
        //this is if we are found already the theme
        if(twoPossible[1] == -100){
            std::cout << twoPossible[0] << std::endl;
            continue;
        }
        //this is if the theme is first
        if(twoPossible[0] == team){
            std::cout << twoPossible[0] << std::endl;
            continue;
        }
        //this is if the theme is second
        if(twoPossible[1] == team){
            std::cout << twoPossible[1] << std::endl;
            continue;
        }
        //get the better theme
        if((twoPossible[1] - team) >= (team - twoPossible[0])){
            std::cout << twoPossible[0] << std::endl;
            continue;
        }
        else {
            std::cout << twoPossible[1] << std::endl;
            continue;
        }
    }
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

    mergeSort(themes, themesSize);//sort the themes
    getTheme(teams,themes);//get themes
}
