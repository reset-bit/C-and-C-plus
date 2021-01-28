#include <iostream>

using namespace std;


void get_num(int &a,int &b,int &c){
    cin>>a>>b>>c;
}

int mymax(int x,int y){
    return x>y?x:y;
}

int mymin(int x,int y){
    return x>y?y:x;
}

void max_min(int &mmax,int &mmin,int &a,int &b,int &c){
    mmax = mymax(a, b);
    if(c > mmax){
        mmax = c;
    }
    mmin = mymin(a, b);
    if(c < mmin){
        mmin = c;
    }
}

int main()
{
    int cases;
    int mmax, mmin, a, b, c;

    cin>>cases;
    for(int i = 1; i <= cases; ++i)
    {
        get_num(a, b, c);
        max_min(mmax, mmin, a, b, c);
        cout<<"case "<<i<<" : "<<mmax<<", "<<mmin<<endl;
    }
}
