#include <iostream>
#include<vector>
using namespace std;

int solution(vector<vector<int>> board)
{
    int answer = 0;

    // [실행] 버튼을 누르면 출력 값을 볼 수 있습니다.
    cout << "Hello Cpp" << endl;
    
    int col=board.size();
    int row=board[0].size();
    vector<vector<int>> dp (col,vector<int>(row,0));
    
    
    for(int i=0;i<col;i++){
        for(int j=0;j<row;j++){
            if(i==0||j==0)dp[i][j]=board[i][j];
            else if (board[i][j]==0)dp[i][j]=0;
            else{
                dp[i][j]=min(dp[i-1][j],min(dp[i-1][j-1],dp[i][j-1]))+1;
            }
            if(dp[i][j]>answer)answer=dp[i][j];
        }
    }

    return answer*answer;
}