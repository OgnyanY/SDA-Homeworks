#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main() {
    std::string lectures;
    std::cin >> lectures;
    std::vector<std::pair<int, int>> unique;
    //histogram for ascii symbols
    std::vector<std::pair<int,int>> ascii(127);

    int maxASCII = 0;// max ascii for lecture
    int minASCII = 0;// min ascii for lecture
    for (int i = 0; i < lectures.size(); ++i) {
        int code = (int)(unsigned char )lectures[i];//take ascii code
        if(code > maxASCII){
            maxASCII = code;
        }
        if(code < minASCII){
            minASCII = code;
        }
        ++ascii[code].first;
        ascii[code].second = i;
    }

    for (int i = minASCII; i <= maxASCII; ++i) {
        if(ascii[i].first == 1) {//find unique
            unique.push_back(ascii[i]);
        }
    }
    //sort indexes
    std::sort(unique.begin(),unique.end(),
              [](std::pair<int, int>& left, std::pair<int, int>& right){
        return left.second < right.second;
    });

    for (auto & i : unique) {
        std::cout << i.second << " ";
    }
}