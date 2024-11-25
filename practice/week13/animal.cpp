#include <iostream>
using namespace std;
class Animal
{
public:
    void Speak() { cout << "Animal speak()" << endl; }
};
class Dog : public Animal
{
public:
    int age;
    void Speak() { cout << "멍멍" << endl; }
};
class Cat : public Animal
{
public:
    void Speak() { cout << "야옹" << endl; }
};

int main()
{
    // new를 통해동적객체를
    // 생성했으므로포인터로받음
    Animal *a1 = new Dog();
    a1->Speak();

    // 오류!! 상향형변환시
    // Dog 복사되서Animal에전달되며정보잘림
    // 객체 슬라이싱(slicing) 이라고함.
    //a1->age = 10;

    Animal a2 = Cat();
    // a2->speak(); // 오류! 포인터가 아니니까
    a2.Speak();

    delete a1;
    return 0;
}
