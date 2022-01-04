#include <iostream>
#include <unordered_map>
#include <vector>

struct Edge {
    int from;
    int to;

    Edge(int from = 0, int to = 0) {
        this->from = from;
        this->to = to;
    }
};

std::vector<int> kruskal(int cities, int paths) {
    // make graph from the data
    std::vector<Edge> edges;
    for (int i = 0; i < paths; ++i) {
        int start = 0, end = 0;
        std::cin >> start >> end;
        Edge edge(start,end);
        edges.push_back(edge);
    }
    std::vector<int> components(cities);
    for (int i = 0; i < cities; i++) {
        components[i] = i;
    }

    for (Edge edge: edges) {
        if (components[edge.from] != components[edge.to]) {
            int oldComponent = components[edge.from];
            int newComponent = components[edge.to];
            for (int i = 0; i < components.size(); i++) {
                if (components[i] == oldComponent){
                    components[i] = newComponent;
                }
            }
        }
    }
    return components;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int cities = 0, paths = 0;
    std::cin >> cities >> paths;
    std::vector<int> components = kruskal(cities,paths);

    int questions = 0;
    std::cin >> questions;
    for (int i = 0; i < questions; ++i) {
        int x = 0,from = 0, to = 0;
        std::cin >> x >> from >> to;
        if(x == 1){
            if (components[from] != components[to]) {
                std::cout << 0;
            }
            if (components[from] == components[to]) {
                std::cout << 1;
            }
        }
        if(x == 2){
            if (components[from] != components[to]) {
                //tree.push_back(edge);
                int oldComponent = components[from];
                int newComponent = components[to];
                for (int j = 0; j < components.size(); j++) {
                    if (components[j] == oldComponent)
                        components[j] = newComponent;
                }
            }
        }
    }
}
