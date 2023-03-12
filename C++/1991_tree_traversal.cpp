#include <iostream>
#include <unordered_map>
#include <array>

static std::unordered_map<char,
    std::array<char, 2>> gBinSearchTree;

void PreOrder(const char& root) {
    if (root != '.') {
        std::cout << root;
        PreOrder(gBinSearchTree[root][0]);
        PreOrder(gBinSearchTree[root][1]);
    }
}

void InOrder(const char& root) {
    if (root != '.') {
        InOrder(gBinSearchTree[root][0]);
        std::cout << root;
        InOrder(gBinSearchTree[root][1]);
    }
}

void PostOrder(const char& root) {
    if (root != '.') {
        PostOrder(gBinSearchTree[root][0]);
        PostOrder(gBinSearchTree[root][1]);
        std::cout << root;
    }
}

int main() {
    short n = 0;
    std::cin >> n;

    while (n--) {
        char root, left, right;
        std::cin >> root >> left >> right;

        std::array<char, 2> child = {left, right};
        gBinSearchTree.insert(std::make_pair(root, child));
    }

    PreOrder('A');
    std::cout << '\n';

    InOrder('A');
    std::cout << '\n';

    PostOrder('A');
    return 0;
}