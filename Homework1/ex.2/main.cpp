#include <iostream>
#include <vector>
#include <algorithm>
int FootballTeam (std::vector<int> arr, const int size){
    std::sort(arr.begin(), arr.end());
    bool positive = false;

    for(int i = 0;i < size;++i){
        if(arr[i] <= 0){
            continue;
        }

        positive = true;

        if(arr[i-1] <= 0 && arr[i] > 1){
            return 1;
        }
        if(arr[i] + 1 < arr[i + 1]){
            return arr[i] + 1;
        }
        if(arr[i] == arr[size-1]){
            return arr[i]+1;
        }
    }
    if(!positive){
        return 1;
    }
    return 0;
}

int main() {
    int number = 0;
    std:: cin >> number;
    std::vector<int> arr;
    for(int i = 0; i < number;++i){
        int num;
        std::cin >> num;
        arr.push_back(num);
    }
    std::cout << FootballTeam(arr, number);
    return 0;
}
