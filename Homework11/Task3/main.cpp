#include <iostream>
#include <unordered_map>
#include <vector>
#include <unordered_set>
#include <queue>

struct Node {
    int end;
    int weight;

    Node(int end = 0, int weight = 0) {
        this->end = end;
        this->weight = weight;
    }

    friend bool operator<(const Node &lhs, const Node &rhs) {
        return lhs.weight > rhs.weight;
    }
};

void shortestPath(int N, int M) {
    int MAX = 2147483647;
    // make graph from the data
    std::unordered_map<int, std::vector<Node>> graph;
    for (int i = 0; i < M; ++i) {
        int start = 0, end = 0, weight = 0;
        std::cin >> start >> end >> weight;
        Node endNode(end, weight);
        Node startNode(start, weight);
        graph[start].push_back(endNode);
        graph[end].push_back(startNode);
    }

    //unordered_set with visited nodes
    std::unordered_set<int> visited;
    //unordered_map withs nodes and their distance
    std::unordered_map<int, int> dist;
    for (int i = 0; i < N; i++) {
        dist[i] = MAX;
    }

    //queue with nodes to check
    std::priority_queue<Node> next;
    int K = 0;
    std::cin >> K;
    //take the nodes in T and push them in the queue
    for (int i = 0; i < K; ++i) {
        int T = 0;
        std::cin >> T;
        //push the beginning nodes
        Node node(T, 0);
        next.push(node);
        dist[T] = 0;
    }

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
            int weight = edge.weight;
            //if the distance of the node is bigger than current,
            //the new distance is current
            if (dist[child] > dist[current.end] + weight) {
                dist[child] = dist[current.end] + weight;
                Node newNode(edge.end, dist[current.end] + weight);
                next.push(newNode);
            }
        }
    }
    //take requests
    int Q = 0;
    std::cin >> Q;
    for (int i = 0; i < Q; ++i) {
        int x = 0;
        std::cin >> x;
        std::cout << dist[x] << '\n';
    }

}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int N = 0, M = 0;
    std::cin >> N >> M;
    shortestPath(N, M);
}
