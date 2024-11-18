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

  
    friend std::ostream& operator<<(std::ostream& os, const User& user);
};

#endif 
