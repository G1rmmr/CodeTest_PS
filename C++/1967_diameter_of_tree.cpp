#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

static const int kMAX = 10001;

static std::vector<std::pair<int, int>> gGraph[kMAX];
static std::vector<int> gVisited(kMAX);

void BFS(const int& startNode, int& treeDiameter) {
    gVisited[startNode] = 0;

    std::queue<int> bfsQueue;
    bfsQueue.push(startNode);

    while (!bfsQueue.empty()) {
        int nowNode = bfsQueue.front();
        bfsQueue.pop();

        for (const auto& node : gGraph[nowNode]) {
            if (gVisited[node.first] < 0) {
                gVisited[node.first] = 
                    gVisited[nowNode] + node.second;

                bfsQueue.push(node.first);

                treeDiameter = std::max(
                    treeDiameter, gVisited[node.first]
                );
            }
        }
    }
}

int main() {
    int n = 0;
    std::cin >> n;

    for (int i = 1; i < n; ++i) {
        int u = 0, v = 0, w = 0;
        std::cin >> u >> v >> w;
        
        gGraph[u].emplace_back(
            std::make_pair(v, w)
        );

        gGraph[v].emplace_back(
            std::make_pair(u, w)
        );
    }

    int treeDiameter = 0;

    for (int i = 1; i <= n; ++i) {
        std::fill(gVisited.begin(), gVisited.end(), -1);
        BFS(i, treeDiameter);
    }
    
    std::cout << treeDiameter;
    return 0;
}