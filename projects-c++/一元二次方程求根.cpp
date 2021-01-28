#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
class Equation{
private:
    double a, b, c, num1, num2;
public:
    Equation(double aa, double bb, double cc):a(aa),b(bb),c(cc){}
    ~Equation(){}
    void solve(){
        double temp = b * b - 4.0 * a * c;//double所有常数加小数点
        num1 = 1.0 * (-b + sqrt(temp)) / (2.0 * a);
        num2 = 1.0 * (-b - sqrt(temp)) / (2.0 * a);
    }
    void printRoot(){
        if(num2 > num1){
            int temp = num1;
            num1 = num2;
            num2 = temp;
        }
        cout<<fixed<<setprecision(2)<<num1<<" "<<fixed<<setprecision(2)<<num2<<endl;
    }
};
int main()
{
    double a, b, c;
    while (cin>>a>>b>>c)
    {
        Equation equ(a,b,c);
        equ.solve();
        equ.printRoot();
    }
    return 0;
}
