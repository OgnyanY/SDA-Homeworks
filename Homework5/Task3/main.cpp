#include <iostream>
#include <vector>
#include <deque>

long long int MinSum (std::vector<int>& numbers, int windowSize){
    std::deque<std::pair<int,int>>window;
    std::vector<int> answer;
    long long int sum = 0;

    for (int i = 0; i < numbers.size(); ++i) {
        //This is to remove the front element,
        //if the window size is bigger of the wanted
        if(!window.empty() && window.front().second <= (i - windowSize)) {
            window.pop_front();
        }

        //if the current element is smaller from the last element in the window,
        //pop the last element, until meet smaller element in the window.
        //That way the smaller possible is on front of the window
        while(!window.empty() && window.back().first >= numbers[i]) {
            window.pop_back();
        }

        //push the current element in the window
        std::pair<int, int> temp;
        temp.first = numbers[i];
        temp.second = i;
        window.push_back(temp);

        //if the size is enough push the max in the vector
        if(i >= (windowSize - 1)) {
            answer.push_back(window.front().first);
        }
    }
    for (int x : answer) {
        sum += x;
    }
    return sum;
}

int main() {
    int numbersSize = 0;
    int window = 0;
    std::cin >> numbersSize >> window;
    std::vector<int> numbers;

    for (int i = 0; i < numbersSize; ++i) {
        int number = 0;
        std::cin >> number;
        numbers.push_back(number);
    }
    std::cout << MinSum(numbers, window);
}
