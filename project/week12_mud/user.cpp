#include "user.h"
#include <iostream>

using namespace std;


User::User() : hp(20), itemCnt(0) {

}

void User::DecreaseHP(int dec_hp) {
    if (dec_hp > 0) {
        hp -= dec_hp;
        if (hp < 0) hp = 0; 
        cout << "체력이 " << dec_hp << " 감소했습니다. 현재 체력: " << hp << endl;
    } else {
        cout << "감소할 체력은 양수여야 합니다!" << endl;
    }
}


void User::IncreaseHP(int inc_hp) {
    if (inc_hp > 0) {
        hp += inc_hp;
        cout << "체력이 " << inc_hp << " 증가했습니다. 현재 체력: " << hp << endl;
    } else {
        cout << "증가할 체력은 양수여야 합니다!" << endl;
    }
}


void User::EatItem() {
    itemCnt++;  
    cout << "아이템을 먹었습니다. 현재 아이템 먹은 횟수: " << itemCnt << endl;
}

int User::GetHP() const {
    return hp;
}


ostream& operator<<(ostream& os, const User& user) {
    os << "현재 HP는 " << user.GetHP() << " 이고, 먹은 아이템은 총 " << user.itemCnt << "개 입니다";
    return os;
}
