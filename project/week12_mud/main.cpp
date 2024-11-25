#include <iostream>
#include <string>
#include <algorithm> // for std::remove_if
using namespace std;

const int mapX = 5;
const int mapY = 5;

class User {
private:
    int hp;

public:
    User() : hp(100) {}

    int GetHP() const { return hp; }

    void DecreaseHP(int amount) { hp -= amount; }

    void IncreaseHP(int amount) { hp += amount; }

    void EatItem() {
        IncreaseHP(5); // 아이템을 먹으면 HP 회복
    }

    friend std::ostream& operator<<(std::ostream& os, const User& user) {
        os << "플레이어 HP: " << user.hp;
        return os;
    }
};

bool checkXY(int user_x, int user_y) {
    return (user_x >= 0 && user_x < mapX && user_y >= 0 && user_y < mapY);
}

void displayMap(int map[][mapX], int user_x, int user_y) {
    for (int i = 0; i < mapY; i++) {
        for (int j = 0; j < mapX; j++) {
            if (i == user_y && j == user_x) {
                cout << " USER |";
            } else {
                switch (map[i][j]) {
                    case 0: cout << "      |"; break;
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

bool checkGoal(int map[][mapX], int user_x, int user_y) {
    return (map[user_y][user_x] == 4);
}

bool CheckUser(const User& user) {
    return user.GetHP() > 0;
}

int main() {
    int map[mapY][mapX] = {
        {0, 1, 2, 0, 4},
        {1, 0, 0, 2, 0},
        {0, 0, 0, 0, 0},
        {0, 2, 3, 0, 0},
        {3, 0, 0, 0, 2}
    };

    User player;

    int user_x = 0; // 가로
    int user_y = 0; // 세로

    while (true) {
        string user_input;

        // 명령어 입력 받기
        cout << "명령어를 입력하세요 (상, 하, 좌, 우, 지도, 정보, 종료): ";
        getline(cin, user_input); // 한 줄 전체 입력 받기

        // 입력값의 앞뒤 공백을 제거
        user_input.erase(user_input.find_last_not_of(" \n\r\t") + 1);
        user_input.erase(0, user_input.find_first_not_of(" \n\r\t"));

        // 입력값이 비어있지 않은지 체크
        if (user_input.empty()) {
            cout << "잘못된 입력입니다. 다시 입력해 주세요." << endl;
            continue;
        }

        // 입력값에 대한 유효성 검사
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
            cout << player << endl;
            continue;
        } else if (user_input == "종료") {
            cout << "종료합니다." << endl;
            break;
        } else {
            cout << "잘못된 입력입니다. 다시 입력해 주세요." << endl;
            continue;
        }

        if (!checkXY(user_x, user_y)) {
            cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
            if (user_input == "상") user_y += 1;
            else if (user_input == "하") user_y -= 1;
            else if (user_input == "좌") user_x += 1;
            else if (user_input == "우") user_x -= 1;
        } else {
            cout << "이동했습니다: " << user_input << endl;
            displayMap(map, user_x, user_y);

            if (map[user_y][user_x] == 2) {
                cout << "적과 조우했습니다! 체력이 5 감소합니다." << endl;
                player.DecreaseHP(5);
            } else if (map[user_y][user_x] == 3) {
                cout << "포션을 발견했습니다! 체력이 2 증가합니다." << endl;
                player.IncreaseHP(2);
            } else if (map[user_y][user_x] == 1) {
                cout << "아이템을 발견했습니다!" << endl;
                player.EatItem();
                map[user_y][user_x] = 0; // 아이템을 먹은 후, 해당 위치를 비워둔다.
            }
        }

        if (!CheckUser(player)) {
            cout << "체력이 0이 되었습니다. 게임 종료!" << endl;
            break;
        }

        if (checkGoal(map, user_x, user_y)) {
            cout << "목적지에 도착했습니다! 축하합니다!" << endl;
            cout << "게임을 종료합니다." << endl;
            break;
        }
    }

    return 0;
}
