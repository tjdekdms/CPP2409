#include <iostream>
#include <string>
using namespace std;

const int mapX = 5;
const int mapY = 5;

const int EMPTY = 0;
const int ITEM = 1;
const int ENEMY = 2;
const int POTION = 3;
const int GOAL = 4;

// 기본 User 클래스
class User {
protected:
    int health;

public:
    User() : health(100) {} // 기본 체력 100

    virtual void DecreaseHP(int amount) {
        health -= amount;
        if (health < 0) health = 0;
    }

    virtual void IncreaseHP(int amount) {
        health += amount;
        if (health > 100) health = 100;
    }

    virtual void EatItem() {
        cout << "아이템을 먹었습니다!" << endl;
    }

    int GetHealth() const {
        return health;
    }

    friend ostream& operator<<(ostream& os, const User& user) {
        os << "체력: " << user.health;
        return os;
    }
};

// Magician 클래스 (User 상속)
class Magician : public User {
public:
    Magician() : User() {}

    // 마법 사용 (체력 감소)
    void CastSpell() {
        cout << "마법을 사용했습니다! 적의 체력을 10 감소시킵니다." << endl;
    }
};

// Warrior 클래스 (User 상속)
class Warrior : public User {
public:
    Warrior() : User() {}

    // 전사 특수 능력 (체력 회복)
    void BattleCry() {
        cout << "전사의 전투 외침! 체력이 5 증가합니다." << endl;
        IncreaseHP(5);
    }
};

bool checkXY(int user_x, int user_y);
void displayMap(int map[][mapX], int user_x, int user_y);
bool checkGoal(int map[][mapX], int user_x, int user_y);
bool CheckUser(const User& user);

int main() {
    int map[mapY][mapX] = {
        {EMPTY, ITEM, ENEMY, EMPTY, GOAL},
        {ITEM, EMPTY, EMPTY, ENEMY, EMPTY},
        {EMPTY, EMPTY, EMPTY, EMPTY, EMPTY},
        {EMPTY, ENEMY, POTION, EMPTY, EMPTY},
        {POTION, EMPTY, EMPTY, EMPTY, ENEMY}
    };

    Magician magician;
    Warrior warrior;
    User* currentPlayer = &magician;  // 게임이 시작될 때는 마법사부터 시작
    int user_x = 0;
    int user_y = 0;

    while (true) {
        string user_input;
        cout << currentPlayer->GetHealth() << endl; // 현재 플레이어의 체력 출력
        cout << "명령어를 입력하세요 (상, 하, 좌, 우, 지도, 정보, 종료): ";
        cin >> user_input;

        // 입력 값 디버깅 출력
        cout << "입력받은 값: '" << user_input << "'" << endl;  // 디버깅용 출력

        // 이동 처리
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
            cout << *currentPlayer << endl;
            continue;
        } else if (user_input == "종료") {
            cout << "게임을 종료합니다." << endl;
            break;
        } else {
            cout << "잘못된 입력입니다." << endl;
            continue;
        }

        // 경계 체크 (맵을 벗어나지 않도록)
        if (!checkXY(user_x, user_y)) {
            cout << "맵을 벗어났습니다. 다시 돌아갑니다." << endl;
            // 유효하지 않은 좌표일 경우 이전 위치로 되돌리기
            if (user_input == "상") user_y += 1;
            else if (user_input == "하") user_y -= 1;
            else if (user_input == "좌") user_x += 1;
            else if (user_input == "우") user_x -= 1;
        } else {
            cout << "이동했습니다: " << user_input << endl;
            displayMap(map, user_x, user_y);

            if (map[user_y][user_x] == ENEMY) {
                cout << "적과 조우했습니다!" << endl;
                currentPlayer->DecreaseHP(5);
            } else if (map[user_y][user_x] == POTION) {
                cout << "포션을 발견했습니다! 체력이 2 증가합니다." << endl;
                currentPlayer->IncreaseHP(2);
            } else if (map[user_y][user_x] == ITEM) {
                cout << "아이템을 발견했습니다!" << endl;
                currentPlayer->EatItem();
                map[user_y][user_x] = EMPTY;
            }
        }

        // HP 체크
        if (!CheckUser(*currentPlayer)) {
            cout << "체력이 0이 되었습니다. 게임 종료!" << endl;
            break;
        }

        // 목적지에 도달했는지 체크
        if (checkGoal(map, user_x, user_y)) {
            cout << "목적지에 도달했습니다! 축하합니다!" << endl;
            cout << "게임을 종료합니다." << endl;
            break;
        }

        // 턴을 넘깁니다.
        if (currentPlayer == &magician) {
            currentPlayer = &warrior;
        } else {
            currentPlayer = &magician;
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
                    case EMPTY: cout << "      |"; break; // 빈 공간
                    case ITEM: cout << "아이템|"; break;
                    case ENEMY: cout << "  적  |"; break;
                    case POTION: cout << " 포션 |"; break;
                    case GOAL: cout << "목적지|"; break;
                }
            }
        }
        cout << endl;
        cout << " -------------------------------- " << endl;
    }
}

// 사용자 좌표가 유효한지 확인하는 함수
bool checkXY(int user_x, int user_y) {
    return (user_x >= 0 && user_x < mapX && user_y >= 0 && user_y < mapY);
}

// 목표지점에 도달했는지 확인하는 함수
bool checkGoal(int map[][mapX], int user_x, int user_y) {
    return map[user_y][user_x] == GOAL;
}

// 사용자 체력 확인 함수
bool CheckUser(const User& user) {
    return user.GetHealth() > 0;
}
