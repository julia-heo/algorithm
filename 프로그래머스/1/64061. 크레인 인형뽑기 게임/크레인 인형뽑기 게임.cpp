#include<iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    int size=board.size();
    stack<int> basket;

    for (auto i : moves) {
        for(int j=0;j<size;j++){
            if(board[j][i-1]!=0){
                if(basket.empty()==false&&basket.top()==board[j][i-1]){
                    basket.pop();
                    answer++;
                } 
                else {
                    basket.push(board[j][i-1]);
                }
                board[j][i-1]=0;
                
                break;
            }
        }
    }
    
    return answer*2;
}