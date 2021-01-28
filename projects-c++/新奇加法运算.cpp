/*
新奇加法运算
定义类newInt，重载运算符“+”
计算规则为：将A、B对应位置上的数字相加，只保留个位数作为结果的对应位置上的数字。
比如：876 + 543 = 319。注意：该运算不改变两个操作数的值。
*/
#include<iostream>
using namespace std;
class newInt{
private:
    int n;
public:
    newInt():n(0){}
    newInt(int num):n(num){}
    friend newInt operator+(const newInt &p, const newInt &q);
    friend istream& operator>>(istream &is, newInt &p);
    friend ostream& operator<<(ostream &os, const newInt &p);
};
newInt operator+(const newInt &p, const newInt &q){
//    int num1 = p.n, num2 = q.n;
//    int* temp = new int[10]{0};
//    int ans = 0, i = 0;
//    while(num1 > 0 || num2 > 0){
//        temp[i] = num1 % 10 + num2 % 10;
//        if(temp[i] >= 10){
//            temp[i] -= 10;
//        }
//        num1 /= 10;
//        num2 /= 10;
//        ++i;
//    }
//    --i;//多
//    for(; i >= 0; --i){
//        ans = ans * 10 + temp[i];
//    }
//    newInt c(ans);
//    delete []temp;
//    return c;
    newInt c;
    int num1 = p.n, num2 = q.n;
    int n = 1;
    while(num1 || num2){
        c.n += (num1 % 10 + num2 % 10) % 10 * n;//超10取个位数可看作再次对10取余；
        n *= 10;//使新取得的操作数上高位，通过控制n扩大10倍来实现
        num1 /= 10;
        num2 /= 10;
    }
    return c;
}
istream& operator>>(istream &is, newInt &p){
    cin>>p.n;
    return is;
}
ostream& operator<<(ostream &os, const newInt &p){
    cout<<p.n;
    return os;
}
int main()
{
    int cases;
    newInt a, b, c;
    cin>>cases;
    for (int i = 0; i < cases; i++)
    {
        cin>>a>>b;
        c = a + b;
        cout<<a<<" + "<<b<<" = "<<c<<endl;
    }
    return 0;
}
