#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;

int check(vector<int> bingo){
    int cnt=0;
    int go=1;
    

    // 가로빙고
    for(int i=0;i<=20;i=i+5){
        go=1;
        for(int j=0;j<5;j++){
            if(bingo[i+j]!=-1) go=0;
        }
        if(go)cnt++;
    }
    
    
    //세로빙고
    for(int i=0;i<5;i++){
        go=1;
        for(int j=0;j<5;j++){
            if(bingo[i+j*5]!=-1) go=0;
        }
        if(go)cnt++;
    }
    
    // 대각선빙고 "\"
    go=1;
    for(int i=0;i<=24;i+=6){
        if(bingo[i]!=-1) go=0;
    }
    if(go)cnt++;
    
    // 대각선빙고 "|"
    go=1;
    for(int i=4;i<=20;i+=4){
        if(bingo[i]!=-1) go=0;
    }
    if(go)cnt++;
    
    return cnt;
}

int main()
{
    vector <int> bingo(25);
    int input;
    for(int i=0;i<25;i++){
        cin>>input;
        bingo[i]=input;
    }
    int call;
    int answer=1000;
    int num=0;
    for(int i=0;i<25;i++){
        cin>>call;
        auto index=find(bingo.begin(),bingo.end(),call);
        int id=index-bingo.begin();
        bingo[id]=-1;
        if(check(bingo)>=3){
            if(i+1<answer) answer=i+1;
        }
    }
    cout<<answer;
    
    return 0;
}