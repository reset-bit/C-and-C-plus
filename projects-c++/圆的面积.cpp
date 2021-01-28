//函数名后加const：
//这是把整个函数修饰为const，意思是“函数体内不能对成员数据做任何改动”
//如果声明这个类的一个const实例，那么它只能调用有const修饰的函数
#include<iostream>
using namespace std;
class Circle{
private:
    double radius;
public:
    static const double PI;
    Circle(double r):radius(r){}
    double getArea()const{//区分返回const类型的函数：const double getArea()
        return PI * radius * radius;
    }
    double getRadius()const{
        return radius;
    }
};
const double Circle::PI = 3.1415926;
int main()
{
    double radius;
    cout<<"PI="<<Circle::PI<<endl;
    cin>>radius;
    Circle c1(radius);
    cout<<"radius="<<c1.getRadius();
    cout<<",area="<<c1.getArea()<<endl;
    return 0;
}
