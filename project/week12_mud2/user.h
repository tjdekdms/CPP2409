#ifndef USER_H
#define USER_H

#include <iostream>

class User {
private:
    int hp;         
    int itemCnt;   

public:
    
    User();

    void DecreaseHP(int dec_hp);

    
    void IncreaseHP(int inc_hp);

    
    void EatItem();

    
    int GetHP() const;

    
    virtual void doAttack();

   
    friend std::ostream& operator<<(std::ostream& os, const User& user);
};


class Magician : public User {
public:
    Magician();  

    void doAttack() override;
};


class Warrior : public User {
public:
    Warrior();  

    
    void doAttack() override;
};

#endif 
