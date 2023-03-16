#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>

static const short kMAX = 1001;

static std::vector<std::vector<short>> gVisited(
    kMAX, std::vector<short>(kMAX)
);

void BFS(const short& s, short& spendTime) {
    for (auto& visitCol : gVisited) {
        std::fill(visitCol.begin(), visitCol.end(), -1);
    }
    gVisited[1][0] = 0;

    std::queue<std::pair<short, short>> bfsQueue;
    bfsQueue.push(std::make_pair(1, 0));

    while (!bfsQueue.empty()) {
        short numDisp = bfsQueue.front().first;
        short numClip = bfsQueue.front().second;

        short calcTime = gVisited[numDisp][numClip];
        bfsQueue.pop();

        if (numDisp == s) {
            spendTime = std::min(spendTime, calcTime);
            continue;
        }

        if (gVisited[numDisp][numDisp] < 0) {
            gVisited[numDisp][numDisp] = calcTime + 1;
            bfsQueue.push(std::make_pair(numDisp, numDisp));
        }

        if (numDisp + numClip <= s
            && gVisited[numDisp + numClip][numClip] < 0) {
            bfsQueue.push(
                std::make_pair(numDisp + numClip, numClip)
            );
            gVisited[numDisp + numClip][numClip] = calcTime + 1;
        }

        if (numDisp - 1 >= 0 && gVisited[numDisp - 1][numClip] < 0) {
            gVisited[numDisp - 1][numClip] = calcTime + 1;
            bfsQueue.push(std::make_pair(numDisp - 1, numClip));
        }
    }
}

int main() {
    short s, spendTime = kMAX * 10;
    std::cin >> s;

    BFS(s, spendTime);

    std::cout << spendTime;
    return 0;
}

