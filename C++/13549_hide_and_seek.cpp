#include <iostream>
#include <vector>
#include <queue>

static const int kMAX = 100001;

static std::vector<int> gGraph(kMAX);

int BFS(const int& n, const int& k) {
    std::queue<int> bfsQueue;
    bfsQueue.push(n);

    while (!bfsQueue.empty()) {
        int node = bfsQueue.front();
        bfsQueue.pop();

        if (node == k || node * 2 == k) {
            return gGraph[node];
        }

        if (node * 2 >= 0 && node * 2 < kMAX
            && !gGraph[node * 2]) {
            gGraph[node * 2] = gGraph[node];
            bfsQueue.push(node * 2);
        }

        if (node - 1 >= 0 && node - 1 < kMAX
            && !gGraph[node - 1]) {
            gGraph[node - 1] = gGraph[node] + 1;
            bfsQueue.push(node - 1);
        }

        if (node + 1 >= 0 && node + 1 < kMAX
            && !gGraph[node + 1]) {
            gGraph[node + 1] = gGraph[node] + 1;
            bfsQueue.push(node + 1);
        }
    }
}

int main() {
    int n, k;
    std::cin >> n >> k;

    std::cout << BFS(n, k);
    return 0;
}