#include <iostream>
#include <string>

using namespace std;

class Date {
    int year, month, day;
public:
    Date(int y, int m, int d) { year = y; month = m; day = d; }
    void Print() {
        cout << year << ".";
        if (month < 10) cout << "0";  // 월이 10 미만일 때 앞에 0을 추가
        cout << month << ".";
        if (day < 10) cout << "0";    // 일이 10 미만일 때 앞에 0을 추가
        cout << day << endl;
    }
};

class Person {
    string name;
    Date birth;
public:
    Person(string n, Date d) {name = n; birth = d;}
    
    void Print() {
        cout << name << ";";
        birth.Print();
        cout << endl;
    }
};

int main() {
    Date d{ 1998, 3, 1 };
    Person p{ "김철수", d };
    p.Print();
    return 0;
}
