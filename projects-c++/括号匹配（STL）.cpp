#include <bits/stdc++.h>//!����ͷ�ļ�
using namespace std;
int main(){
    string data;
    while(cin>>data){
        stack<int> s;//��s���Ƿ����1����Ƿ�ƥ��
        int i;
        for(i = 0; i < data.length(); i++){
            if(data[i] == '('){//!string��ֱ��������ʹ�ã�
                s.push(1);
            }
            else if(!s.empty()){
                s.pop();
            }
            else{//s��
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
        strcpy(tmp, data.c_str());  //stringתchar
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
