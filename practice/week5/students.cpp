#include <iostream>
using namespace std;

int main()
{
    const int STRUDENTS = 5;
    int scores[STRUDENTS];
    int sum = 0;
    int i, average;

    for (i = 0; i < STRUDENTS; i++)
    {   cout << "학생들의 성적을 입력하시오:";
        cin >> scores[1]; }
    for ( i = 0; i < STRUDENTS; i++)
        sum += scores[1];

    average = sum / STRUDENTS;
    cout << "성적 평균= " << average << endl;
    return 0;
}