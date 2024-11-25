#include <iostream>
using namespace std;

class Animal {
public:
    virtual void move() = 0;
    virtual void eat() = 0;
    virtual void speak() = 0;
    void animal_speak() {
        cout << "동물의speak() " << endl;
    }
};
class Lion : public Animal {
public:
    void move() override {
        cout << "사자의move()" << endl;
    }
    void eat() override {
        cout << "사자의eat()" << endl;
    }
    void speak() override {
        cout << "사자의speak()" << endl;
    }
};

int main() {
    Animal* lion = new Lion();
    lion->speak();
    lion->animal_speak();
    delete lion;
    return 0;
}
