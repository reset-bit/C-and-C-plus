#include <bits/stdc++.h>//!万能头文件
using namespace std;
int main(){
    string data;
    while(cin>>data){
        stack<int> s;//用s中是否存在1标记是否匹配
        int i;
        for(i = 0; i < data.length(); i++){
            if(data[i] == '('){//!string可直接类数组使用！
                s.push(1);
            }
            else if(!s.empty()){
                s.pop();
            }
            else{//s空
                break;
            }
        }
        if(i == data.length() && s.empty())
            cout<<"YES"<<endl;
        else
            cout<<"NO"<<endl;
    }
    return 0;
}
/*
int main(){
    string data;
    stack<char> s;
    while(cin>>data){
        char tmp[100];
        int flag = 0;
        strcpy(tmp, data.c_str());  //string转char
        for(int i = 0; tmp[i] != '\0'; ++i){
            if(tmp[i] == '('){
                s.push(tmp[i]);
            }
            else if(tmp[i] == ')'){
                if(!s.empty()){
                    if(s.top() != '('){
                        cout<<"NO"<<endl;
                        flag = 1;
                        break;
                    }
                    s.pop();
                }
                else{
                    cout<<"NO"<<endl;
                    flag = 1;
                    break;
                }
            }//else if
        }//for
        if(flag == 0){
            cout<<"YES"<<endl;
        }
    }
    return 0;
}
*/
