#include <iostream>
#include<vector>
using namespace std;

int solution(vector<vector<int>> board)
{
    int answer = 0;

    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "Hello Cpp" << endl;
    
    int size1 = board.size();
    int size2 = board[0].size();
    vector<vector<int>> dp(size1,vector<int>(size2,0));
    
    for(int i=0;i<size1;i++){dp[i][0]=board[i][0];if(dp[i][0]>answer)answer=dp[i][0];}
    for(int i=0;i<size2;i++){dp[0][i]=board[0][i];if(dp[0][i]>answer)answer=dp[0][i];}
    
    for(int i=1;i<size1;i++){
        for(int j=1;j<size2;j++){
            if(board[i][j]==0)dp[i][j]=0;
            else{dp[i][j]=min(min(dp[i-1][j-1],dp[i][j-1]),dp[i-1][j])+1;}
            if(dp[i][j]>answer)answer=dp[i][j];
        }
    }    
    answer=answer*answer;
    return answer;
}