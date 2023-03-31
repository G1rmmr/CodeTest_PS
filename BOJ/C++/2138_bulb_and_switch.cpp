#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>

const int kMAX = 1e8;

void TurnOn(const short& i, const int& N,
    std::vector<short>& Lights)
{
    if (i > 0)
    {
        Lights[i - 1] = Lights[i - 1] ? 0 : 1;
    }

    Lights[i] = Lights[i] ? 0 : 1;

    if (i < N - 1)
    {
        Lights[i + 1] = Lights[i + 1] ? 0 : 1;
    }
}

int GetTransform(const int& N,
    std::vector<short>& BeforeLights,
    const std::vector<short>& AfterLights)
{
    std::vector<short> Lights = BeforeLights;
    int Count = 0, NumSwitch = kMAX;

    Lights[0] = Lights[0] ? 0 : 1;
    Lights[1] = Lights[1] ? 0 : 1;

    Count++;

    for (short i = 1; i < N; ++i)
    {
        if (Lights[i - 1] != AfterLights[i - 1])
        {
            TurnOn(i, N, Lights);
            Count++;
        }
    }

    if (Lights == AfterLights)
    {
        NumSwitch = std::min(NumSwitch, Count);
    }

    Count = 0;

    for (short i = 1; i < N; ++i)
    {
        if (BeforeLights[i - 1] != AfterLights[i - 1])
        {
            TurnOn(i, N, BeforeLights);
            Count++;
        }
    }

    if (BeforeLights == AfterLights)
    {
        NumSwitch = std::min(NumSwitch, Count);
    }
    return (NumSwitch == kMAX ? -1 : NumSwitch);
}

int main()
{
    int N = 0;
    scanf("%d", &N);

    std::vector<short> BeforeLights(N), AfterLights(N);

    for (auto& Light : BeforeLights)
    {
        scanf("%1hd", &Light);
    }

    for (auto& Light : AfterLights)
    { 
        scanf("%1hd", &Light);
    }

    int NumSwitch = GetTransform(N, BeforeLights, AfterLights);

    printf("%d", NumSwitch);
    return 0;
}