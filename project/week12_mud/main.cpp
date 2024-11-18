#include "user.h"
#include <iostream>
#include <string>
using namespace std;

const int mapX = 5;
const int mapY = 5;


bool checkXY(int user_x, int user_y);


void displayMap(int map[][mapX], int user_x, int user_y);


bool checkGoal(int map[][mapX], int user_x, int user_y);


bool CheckUser(const User& user);

int main() {
    // 0은 빈 공간, 1은 아이템, 2는 적, 3은 포션, 4는 목적지
    int map[mapY][mapX] = {
        {0, 1, 2, 0, 4},
        {1, 0, 0, 2, 0},
        {0, 0, 0, 0, 0},
        {0, 2, 3, 0, 0},
        {3, 0, 0, 0, 2}
    };

    // User 객체 생성
    User player;

    // 유저의 위치를 저장할 변수
    int user_x = 0; // 가로 번호
    int user_y = 0; // 세로 번호

    // 게임 시작 
    while (true) { // 사용자에게 계속 입력받기 위해 무한 루프
        // 사용자의 입력을 저장할 변수
        string user_input;

        cout << "명령어를 입력하세요 (상,하,좌,우,지도,정보,종료): ";
        cin >> user_input;

        if (user_input == "상") {
            user_y -= 1;
        } else if (user_input == "하") {
            user_y += 1;
        } else if (user_input == "좌") {
            user_x -= 1;
        } else if (user_input == "우") {
            user_x += 1;
        } else if (user_input == "지도") {
            displayMap(map, user_x, user_y);
            continue;
        } else if (user_input == "정보") {
            // 사용자 정보 출력
            cout << player << endl;
            continue;
        } else if (user_input == "종료") {
            cout << "종료합니다." << endl;
            break;
        } else {
            cout << "잘못된 입력입니다." << endl;
            continue;
        }

        // 경계 체크
        if (!checkXY(user_x, user_y)) {
            cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
            // 유효하지 않은 좌표일 경우 이전 위치로 되돌리기
            if (user_input == "상") user_y += 1;
            else if (user_input == "하") user_y -= 1;
            else if (user_input == "좌") user_x += 1;
            else if (user_input == "우") user_x -= 1;
        } else {
            cout << "이동했습니다: " << user_input << endl; // 이동 메시지 추가
            displayMap(map, user_x, user_y);

            // 현재 위치에 적이 있는지 체크
            if (map[user_y][user_x] == 2) { // 적이 있는 경우
                cout << "적과 조우했습니다! 체력이 5 감소합니다." << endl;
                player.DecreaseHP(5);
            }
            // 현재 위치에 포션이 있는지 체크
            else if (map[user_y][user_x] == 3) { // 포션이 있는 경우
                cout << "포션을 발견했습니다! 체력이 2 증가합니다." << endl;
                player.IncreaseHP(2);
            }
            // 아이템 획득
            else if (map[user_y][user_x] == 1) { // 아이템이 있는 경우
                cout << "아이템을 발견했습니다!" << endl;
                player.EatItem();
                map[user_y][user_x] = 0; // 아이템을 먹은 후, 해당 위치를 비워둔다.
            }
        }

        // HP 체크
        if (!CheckUser(player)) {
            cout << "체력이 0이 되었습니다. 게임 종료!" << endl;
            break;
        }

        // 목적지에 도달했는지 체크
        if (checkGoal(map, user_x, user_y)) {
            cout << "목적지에 도착했습니다! 축하합니다!" << endl;
            cout << "게임을 종료합니다." << endl;
            break;
        }
    }

    return 0;
}

// 지도와 사용자 위치 출력하는 함수
void displayMap(int map[][mapX], int user_x, int user_y) {
    for (int i = 0; i < mapY; i++) {
        for (int j = 0; j < mapX; j++) {
            if (i == user_y && j == user_x) {
                cout << " USER |"; // 사용자 위치
            } else {
                switch (map[i][j]) {
                    case 0: cout << "      |"; break; // 빈 공간
                    case 1: cout << "아이템|"; break;
                    case 2: cout << "  적  |"; break;
                    case 3: cout << " 포션 |"; break;
                    case 4: cout << "목적지|"; break;
                }
            }
        }
        cout << endl;
        cout << " -------------------------------- " << endl;
    }
}

bool checkXY(int user_x, int user_y) {
    return (user_x >= 0 && user_x < mapX && user_y >= 0 && user_y < mapY);
}