#include <iostream>
using namespace std;

class Dog {
private:
    int pWeight;
    int pAge ;

public:
    Dog() {
        pAge = 1;
        pWeight = 10;
    }
    ~Dog() {
    }
    int GetAge() { return pAge; }
    void SetAge(int age) { pAge = age; }
    int GetWeight() { return pWeight; }
    void SetWeight(int weight) { pWeight = weight; }
};
int main()
{
    Dog pDog = Dog();
    cout << "강아지의 나이: " << pDog.GetAge() << endl;
    
    pDog.SetAge(5);
    cout << "강아지의 나이: " << pDog.GetAge() << endl;

    return 0;
}