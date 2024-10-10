#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int N;
    cin>>N;
    vector <vector<pair<int,int>>> vec(N+1);// i날 끝나는거 모음:시작 날짜, 금액
    vector<int> dp(N+1);
    
    int t,p;
    for(int i=1;i<=N;i++){
        cin>>t>>p;
        if (i + t - 1 <= N) vec[i+t-1].push_back(make_pair(i,p));
    }
    
    for(int i=1;i<=N;i++){
        dp[i]=dp[i-1];
        for(pair<int,int> p : vec[i]){
            dp[i]=max(dp[i],dp[p.first-1]+p.second);
        }
    }
    
    cout<<dp[N];

    return 0;
}