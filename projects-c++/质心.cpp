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
        points = new Point[num];//���鶯̬���ٿռ�
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
        Point *centroid = new Point(sumx, sumy);//newֻ�ܴ�������ָ��
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
1.ͬһ��Ķ���֮��ĸ�ֵ���㣨=�������ÿ������캯����
2.��ʹ�ö�����Ϊ��������ֵʱ�������һ����ʱ���󣬴�ʱ����ÿ������캯����
������g++��������code::blocks���ñ��������У� ���������صĶ������һ��������и�ֵʱ��
�����������ֵ��һ���ֲ��������򲻻���ÿ������캯��. ���ԣ�������ڴ˳�����ʵ�ֿ������캯���ĵ��ã�
������getCentroid�з���һ��ʹ��new����������Ķ��󣬶�����һ���Ѿ�����ľֲ�����
*/
