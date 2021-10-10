#include <iostream>
#include <vector>
#include <algorithm>
int FootballTeam (std::vector<int> arr, const int size){
    std::sort(arr.begin(), arr.end());//sort the array
    bool positive = false;//this is to check if the digit is positive

    for(int i = 0; i < size; ++i){
        //check if the digit is negative
        if(arr[i] <= 0){
            continue;
        }
        positive = true;
        //check if there is smaller possible digit than the first positive-1
        if(arr[i-1] <= 0 && arr[i] > 1){
            return 1;
        }
        //check for possible digit
        if(arr[i] + 1 < arr[i + 1]){
            return arr[i] + 1;
        }
        //this is when there is no possible digit than the biggest+1
        if(arr[i] == arr[size-1]){
            return arr[i]+1;
        }
    }
    //if there is only negative digits
    if(!positive){
        return 1;
    }
    return 0;
}

int main() {
    int number = 0;
    std:: cin >> number;
    std::vector<int> arr;
    for(int i = 0; i < number; ++i){
        int num;
        std::cin >> num;
        arr.push_back(num);
    }
    std::cout << FootballTeam(arr, number);
    return 0;
}
