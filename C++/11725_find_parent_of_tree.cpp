#include <iostream>
#include <vector>
#include <queue>

static const int kMAX = 100001;

static std::vector<int> gTreeRoots(kMAX);
static std::vector<int> gGraph[kMAX];
static std::vector<bool> gVisited(kMAX);

void BFS() {
    std::queue<int> bfsQueue;
    gVisited[1] = true;
    bfsQueue.push(1);

    while (!bfsQueue.empty()) {
        int parent = bfsQueue.front();
        bfsQueue.pop();

        for (const auto& child : gGraph[parent]) {
            if (!gVisited[child]) {
                gTreeRoots[child] = parent;
                gVisited[child] = true;
                bfsQueue.push(child);
            }
        }
    }
}

int main() {
    int n = 0;
    std::cin >> n;
    
    for (int i = 1; i < n; ++i) {
        int u = 0, v = 0;
        std::cin >> u >> v;

        gGraph[u].emplace_back(v);
        gGraph[v].emplace_back(u);
    }

    BFS();

    for (int i = 2; i <= n; ++i) {
        std::cout << gTreeRoots[i] << '\n';
    }
    return 0;
}