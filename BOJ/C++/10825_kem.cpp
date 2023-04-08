#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>

struct GradeInfo
{
    std::string StudentName;
    int KoreanScore;
    int EnglishScore;
    int MathScore;
};

void GradeSort(std::vector<GradeInfo>& Grades)
{
    std::sort(Grades.begin(), Grades.end(),
        [](const GradeInfo& _left, const GradeInfo& _right)
    {
        if (_left.KoreanScore != _right.KoreanScore)
        {
            return _left.KoreanScore > _right.KoreanScore;
        }
        else if (_left.EnglishScore != _right.EnglishScore)
        {
            return _left.EnglishScore < _right.EnglishScore;
        }
        else if(_left.MathScore != _right.MathScore)
        {
            return _left.MathScore > _right.MathScore;
        }
        else
        {
            return _left.StudentName < _right.StudentName;
        }
    });
}

int main()
{
    int N = 0;
    std::cin >> N;

    std::vector<GradeInfo> Grades(N);

    for (auto& Grade : Grades)
    {
        std::cin.ignore();

        std::cin
            >> Grade.StudentName
            >> Grade.KoreanScore
            >> Grade.EnglishScore
            >> Grade.MathScore;
    }

    GradeSort(Grades);
    
    for (const auto& Grade : Grades)
    {
        std::cout << Grade.StudentName << '\n';
    }
    return 0;
}