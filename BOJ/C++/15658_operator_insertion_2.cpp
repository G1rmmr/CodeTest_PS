#include <iostream>
#include <array>

static int gMin = 1000000001;
static int gMax = -1000000001;

static std::array<short, 11> gSeq;
static std::array<short, 4> gOpers;

void Operate(
    const short& N,
    const int& TempResult,
    const int& RecusionLevel)
{
    if(RecusionLevel == N)
    {
        if(TempResult > gMax) {
            gMax = TempResult;
        }

        if(TempResult < gMin){
            gMin = TempResult;
        }
        return;
    }
    
    for(int i = 0; i < 4; i++)
    {
        if(gOpers[i])
        {
            gOpers[i]--;

            switch(i)
            {
            case 0:
                Operate(N,
                    TempResult + gSeq[RecusionLevel],
                    RecusionLevel + 1
                );
                break;
            
            case 1:
                Operate(N,
                    TempResult - gSeq[RecusionLevel],
                    RecusionLevel + 1
                );
                break;

            case 2:
                Operate(N,
                    TempResult * gSeq[RecusionLevel],
                    RecusionLevel + 1
                );
                break;

            default:
                Operate(N,
                    TempResult / gSeq[RecusionLevel],
                    RecusionLevel + 1
                );
                break;
            }
            gOpers[i]++;
        }
    }
}

int main()
{
    short N;
    std::cin >> N;

    for(int i = 0; i < N; ++i)
    {
        std::cin >> gSeq[i];
    }

    for(auto& Oper : gOpers)
    {
        std::cin >> Oper;
    }

    Operate(N, *gSeq.begin(), 1);

    std::cout << gMax << '\n' << gMin;
	return 0;
}