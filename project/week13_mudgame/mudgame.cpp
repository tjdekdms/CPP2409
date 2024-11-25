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

// User 인터페이스 (추상 클래스)
class User {
public:
    virtual void DecreaseHP(int amount) = 0;  // 체력 감소
    virtual void IncreaseHP(int amount) = 0;  // 체력 증가
    virtual void EatItem() = 0;               // 아이템을 먹다
    virtual int GetHealth() const = 0;         // 체력 반환
    virtual void DisplayInfo() const = 0;     // 정보 출력

    virtual ~User() {}
};

// Magician 클래스 (User 인터페이스 구현)
class Magician : public User {
protected:
    int health;
public:
    Magician() : health(100) {} // 기본 체력 100

    void DecreaseHP(int amount) override {
        health -= amount;
        if (health < 0) health = 0;
    }

    void IncreaseHP(int amount) override {
        health += amount;
        if (health > 100) health = 100;
    }

    void EatItem() override {
        cout << "아이템을 먹었습니다!" << endl;
    }

    int GetHealth() const override {
        return health;
    }

    void DisplayInfo() const override {
        cout << "마법사 - 체력: " << health << endl;
    }

    void CastSpell() {
        cout << "마법을 사용했습니다! 적의 체력을 10 감소시킵니다." << endl;
    }
};

// Warrior 클래스 (User 인터페이스 구현)
class Warrior : public User {
protected:
    int health;
public:
    Warrior() : health(100) {} // 기본 체력 100

    void DecreaseHP(int amount) override {
        health -= amount;
        if (health < 0) health = 0;
    }

    void IncreaseHP(int amount) override {
        health += amount;
        if (health > 100) health = 100;
    }

    void EatItem() override {
        cout << "아이템을 먹었습니다!" << endl;
    }

    int GetHealth() const override {
        return health;
    }

    void DisplayInfo() const override {
        cout << "전사 - 체력: " << health << endl;
    }

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

    // 게임 시작 시 직업 선택
    cout << "직업을 선택하세요 (1. 마법사, 2. 전사): ";
    int choice;
    cin >> choice;

    User* currentPlayer = nullptr;
    if (choice == 1) {
        currentPlayer = new Magician();
    } else if (choice == 2) {
        currentPlayer = new Warrior();
    } else {
        cout << "잘못된 입력입니다. 기본 마법사로 시작합니다." << endl;
        currentPlayer = new Magician();
    }

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
            currentPlayer->DisplayInfo();
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
    }

    delete currentPlayer;  // 동적으로 할당된 메모리 해제
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
