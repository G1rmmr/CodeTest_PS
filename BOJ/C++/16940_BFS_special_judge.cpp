#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

bool BFS (
    const int& startNode,
    const std::vector<int>& searchOrder,
    const std::vector<std::vector<int>>& graph,
    std::vector<bool> visited) {
    std::queue<int> bfsQueue;
    int orderSeq = 2;

    bfsQueue.push(startNode);
    visited[startNode] = true;

    while (!bfsQueue.empty()) {
        int nodeX = bfsQueue.front();
        bfsQueue.pop();

        for (auto nodeY : graph[nodeX]) {
            if (visited[nodeY]) {
                continue;
            }

            if (!visited[nodeY]
                && searchOrder[nodeY] == orderSeq) {
                bfsQueue.push(nodeY);
                visited[nodeY] = true;
                orderSeq++;
            } else if (searchOrder[nodeY] != orderSeq) {
                return false;
            }
        }
    }
    return true;
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

    for (int num = 1; num <= n; ++num) {
        int i;
        std::cin >> i;
        
        searchOrder[i] = num;
    }

    for (int i = 1; i <= n; ++i) {
        std::sort(graph[i].begin(), graph[i].end(), [&]
            (const int& node1, const int& node2) {
                return searchOrder[node1] < searchOrder[node2];
            }
        );
    }

    if (BFS(1, searchOrder, graph, visited)) {
        std::cout << 1;
    } else {
        std::cout << 0;
    }
    return 0;
}