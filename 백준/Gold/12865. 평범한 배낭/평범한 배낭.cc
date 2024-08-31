/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <iostream>
#include <algorithm>
using namespace std;
#include <vector>

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int N,K;
    cin>>N>>K;
    
    vector<vector<int>> bags(N+1,vector<int>(2,0));
    for(int i=1;i<=N;i++){
        cin>>bags[i][0]>>bags[i][1]; // 무게 가치
    }
    
    vector<vector<int>> dp(N+1,vector<int>(K+1,0));
    // i번째 물건까지 고려했을때, 무게j가 가질 수 있는 최대 가치 dp[i][j]
    // if (i의 W>K) dp[i][j] = dp[i-1][j]
    // else MAX(dp[i-1][j], dp[i-1][j-W]+V)  
    // 1만큼 무게가 늘었을 때, 현재 W를 넣을거면 j-W한거에 현재의 V를 더해야 함 !와우
    for(int i=1;i<=N;i++){
        for(int j=1;j<=K;j++){
            if(bags[i][0]>j) {
                dp[i][j]=dp[i-1][j];
            }
            else{
                dp[i][j]=max(dp[i-1][j], dp[i-1][j-bags[i][0]]+bags[i][1]);
            }
            //cout<<i<<" "<<j<<": "<<dp[i][j]<<"\n";
        }
    }
    cout<<dp[N][K];
    

    return 0;
}