#include<iostream>
#include<iomanip>
using namespace std;
class Point{
private:
    double x, y;
public:
    Point(double xx = 0.0, double yy = 0.0):x(xx),y(yy){
        cout<<"The Point ("<<fixed<<setprecision(2)<<x;
        cout<<", "<<fixed<<setprecision(2)<<y<<") is created!"<<endl;
    }
    Point(const Point &p):x(p.x), y(p.y){
        cout<<"A Point ("<<fixed<<setprecision(2)<<x;
        cout<<", "<<fixed<<setprecision(2)<<y<<") is copied!"<<endl;
    }
    ~Point(){
        cout<<"A Point ("<<fixed<<setprecision(2)<<x;
        cout<<", "<<fixed<<setprecision(2)<<y<<") is erased!"<<endl;
    }
    double getX(){return x;}
    double getY(){return y;}
};
class Graph{
private:
    Point *points;
    int numOfPoints;
public:
    Graph(Point *p, int num){
        points = new Point[num];//数组动态开辟空间
        for(int i = 0; i < num; ++i){
            points[i] = p[i];
        }
        numOfPoints = num;
        cout<<"A graph with "<<numOfPoints<<" points is created!"<<endl;
    }
    ~Graph(){
        delete []points;
        cout<<"A graph with "<<numOfPoints<<" points is erased!"<<endl;
    }
    Point getCentroid(){
        double sumx = 0, sumy = 0;
        for(int i = 0; i < numOfPoints; ++i){
            sumx += points[i].getX();
            sumy += points[i].getY();
        }
        sumx /= numOfPoints;
        sumy /= numOfPoints;
        Point *centroid = new Point(sumx, sumy);//new只能创建对象指针
        return *centroid;
    }
};
int main()
{
    int cases,num;
    double x, y;
    Point centroid;
    cin>>cases;
    for (int i = 0; i < cases; i++)
    {
        cin>>num;
        Point points[num];
        for (int j = 0; j < num; j++)
        {
            cin>>x>>y;
            points[j] = *(new Point(x, y));
        }
        Graph graph(points, num);
        centroid = graph.getCentroid();
        cout<<setprecision(2)<<fixed<<"The centroid is ("<<centroid.getX()<<", "<<centroid.getY()<<")."<<endl;
    }
    return 0;
}
/*
1.同一类的对象之间的赋值运算（=）不调用拷贝构造函数。
2.当使用对象作为函数返回值时，会产生一个临时对象，此时会调用拷贝构造函数。
但是在g++编译器（code::blocks所用编译器）中， 当函数返回的对象给另一个对象进行赋值时，
如果函数返回值是一个局部变量，则不会调用拷贝构造函数. 所以，如果想在此程序中实现拷贝构造函数的调用，
必须在getCentroid中返回一个使用new运算符创建的对象，而不是一个已经定义的局部对象。
*/
