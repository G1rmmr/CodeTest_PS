#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <array>
#include <queue>

const short kMAX = 10000, kMIN = 999;

std::array<bool, kMAX> Eratos;
std::array<short, kMAX> Distance;

void GetPrime()
{
    std::fill(Eratos.begin(), Eratos.end(), true);

    Eratos[0] = false, Eratos[1] = false;

    for (short i = 2;
        i <= static_cast<short>(std::sqrt(kMAX));
        ++i)
    {
        if (Eratos[i])
        {
            for (short j = i * i; j < kMAX; j += i)
            {
                Eratos[j] = false;
            }
        }
    }
}

short BFS(const short& Num1, const short& Num2)
{
    std::fill(Distance.begin(), Distance.end(), -1);
    Distance[Num1] = 0;

    std::queue<short> BFSQueue;
    BFSQueue.push(Num1);

    while (!BFSQueue.empty())
    {
        short Now = BFSQueue.front();
        BFSQueue.pop();

        if (Now == Num2)
        {
            return Distance[Num2];
        }

        short Temp = Now;
        std::vector<short> Digits;
        
        for (short i = 0; i < 4; ++i)
        {
            Digits.emplace_back(Temp % 10);
            Temp /= 10;
        }
        
        std::reverse(Digits.begin(), Digits.end());

        for (short i = 0; i < 4; ++i)
        {
            for (short j = 0; j <= 9; ++j)
            {
                if (j == Digits[i])
                {
                    continue;
                }

                short NextNum = 0;

                for (short k = 0; k < 4; ++k)
                {
                    NextNum += std::pow(10, 3 - k)
                        * (i == k ? j : Digits[k]);
                }

                if ((NextNum < kMAX && NextNum > kMIN
                    && Distance[NextNum] < 0)
                    && Eratos[NextNum])
                {
                    Distance[NextNum] = Distance[Now] + 1;
                    BFSQueue.push(NextNum);
                }
            }
        }
    }
    return -1;
}


int main()
{
    int T = 0;
    scanf_s("%d", &T);

    GetPrime();
    while (T--)
    {
        short Num1 = 0, Num2 = 0;
        scanf_s("%hd %hd", &Num1, &Num2);

        short Count = BFS(Num1, Num2);
        Count < 0 ? printf("Impossible\n") : printf("%hd\n", Count);
    }
    return 0;
}