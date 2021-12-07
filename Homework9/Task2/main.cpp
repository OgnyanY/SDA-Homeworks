#include <iostream>
#include <unordered_map>
#include <set>

struct Kilogram {
    int value = 0;
    int number = 0;
    //int index = 0;

    Kilogram(int value = 0, int number = 0) {
        this->value = value;
        this->number = number;
    }

    friend bool operator<(Kilogram const &lhs, Kilogram const &rhs) {
        return lhs.value > rhs.value;
    }

    friend bool operator==(Kilogram const &lhs, Kilogram const &rhs) {
        return lhs.value == rhs.value;
    }
};

int main() {
    int animalsSize = 0, criterion = 0;
    std::cin >> animalsSize >> criterion;
    int result = 0;

    std::unordered_map<int, int> animals;
    std::set<int> sorted;
    for (int i = 0; i < animalsSize; ++i) {
        int animal;
        std::cin >> animal;
        sorted.insert(animal);
        animals[animal] += 1;
    }
    std::set<int>::iterator();
    for (auto first = sorted.begin(); first != --(--sorted.end()); first++) {

        for (auto second = first; second != --sorted.end();) {
            ++second;
            if (*second == *first * criterion) {

                for (auto third = second; third != sorted.end();) {
                    ++third;
                    if (*third == *second * criterion) {
                        result += animals[*first] * animals[*second] * animals[*third];
                        break;
                    } else if (*third < *second * criterion) {
                        continue;
                    } else {
                        break;
                    }
                }
            } else if (*second < *first * criterion) {
                continue;
            } else {
                break;
            }
        }

    }
    std::cout << result;

    return 0;
}
