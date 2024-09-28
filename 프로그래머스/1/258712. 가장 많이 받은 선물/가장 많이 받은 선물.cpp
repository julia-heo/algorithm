#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0,index;
    int size=friends.size();
    map <string, int> m;
    vector<vector<int>> his(size,vector<int>(size,0));
    vector<int> score(size,0);
    
    for(int i=0;i<size;i++){
        m.insert(make_pair(friends[i],i));
    }    
    for(string str : gifts){
        index=str.find(' ');
        string fromN = str.substr(0,index);
        string toN = str.substr(index+1);
        int from=m[fromN];
        int to=m[toN];
        his[from][to]++;
        score[from]++;
        score[to]--;
    }
    vector<int> giftCount(size,0);
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            if(his[i][j]>his[j][i]) giftCount[i]++;
            else if(his[i][j]==his[j][i]){
                if(score[i]>score[j])giftCount[i]++;
            }
        }
    }
    for(int i=0;i<size;i++){
        if(giftCount[i]>answer)answer=giftCount[i];
    }   
    
    
    return answer;
}