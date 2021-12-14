#include <iostream>
#include <bits/stdc++.h>
//#include <vector>
#include <set>
#include <unordered_map>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int applicationSize = 0;
    std::cin >> applicationSize;

    std::unordered_map<int, std::set<int>> applications;
    bool answer = false;

    for (int i = 0; i < applicationSize; ++i) {
        int edges = 0;
        std::cin >> edges;
        for (int j = 0; j < edges; ++j) {
            int start = 0, end = 0;
            std::cin >> start >> end;
            applications[end].insert(start);
            for (auto it = applications[start].begin(); it != applications[start].end(); ++it) {
                applications[end].insert(*it);
            }

            if (applications[end].count(end) > 0) {
                answer = true;
                std::cout << true << ' ';
                break;
            }
        }
        if (!answer) {
            std::cout << false << ' ';
        }
        applications.clear();
    }
}

