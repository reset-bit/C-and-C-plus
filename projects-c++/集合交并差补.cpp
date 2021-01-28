//ĩβ�����ּ�����������
#include<iostream>
#include<set>
#include<algorithm>
using namespace std;
void print(const set<int> &a){
    set<int>::iterator iter = a.begin();
    cout<<"{";
    for(iter; iter != a.end(); ++iter){
        if(iter == a.begin()){
            cout<<*iter;
        }
        else{
            cout<<", "<<*iter;
        }
    }
    cout<<"}"<<endl;
}
int main(){
    int t;
    cin>>t;
    for(int i = 0; i < t; ++i){
        cout<<"Case# "<<i + 1<<":"<<endl;

        int alen, blen;
        set<int> a, b;
        set<int> tmp1, tmp2, tmp3, tmp4, tmp5;
        set<int>::iterator itera = a.begin(), iterb = b.begin();

        cin>>alen;
        for(int j = 0; j < alen; ++j){
            int t;
            cin>>t;
            a.insert(t);
        }
        cin>>blen;
        for(int j = 0; j < blen; ++j){
            int t;
            cin>>t;
            b.insert(t);
        }

        cout<<"A = ";
        print(a);
        cout<<"B = ";
        print(b);

        //��
        set_union(a.begin(), a.end(), b.begin(), b.end(), inserter(tmp1, tmp1.begin()));
        cout<<"A u B = ";
        print(tmp1);
        //��
        set_intersection(a.begin(), a.end(), b.begin(), b.end(), inserter(tmp2, tmp2.begin()));
        cout<<"A n B = ";
        print(tmp2);
        //��
        set_difference(a.begin(), a.end(), b.begin(), b.end(), inserter(tmp3, tmp3.begin()));
        cout<<"A - B = ";
        print(tmp3);
        //A��
        set_difference(tmp1.begin(), tmp1.end(), a.begin(), a.end(), inserter(tmp4, tmp4.begin()));
        cout<<"SA = ";
        print(tmp4);
        //B��
        set_difference(tmp1.begin(), tmp1.end(), b.begin(), b.end(), inserter(tmp5, tmp5.begin()));
        cout<<"SB = ";
        print(tmp5);
    }
    return 0;
}

/**
1.Inserter

ԭ�����ڲ�����insert()

���ܣ���������ָ��λ�ò���Ԫ��

���ƣ�ֻ���ṩ��inset()��Ա�����������У�inserter���������ó�. ����STL�������ṩ��inset()����.


2.set_symmetric_difference (beg1,end1,beg2,end2,dest) ;

���ܣ��󲹼��������飩

����:[beg1,end1)��[beg2,end2)��ʾ�Ѱ��������������������.[dest,...)��ʾ�������.greater<int> ()�Ƕ�Ԫ��������.

����:�����������д������һ���������д��ڣ�����ͬʱ���������������д��ڵ�Ԫ��.������а�����������.

����ֵ:����ָ������������һ����д��Ԫ����һ��λ�õĵ�����.

��ע:	���ͬһ��Ԫ�����������������ж�����.�������������д���Ԫ�ص�����Ϊ:
        |[beg1,end1)�г��ֵĴ��� - [beg2,end2)�г��ֵĴ���|.д�뵽������е�Ԫ�ؼ�����λ�ò���.
        ���뱣����������㹻���ܹ����������Ԫ��.���򽫴����쳣.

*/
