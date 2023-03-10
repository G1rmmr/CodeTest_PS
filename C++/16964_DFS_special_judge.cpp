#include <iostream>
#include <algorithm>
#include <vector>

void DFS (
    const int& startNode,
    const std::vector<std::vector<int>>& graph,
    std::vector<bool>& visited,
    std::vector<int>& dfsOrder) {
    if (visited[startNode]) {
        return;
    }
    
    visited[startNode] = true;
    dfsOrder.emplace_back(startNode);

    for (const auto& node : graph[startNode]) {
        if (!visited[node]) {
            DFS(node, graph, visited, dfsOrder);
        }
    }
}

int main() {
    int n;
    std::cin >> n;

    std::vector<std::vector<int>> graph(n + 1);
    std::vector<bool> visited (n + 1);

    for (int i = 0; i < n - 1; ++i) {
        int v, e;
        std::cin >> v >> e;

        graph[v].emplace_back(e);
        graph[e].emplace_back(v);
    }

    std::vector<int> searchOrder(n + 1);
    std::vector<int> orderBuffer(n + 1);

    for (int num = 1; num <= n; ++num) {
        std::cin >> orderBuffer[num];
        searchOrder[orderBuffer[num]] = num;
    }

    for (int i = 1; i <= n; ++i) {
        std::sort(graph[i].begin(), graph[i].end(), [&]
            (const int& node1, const int& node2) {
                return searchOrder[node1] < searchOrder[node2];
            }
        );
    }

    std::vector<int> dfsOrder(1);

    if (orderBuffer[1] == 1) {
        DFS(1, graph, visited, dfsOrder);
    }
    
    std::cout << (dfsOrder == orderBuffer ? 1 : 0);
    return 0;
}