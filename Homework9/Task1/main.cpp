#include <iostream>
#include <bits/stdc++.h>
#include <vector>
#include <unordered_map>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    //insert how many keys and doors Mario will find
    int movesSize = 0;
    std::cin >> movesSize;

    //insert all keys
    std::vector<int> keys(movesSize);
    for (int i = 0; i < movesSize; ++i) {
        int key = 0;
        std::cin >> key;
        keys[i] = key;
    }

    std::unordered_map<int, int> mario;
    int crushedDoors = 0;
    for (int i = 0; i < movesSize; ++i) {
        mario[keys[i]] += 1;//Mario find key
        int door = 0;
        std::cin >> door;
        //if the key open a door, remove it
        if (mario[door] > 0) {
            mario[door] -= 1;
        } else {// otherwise, broke the door
            ++crushedDoors;
        }
    }
    std::cout << crushedDoors;
}
