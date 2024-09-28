#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    int N,K;
    cin>>N>>K;
    vector<vector<int>> vec(N+1,vector<int>(2,0));
    vector<vector<int>> dp(N+1,vector<int>(K+1,0)); //가치합
    for(int i=1;i<=N;i++){
        cin>>vec[i][0]>>vec[i][1];
    }

    
    for(int i=1;i<=N;i++){
        for(int j=1;j<=K;j++){
            if(vec[i][0]>j) dp[i][j]=dp[i-1][j];
            else{
                dp[i][j]=max(dp[i-1][j],dp[i-1][j-vec[i][0]]+vec[i][1]);
            }
        }
    }
    cout<<dp[N][K];
    return 0;
}

