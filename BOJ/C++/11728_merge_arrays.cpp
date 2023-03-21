#include <cstdio>
#include <vector>

int main()
{
    int N = 0, M = 0, Num = 0;
    scanf_s("%d %d", &N, &M);

    std::vector<int> A(N), B(M);

    for (auto& Num : A)
    {
        scanf_s("%d", &Num);
    }

    for (auto& Num : B)
    {
        scanf_s("%d", &Num);
    }

    auto IterA = A.begin();
    auto IterB = B.begin();

    while (IterA != A.end() && IterB != B.end())
    {
        if (*IterA < *IterB)
        {
            printf("%d ", *(IterA++));
        }
        else
        {
            printf("%d ", *(IterB++));
        }
    }

    if (IterB == B.end())
    {
        for (; IterA != A.end(); ++IterA)
        {
            printf("%d ", *IterA);
        }
    }
    if (IterA == A.end())
    {
        for (; IterB != B.end(); ++IterB)
        {
            printf("%d ", *IterB);
        }
    }
    return 0;
}