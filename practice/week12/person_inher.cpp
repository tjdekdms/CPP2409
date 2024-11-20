#include <iostream>
using namespace std;

class Person {
private:
    string name; 

protected:
    string address; 

public:
   
    void setName(string newName) {
        name = newName;
    }

   
    string getName() {
        return name;
    }
};

class Student : public Person {
public:
    void setAddress(string add) {
        address = add;
    }

   
    string getAddress() {
        return address;
    }
};

int main() {
    Student obj;
    obj.setName("미수"); 
    obj.setAddress("서울시 종로구 1번지");  

   
    cout << "Name: " << obj.getName() << endl;
    cout << "Address: " << obj.getAddress() << endl;

    return 0;
}
