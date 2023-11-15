#include <string>
#include <vector>
#include <iostream>

using namespace std;
string number[10]={"zero","one","two","three","four","five","six","seven","eight","nine"};

int solution(string s) {
    int answer = 0;
    string tmp="";
    
    for(int i=0;i<s.size()+1;i++){
        if(tmp!=""){
            cout<<tmp<<" ";
            int j=0;
            for(;j<=10;j++){
                if(tmp==number[j]){
                    answer=answer*10+j;
                    break;
                }
            }

            if(j!=11)tmp="";
        }
        
        if(0<=s[i]-'0'&&s[i]-'0'<10){
            answer=answer*10+(s[i]-'0');
        }
        else{
            
            tmp+=s[i];
            // cout<<tmp<<" ";
        }
    }
    return answer;
}