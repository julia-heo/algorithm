#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;


int main()
{
    int N,K;
    cin>>N>>K;
    vector <int> v(N,0);
    vector <int> sumnum;
    for(int i=0;i<N;i++){
        cin>>v[i];
    }
    int sum=0;
    for(int i=0;i<K;i++){
        sum+=v[i];
    }
    sumnum.push_back(sum);
    for(int i=K;i<N;i++){
        sum+=v[i];
        sum-=v[i-K];
        sumnum.push_back(sum);
    }
    sort(sumnum.begin(),sumnum.end(),greater<int>());
    cout<<sumnum[0];
    return 0;
}