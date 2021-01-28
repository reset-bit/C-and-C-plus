#include<iostream>
#include<iomanip>
using namespace std;
int main(){
    double a;
    cin>>a;
    cout<<setiosflags(ios::fixed)<<setprecision(6)<<"Area: "<<3.14*a*a<<endl;
    cout<<setiosflags(ios::fixed)<<setprecision(6)<<"Perimeter: "<<2*3.14*a<<endl;
    return 0;
}
