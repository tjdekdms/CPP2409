#include <iostream>
using namespace std;

class User {
private:
    int hp; // 체력

public:
    // 기본 생성자
    User() : hp(20) { // 기본 체력을 20으로 설정
    }

    // 체력 감소 메서드
    void DecreaseHP(int dec_hp) {
        if (dec_hp > 0) {
            hp -= dec_hp;
            if (hp < 0) hp = 0; // 체력이 0 미만이 되지 않도록 조정
            cout << "체력이 " << dec_hp << " 감소했습니다. 현재 체력: " << hp << endl;
        } else {
            cout << "감소할 체력은 양수여야 합니다!" << endl;
        }
    }

    // 체력 증가 메서드
    void IncreaseHP(int inc_hp) {
        if (inc_hp > 0) {
            hp += inc_hp;
            cout << "체력이 " << inc_hp << " 증가했습니다. 현재 체력: " << hp << endl;
        } else {
            cout << "증가할 체력은 양수여야 합니다!" << endl;
        }
    }

    // 현재 체력 반환 메서드
    int GetHP() {
        return hp;
    }
};

int main() {
    User player; // User 객체 생성

    // 초기 체력 출력
    cout << "초기 체력: " << player.GetHP() << endl;

    // 체력 감소
    player.DecreaseHP(5);
    player.DecreaseHP(10);

    // 체력 증가
    player.IncreaseHP(15);

    // 최종 체력 출력
    cout << "최종 체력: " << player.GetHP() << endl;

    return 0;
}
