#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


struct country {
    int name;
    int gold;
    int silver;
    int dong;
    int grade;
};
vector <country> C;

bool cmp(country a, country b){
    if(a.gold==b.gold) {
        if(a.silver==b.silver) {
            return a.dong>b.dong;
        }
        return a.silver>b.silver;
    }
    return a.gold>b.gold;
}
bool same(country a, country b){
    if(a.gold==b.gold&&a.silver==b.silver&&a.dong==b.dong) {
        return true;
    }
    return false;
}

int main()
{
    int N,K;
    cin>>N>>K;
    C.resize(N);
    
    int a,b,c,d;
    for(int i=0;i<N;i++){
        cin>>C[i].name>>C[i].gold>>C[i].silver>>C[i].dong;
        C[i].grade=0;
    }
    sort(C.begin(),C.end(), cmp);
    
    int g=1, cnt=1;
    C[0].grade=1;
    struct country tmp = C[0];
    if(C[0].name==K) {
        cout<<1;
    } else {
        int now=1;
        for(;now<N;now++){
            if(same(tmp,C[now])) {
                C[now].grade=g;
                cnt++;
            }
            else{
                g+=cnt;
                C[now].grade=g;
                cnt=1;
            }
            if(C[now].name==K) break;
            tmp=C[now];
        }
        cout<<C[now].grade;
    }
    
    
    

    return 0;
}