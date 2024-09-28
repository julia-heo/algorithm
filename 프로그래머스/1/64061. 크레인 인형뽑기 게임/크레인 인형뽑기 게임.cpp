#include <string>
#include <vector>
#include <stack>
using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0,tmp;
    stack<int> st;
    
    int size = board.size();

    for(int i:moves){
        tmp=-1;
        for(int j=0;j<size;j++){
            if(board[j][i-1]!=0){
                tmp=board[j][i-1];
                board[j][i-1]=0;
                break;
            }
        }
        if(tmp!=-1){
            if(st.empty()) st.push(tmp);
            else if(st.top()==tmp){st.pop();answer+=2;}
            else st.push(tmp);
        }
    }
    
    
    
    return answer;
}