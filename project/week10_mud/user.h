class User {
private:
    int hp;  // 체력

public:
    // 기본 생성자
    User();

    // 체력 감소 메소드
    void DecreaseHP(int dec_hp);

    // 체력 증가 메소드
    void IncreaseHP(int inc_hp);

    // 현재 체력 반환 메소드
    int GetHP() const;
};