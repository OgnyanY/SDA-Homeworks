#include <iostream>
#include <unordered_map>
#include <vector>
#include <unordered_set>
#include <queue>

struct Node {
    int end;
    long long weight;

    Node(int end = 0, long long weight = 0) {
        this->end = end;
        this->weight = weight;
    }

    friend bool operator<(const Node &lhs, const Node &rhs) {
        return lhs.weight > rhs.weight;
    }
};

void shortestPath(int begin, int paths, int final) {
    long long MAX = 9223372036854775807;
    // make graph from the data
    std::unordered_map<long long, std::vector<Node>> graph;
    for (int i = 0; i < paths; ++i) {
        int start = 0, end = 0, weight = 0;
        std::cin >> start >> end >> weight;
        graph[start].push_back({end, weight});
    }

    //set with visited nodes
    std::unordered_set<int> visited;
    //unordered_map withs nodes, their distance and how much we found that distance
    std::unordered_map<int, std::pair<long long, int>> dist;
    for (int i = 1; i <= final; i++) {
        dist[i].first = MAX;
        dist[i].second = 0;
    }

    //queue with nodes to check
    std::priority_queue<Node> next;
    //push the beginning node
    Node node(begin, 0);
    next.push(node); //first element
    dist[begin].first = 0;
    dist[begin].second = 1;


    while (!next.empty()) {
        //take next node
        auto current = next.top();
        next.pop();

        //if the node is already visited continue
        if (visited.count(current.end) > 0) {
            continue;
        }
        visited.insert(current.end);

        for (auto edge: graph[current.end]) {
            int child = edge.end;
            long long weight = edge.weight;
            //if the distance of the node is bigger than current,
            //new distance is current
            if (dist[child].first > dist[current.end].first + weight) {
                dist[child].first = dist[current.end].first + weight;
                dist[child].second = (dist[current.end].second) % 1000000007;
                Node newNode(edge.end, dist[current.end].first + weight);
                next.push(newNode);

            }
                //if the distance of the node is equal to current,
                //increase the counter of the distance
            else if (dist[child].first == dist[current.end].first + weight) {
                dist[child].second = (dist[child].second + dist[current.end].second) % 1000000007;
            }
        }
    }
    //if there is path to the last node
    if (dist[final].second) {
        std::cout << dist[final].first << ' ' << dist[final].second;
    }
        //if there is no path to the last node
    else {
        std::cout << -1 << ' ' << 0;
    }


}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int final = 0, paths = 0;
    std::cin >> final >> paths;
    shortestPath(1, paths, final);
}
