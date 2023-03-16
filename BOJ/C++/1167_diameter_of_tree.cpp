#include <iostream>
#include <vector>
#include <queue>

static const int kMAX = 100001;

static std::vector<std::pair<int, int>> gGraph[kMAX];
static std::vector<int> gVisited(kMAX);

void BFS(const int& startNode,
    int& treeDiameter, int& deepestNode) {
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

                if (treeDiameter < gVisited[node.first]) {
                    treeDiameter = gVisited[node.first];
                    deepestNode = node.first;
                }
            }
        }
    }
}

int main() {
    int n = 0;
    std::cin >> n;
    
    while (n--) {
        int u = 0, v = 0, w = 0;
        std::cin >> u;

        while (true) {
            std::cin >> v;

            if (v < 0) {
                break;
            }
            
            std::cin >> w;
            
            gGraph[u].emplace_back(
                std::make_pair(v, w)
            );
        }
    }

    int treeDiameter = 0, deepestNode = 0;

    std::fill(gVisited.begin(), gVisited.end(), -1);
    BFS(1, treeDiameter, deepestNode);

    std::fill(gVisited.begin(), gVisited.end(), -1);
    BFS(deepestNode, treeDiameter, deepestNode);

    std::cout << treeDiameter;
    return 0;
}