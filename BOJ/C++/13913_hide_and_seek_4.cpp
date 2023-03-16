#include <iostream>
#include <vector>
#include <queue>

static const int kMAX = 100001;

static std::vector<int> gGraph(kMAX);
static std::vector<bool> gVisited(kMAX);

int BFS(
    std::vector<int>& pathTrace,
    const int& n, const int& k) {
    std::queue<std::pair<int, int>> bfsQueue;
    bfsQueue.push(std::make_pair(n, 0));
    gVisited[n] = true;
   
    while (!bfsQueue.empty()) {
        int node = bfsQueue.front().first;
        int time = bfsQueue.front().second;
        bfsQueue.pop();

        if (node == k) {
            int i = node;

            while (i != n) {
                pathTrace.emplace_back(i);
                i = gGraph[i];
            }
            pathTrace.emplace_back(n);
            return time;
        }

        std::vector<int> factors = {
            node - 1, node + 1, node * 2
        };

        for (const auto& factor : factors) {
            if (factor >= 0 && factor <= kMAX
                && !gVisited[factor]) {
                bfsQueue.push(std::make_pair(factor, time + 1));
                gVisited[factor] = true;
                gGraph[factor] = node;
            }
        }
    }
}

int main() {
    int n, k;
    std::cin >> n >> k;

    std::vector<int> pathTrace;

    int shortestTime = BFS(pathTrace, n, k);
    std::cout << shortestTime << '\n';

    for (auto iter = pathTrace.rbegin();
        iter != pathTrace.rend(); 
        ++iter) {
        std::cout << *iter << ' ';
    }
    return 0;
}