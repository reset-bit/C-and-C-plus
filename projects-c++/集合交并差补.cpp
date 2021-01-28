//末尾附部分几个函数介绍
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

        //并
        set_union(a.begin(), a.end(), b.begin(), b.end(), inserter(tmp1, tmp1.begin()));
        cout<<"A u B = ";
        print(tmp1);
        //交
        set_intersection(a.begin(), a.end(), b.begin(), b.end(), inserter(tmp2, tmp2.begin()));
        cout<<"A n B = ";
        print(tmp2);
        //差
        set_difference(a.begin(), a.end(), b.begin(), b.end(), inserter(tmp3, tmp3.begin()));
        cout<<"A - B = ";
        print(tmp3);
        //A补
        set_difference(tmp1.begin(), tmp1.end(), a.begin(), a.end(), inserter(tmp4, tmp4.begin()));
        cout<<"SA = ";
        print(tmp4);
        //B补
        set_difference(tmp1.begin(), tmp1.end(), b.begin(), b.end(), inserter(tmp5, tmp5.begin()));
        cout<<"SB = ";
        print(tmp5);
    }
    return 0;
}

/**
1.Inserter

原理：其内部调用insert()

功能：在容器的指定位置插入元素

限制：只有提供了inset()成员函数的容器中，inserter才能派上用场. 所有STL容器都提供了inset()函数.


2.set_symmetric_difference (beg1,end1,beg2,end2,dest) ;

功能：求补集（不建议）

参数:[beg1,end1)和[beg2,end2)标示已按非升序排序的输入序列.[dest,...)标示输出序列.greater<int> ()是二元函数对象.

操作:向输出序列中写入在任一输入容器中存在，但不同时在两个输入容器中存在的元素.输出序列按非升序排列.

返回值:返回指向输出序列最后一个被写入元素下一个位置的迭代器.

备注:	如果同一个元素在两个输入序列中都出现.则向输出序列中写入该元素的数量为:
        |[beg1,end1)中出现的次数 - [beg2,end2)中出现的次数|.写入到输出序列的元素间的相对位置不变.
        必须保障输出序列足够大能够容纳输入的元素.否则将触发异常.

*/
