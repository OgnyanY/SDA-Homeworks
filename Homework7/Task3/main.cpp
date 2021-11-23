#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int numbersSize = 0, difference = 0;
    std::cin >> numbersSize >> difference;

    std::vector<int> numbers;
    for (int i = 0; i < numbersSize; ++i) {
        int num = 0;
        std::cin >> num;
        numbers.push_back(num);
    }
    bool find = false;
    for (int i = 0; i < numbersSize; ++i) {
        for (int j = i - 1; j >= 0; --j) {
            if(numbers[i] > numbers[j] && numbers[i] - numbers[j] <= difference){
                std::cout << j << ' ';
                find = true;
                break;
            }
        }
        if(!find){
            std::cout << -1 << ' ';
        }
        find = false;
    }

    return 0;
}
