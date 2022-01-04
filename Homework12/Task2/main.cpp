#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <queue>

struct Edge {
    long long from;
    long long to;
    long long effort;
    long long profit;
    long long index;

    Edge(long long from = 0, long long to = 0, long long effort = 0, long long profit = 0, long long index = 0) {
        this->from = from;
        this->to = to;
        this->effort = effort;
        this->profit = profit;
        this->index = index;
    }

    bool operator<(const Edge &rhs) const {
        if (this->effort > rhs.effort) {
            return true;
        } else if (this->effort == rhs.effort) {
            return this->profit < rhs.profit;
        }
        return false;
    }
};

std::vector<long long> prim(long long cities, long long paths) {
    // make graph from the data
    std::unordered_map<long long, std::vector<Edge>> edges;
    for (int i = 0; i < paths; ++i) {
        long long start = 0, end = 0, effort = 0, profit = 0;
        std::cin >> start >> end >> effort >> profit;
        Edge edge1(start, end, effort, profit, i + 1);
        Edge edge2(end, start, effort, profit, i + 1);
        edges[start].push_back(edge1);
        edges[end].push_back(edge2);
    }

    std::vector<long long> indexes;
    //unordered_set with visited nodes
    std::unordered_set<long long> visited;

    //queue with nodes to check
    std::priority_queue<Edge> nextToProcess;
    nextToProcess.push({-1, 1, 0, 0, 0});

    while (!nextToProcess.empty()) {
        //take next node
        Edge next = nextToProcess.top();
        nextToProcess.pop();
        long long child = next.to;

        //if the node is already visited continue
        if (visited.count(child) > 0) {
            continue;
        }
        visited.insert(child);

        long long parent = next.from;

        //if the current edge is not the first
        if (parent != -1) {
            indexes.push_back(next.index);
        }

        //take neighbours
        for (auto neighbour: edges[child]) {
            nextToProcess.push(neighbour);
        }
    }
    return indexes;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    long long cities = 0, paths = 0;
    std::cin >> cities >> paths;

    std::vector<long long> indexes = prim(cities, paths);
    std::sort(indexes.begin(), indexes.end());
    for (long long index: indexes) {
        std::cout << index << '\n';
    }
}
