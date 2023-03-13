#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <set>

static char gMaxDigits[256];

int CalcSum(
    const std::vector<std::string>& words,
    const std::set<char>& digits,
    const std::vector<short>& numDigits) {
    int sum = 0, i = 0;
    
    for (const auto& digit : digits) {
        gMaxDigits[digit] = numDigits[i++];
    }

    for (const auto& word : words) {
        int tempSum = 0;

        for (const char& num : word) {
            tempSum *= 10;
            tempSum += gMaxDigits[num];
        }
        sum += tempSum;
    }
    return sum;
}

int GetMaxSum(
    const std::vector<std::string>& words,
    const std::set<char>& digits) {
    std::vector<short> numDigits;

    for (short i = 0; i < digits.size(); ++i) {
        numDigits.emplace_back(9 - i);
    }

    std::sort(numDigits.begin(), numDigits.end());
    int maxSum = 0;
    
    do {
        maxSum = std::max(maxSum, CalcSum(
            words, digits, numDigits));

    } while (std::next_permutation(
        numDigits.begin(), numDigits.end()));

    return maxSum;
}

int main() {
    short n = 0;
    std::cin >> n;

    std::vector<std::string> words(n);
    std::set<char> digits;

    for (auto& word : words) {
        std::cin >> word;

        for (const char& digit : word) {
            digits.insert(digit);
        }
    }

    std::cout << GetMaxSum(words, digits);
    return 0;
}