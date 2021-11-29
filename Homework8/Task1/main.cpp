#include <bits/stdc++.h>
#include <queue>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout << std::fixed << std::setprecision(1);

    int citizens = 0;
    std::cin >> citizens;

    // max compare function
    auto maxCmp = [](auto &a, auto &b) {
        return a < b;
    };
    //min compare
    auto minCmp = [](auto &a, auto &b) {
        return a > b;
    };

    std::priority_queue<double, std::vector<double>, decltype(maxCmp)> smallWealthCitizens(maxCmp);
    std::priority_queue<double, std::vector<double>, decltype(minCmp)> bigWealthCitizens(minCmp);

    //print the wealth of the first citizen
    double firstCitizen = 0;
    std::cin >> firstCitizen;
    printf("%.1f\n", firstCitizen);
    smallWealthCitizens.push(firstCitizen);

    //continue with the other citizens
    for (int i = 1; i < citizens; ++i) {
        double citizenWealth = 0;
        std::cin >> citizenWealth;
        //check if the wealth of the citizen is negative
        if (citizenWealth < 0) {
            continue;
        }
        //push to the queue with citizens with small wealth
        smallWealthCitizens.push(citizenWealth);

        //make the two queues most equal by size,
        //by pushing the biggest in the queue with small wealth citizens
        //in the queue with big wealth citizens
        bigWealthCitizens.push(smallWealthCitizens.top());
        smallWealthCitizens.pop();
        //if the queue with small wealth citizens is smaller
        //push the smallest in the queue with big wealth citizens
        //in the queue with small wealth citizens
        if (smallWealthCitizens.size() < bigWealthCitizens.size()) {
            smallWealthCitizens.push(bigWealthCitizens.top());
            bigWealthCitizens.pop();
        }
        
        //if the size of the citizens are odd
        //print the middle citizen as median
        if (smallWealthCitizens.size() > bigWealthCitizens.size()) {
            printf("%.1f\n", smallWealthCitizens.top());
        }
        //if the size of the citizens are even,
        //calculate the median and print it
        else {
            printf("%.1f\n", ((smallWealthCitizens.top() + bigWealthCitizens.top()) / 2));
        }
    }
    return 0;
}
