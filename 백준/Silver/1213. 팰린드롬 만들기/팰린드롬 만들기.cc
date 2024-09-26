#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    vector<int> vec(26,0);
    vector<char> answer(25,0);
    vec.clear(); answer.clear();
    
    string str;
    cin>>str;
    
    for(int i=0;i<str.length();i++){
        int n=str[i]-'A';
        vec[n]=vec[n]+1;
    }
    
    int num=0;
    int hol=-1;
    for(int i=0;i<26;i++){
        if(vec[i]%2==1){
            num++;
            hol=i;
        }
        for(int j=0;j<vec[i]/2;j++)answer.push_back('A'+i);
    }
    
    
    
    
    if(num>1) cout<<"I'm Sorry Hansoo";
    else{
        if(hol!=-1)answer.push_back('A'+hol);
        for (char i : answer) cout << i;
        if(num==1)for(int i=answer.size()-2;i>=0;i--) cout << answer[i];
        else for(int i=answer.size()-1;i>=0;i--) cout << answer[i];
    }
    
    
}