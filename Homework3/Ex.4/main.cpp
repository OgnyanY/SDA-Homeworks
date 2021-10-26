#include <iostream>
#include <vector>
#include <algorithm>

void mySum(const std::vector<int>& elements, int position, int maxSum){
    int counter = 0;
    for(int i = position - 1; i >= 0; --i){
        if(maxSum - elements[i] >= 0){
            maxSum -= elements[i];
            ++counter;
        }
        else {
            break;
        }
    }
    printf ("%d \n", counter);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int elSize = 0;
    int appSize  = 0;
    std::cin >> elSize >> appSize;
    std::vector<int> el;
    std::vector<std::pair<int,int>> app(appSize);

    for(int i = 0; i < elSize; ++i) {
        int element = 0;
        std::cin >> element;
        el.push_back(element);
    }
    for(int i = 0; i < appSize; ++i) {
        int s = 0;
        int p = 0;
        std::cin >> s >> p;

        app[i].first = s;
        app[i].second = p;
    }

    std::sort(el.begin(),el.end());//sort the elements

    for(int i = 0; i < appSize; ++i) {
        int biggestPossible = std::upper_bound (el.begin(), el.end(), app[i].second) - el.begin();
        mySum(el,biggestPossible,app[i].first);//count how elements we can get
    }
}