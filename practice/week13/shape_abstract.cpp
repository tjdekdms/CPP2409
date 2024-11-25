#include <iostream>
using namespace std;
class Shape{
protected:
    int x,y;

public:
    Shape(int x,int y):x(x),y(y){ }
    virtual void draw()=0;
};
class Rect:public Shape{
private:
    int width,height;
public:
    Rect(int x,int y,int w,int h):Shape(x,y),width(w),height(h){ }
    void draw(){//없으면에러
        cout<<"RectangleDraw"<<endl;
    }
};

int main()
{
    Shape*ps=new Rect(0,0,100,100); //OK!
    ps->draw(); //Rectangle의draw()가호출된다.
    delete ps;

    return 0;
 }