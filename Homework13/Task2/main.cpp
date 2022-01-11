#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <queue>

std::queue<int> smth(int nodes) {
    // make graph from the data
    std::unordered_map<int, std::vector<int>> graph;
    std::vector<int> degree(nodes);
    for (int i = 0; i < nodes; ++i) {
        degree[i] = 0;
    }

    for (int i = 0; i < nodes - 1; ++i) {
        int start = 0, end = 0;
        std::cin >> start >> end;

        graph[start].push_back(end);
        graph[end].push_back(start);
        ++degree[start];
        ++degree[end];
    }

    std::queue<int> q;

    for (int i = 0; i < nodes; ++i) {
        if (degree[i] == 1) {
            q.push(i);
        }
    }

    while (nodes > 2) {
        int popElements = (int) q.size();
        nodes -= popElements;

        for (int i = 0; i < popElements; i++) {
            int t = q.front();
            q.pop();

            for (int &j: graph[t]) {
                --degree[j];
                if (degree[j] == 1)
                    q.push(j);
            }
        }
    }
    return q;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int nodes;
    std::cin >> nodes;

    std::queue<int> q = smth(nodes);
    std::vector<int> answer;
    while (!q.empty()) {
        answer.push_back(q.front());
        q.pop();
    }
    std::sort(answer.begin(), answer.end());
    for (int i: answer) {
        std::cout << i << ' ';
    }
}