#include <iostream>
#include <string>
using namespace std;

int main()
{
    const int maxPeople = 5;
    string names[maxPeople];
    int ages[maxPeople];

    cout << maxPeople << "명의 회원정보를 입력해주세요." << endl;

    for (int i = 0; i < maxPeople; i++) {
        cout << "사람 " << i + 1 << "의 이름: ";
        cin >> names[i];
        cout << "사람 " << i + 1 << "의 나이: ";
        cin >> ages[i]; 
    }

    int choice;

    while (true) {
        cout << "\n메뉴:\n";
        cout << "1. 가장 나이가 많은 사람 출력\n";
        cout << "2. 가장 나이가 적은 사람 출력\n";
        cout << "3. 종료\n";
        cout << "선택하세요: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int maxAge = ages[0];
                string oldestPerson = names[0];

                for (int j = 1; j < maxPeople; j++) {
                    if (ages[j] > maxAge) {
                        maxAge = ages[j];
                        oldestPerson = names[j];
                    }
                }
                cout << "가장 나이가 많은 사람: " << oldestPerson << " (" << maxAge << "세)" << endl;
                break;
            }
            case 2: {
                int minAge = ages[0];
                string youngestPerson = names[0];

                for (int j = 1; j < maxPeople; j++) {
                    if (ages[j] < minAge) {
                        minAge = ages[j];
                        youngestPerson = names[j];
                    }
                }
                cout << "가장 나이가 적은 사람: " << youngestPerson << " (" << minAge << "세)" << endl;
                break;
            }
            case 3:
                cout << "프로그램을 종료합니다." << endl;
                return 0; // 프로그램 종료
            default:
                cout << "잘못된 선택입니다. 다시 시도하세요." << endl;
                break;
        }
    }

    return 0;
}
