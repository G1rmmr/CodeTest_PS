#include <iostream>

inline GetArea(const short& A, const short& B)
{
    return A * B;
}

int main()
{
    short A = 0, B = 0;
    std::cin >> A >> B;

    std::cout << GetArea(A, B);
    return 0;
}