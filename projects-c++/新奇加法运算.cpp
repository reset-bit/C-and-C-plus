/*
����ӷ�����
������newInt�������������+��
�������Ϊ����A��B��Ӧλ���ϵ�������ӣ�ֻ������λ����Ϊ����Ķ�Ӧλ���ϵ����֡�
���磺876 + 543 = 319��ע�⣺�����㲻�ı�������������ֵ��
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
//    --i;//��
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
        c.n += (num1 % 10 + num2 % 10) % 10 * n;//��10ȡ��λ���ɿ����ٴζ�10ȡ�ࣻ
        n *= 10;//ʹ��ȡ�õĲ������ϸ�λ��ͨ������n����10����ʵ��
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
