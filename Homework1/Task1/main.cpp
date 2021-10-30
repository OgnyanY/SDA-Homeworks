#include <iostream>
#include <string>
#include <vector>
void Seats (std::string str, const char test){
    std::vector<int> arr;
    int counter = 1;
    bool isFound = false;

    for(int i = 0; i < str.size(); ++i){
        //we assign a temporal value to the unknown tests
        // until we find the same test we are looking for
        if(str[i] != test && !isFound){//
            arr.push_back(-1);
            continue;
        }
        if(str[i] == test){//find first same test
            arr.push_back(0);
            isFound = true;
            counter = 1;
        }
        if(str[i] != test && isFound){//assign space on left to right
            arr.push_back(counter);
            ++counter;
        }
    }

    isFound = false;
    counter = 1;
    for(int i = str.size() - 1; i >= 0; --i){
        //pass the first spaces until wi find one with the same test
        if(str[i] != test && !isFound){
            continue;
        }
        if(str[i] == test){//find same test
            isFound = true;
            counter = 1;
            continue;
        }
        //take the minimum value of the space or
        //fix "-1" for the first places with different test
        if(str[i] != test && isFound){
            if(arr[i] == -1){
                arr[i] = counter;
                ++counter;
            }
            if(counter < arr[i]){
                arr[i] = counter;
                ++counter;
            }
        }
    }

    for(int i : arr){
        std::cout << i << ' ';
    }
}
int main() {
    std::string word;
    char test;
    std:: cin >> word >> test;
    Seats(word, test);
    return 0;
}
