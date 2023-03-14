#include <iostream>
#include <array>

static std::array<int, 21> gS;
static std::array<bool, 2000001> gVisited;

void CalcSum(
    const int& TargetNum,
    const int& Sum,
    const short& N)
{
    gVisited[Sum] = true;

    if(TargetNum == N)
    {
        return;
    }
    else
    {
        CalcSum(TargetNum + 1, Sum, N);
        CalcSum(
            TargetNum + 1, Sum + gS[TargetNum], N
            );
    }
}

int main()
{
	short N;
	std::cin >> N;

    for(int i = 0; i < N; ++i)
    {
        std::cin >> gS[i];
    }

    CalcSum(0, 0, N);

    int index = 1;

    while(gVisited[index]){
        index++;
    }
    std::cout << index;
	return 0;
}