#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <queue>

bool isConnected(std::unordered_map<int, std::vector<int>> graph, int nodes) {
    //unordered_set with visited nodes
    std::unordered_set<int> visited;

    //queue with nodes to check
    std::priority_queue<int> nextToProcess;
    nextToProcess.push({graph.begin()->first});

    while (!nextToProcess.empty()) {
        //take current node
        int current = nextToProcess.top();
        nextToProcess.pop();

        //if the node is already visited continue
        if (visited.count(current) > 0) {
            continue;
        }
        visited.insert(current);

        //take neighbours
        for (auto neighbour: graph[current]) {
            nextToProcess.push(neighbour);
        }
    }

    if (visited.size() < nodes) {
        return false;
    } else {
        return true;
    }
}

void isEulerian(const std::unordered_map<int, std::vector<int>> &graph, int nodes) {
    if (!isConnected(graph, nodes)) {
        std::cout << "none";
        return;
    }

    int odd = 0;
    for (auto const &i: graph) {
        if (i.second.size() % 2 != 0) {
            ++odd;
        }
    }

    if (odd == 0) {
        std::cout << "ecycle";
        return;
    } else if (odd == 2) {
        std::cout << "epath";
        return;
    } else {
        std::cout << "none";
        return;
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int queries;
    std::cin >> queries;
    for (int i = 0; i < queries; ++i) {
        int nodes, edges;
        std::cin >> nodes >> edges;
        std::unordered_map<int, std::vector<int>> graph;
        for (int j = 0; j < edges; ++j) {
            int start = 0, end = 0;
            std::cin >> start >> end;

            graph[start].push_back(end);
            graph[end].push_back(start);
        }
        isEulerian(graph, nodes);
        std::cout << '\n';
    }
}