#include <iostream>
using namespace std;

class Fectangle {
public:
    int width, height;
    int CalcArea() {
        return width * height;
    }
};

int main()
{
    Fectangle obj;
    
    obj.width = 10;
    obj.height = 10;
    int area = obj.CalcArea();
    cout << "사각형의 넓이: " << area << endl;
    return 0;
    }