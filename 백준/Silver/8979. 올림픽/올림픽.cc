
#include <iostream>
#include <algorithm>

using namespace std;
struct Medal{
    int country;
    int gold;
    int silv;
    int bron;
    int R;
};

bool comp(const Medal &m1, const Medal &m2){
    if(m1.gold == m2.gold){
        if(m1.silv == m2.silv){
            return m1.bron>=m2.bron;
        }
        else{
            return m1.silv>m2.silv;
        }
    }
    else{
        return m1.gold > m2.gold;
    }
}




int main()
{
    int N,K;
    cin>>N>>K;
    Medal med[1000];
    
    for(int i=0;i<N;i++){
        cin>>med[i].country>>med[i].gold>>med[i].silv>>med[i].bron;
    }
    sort(med,med+N,comp);
    
    for(int i=0;i<N;i++){
        med[i].R=i+1;
    }
    
    for(int i=1;i<N;i++){
       if(med[i].gold==med[i-1].gold&&med[i].silv==med[i-1].silv&&med[i].bron==med[i-1].bron){
           med[i].R=med[i].R-1;
       }
    }
    
    
    for(int i=0;i<N;i++){
        if(med[i].country==K){
            cout<<med[i].R;
        }
    }
    return 0;
}
