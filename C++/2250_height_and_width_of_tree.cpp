#include <iostream>
#include <algorithm>
#include <vector>

const short kMAX = 10001;

std::vector<std::pair<short, short>> gBinSearchTree(kMAX);
std::vector<std::vector<short>> gTreeWidth;
std::vector<short> gVisitied(kMAX);

void InOrder(short& width,
    const short& nowNode, const short& nodeLevel) {
    if (nowNode < 0) return;
    
    InOrder(
        width, gBinSearchTree[nowNode].first, nodeLevel + 1
    );

    if (gTreeWidth.size() <= nodeLevel) {
        gTreeWidth.resize(nodeLevel + 1);
    }

    gTreeWidth[nodeLevel].emplace_back(width++);

    InOrder(
        width, gBinSearchTree[nowNode].second, nodeLevel + 1
    );
}

void GetMaxWidth(short& maxWidth, short& maxLevel) {
    short width = 0;

    for (short i = 1; i < gTreeWidth.size(); ++i) {
        std::sort(
            gTreeWidth[i].begin(), gTreeWidth[i].end()
        );

        width = *(gTreeWidth[i].end() - 1) 
            - *gTreeWidth[i].begin() + 1;

        if (width > maxWidth) {
            maxWidth = width;
            maxLevel = i;
        }
    }
}

int main() {
    short n = 0;
    std::cin >> n;

    for (short i = 0; i < n; ++i) {
        short root, left, right;
        std::cin >> root >> left >> right;
       
        gBinSearchTree[root] = std::make_pair(left, right);

        if (!(left < 0)) gVisitied[left]++;
        if (!(right < 0)) gVisitied[right]++;
    }

    short rootNode = 0;

    for (short i = 1; i <= n; ++i) {
        if (!gVisitied[i]) {
            rootNode = i;
            break;
        }
    }

    short width = 1;
    InOrder(width, rootNode, 1);

    short maxWidth = 0, maxLevel = 0;
    GetMaxWidth(maxWidth, maxLevel);

    std::cout << maxLevel << ' ' << maxWidth;
    return 0;
}