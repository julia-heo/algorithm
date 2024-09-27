#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

int solution(vector<string> friends, vector<string> gifts) {
    int answer = 0;
    
    int fNum=friends.size();
    map<string,int> m;
    m.clear();
    for(int i=0;i<fNum;i++){
        m.insert(make_pair(friends[i],i));
    }
    
    vector <vector<int>> vec(fNum,vector<int>(fNum,0));
    vector <int> jisu(fNum,0);
    
    for(int i=0;i<gifts.size();i++){
        string str=gifts[i];
        int index=str.find(' ');
        string f1 = str.substr(0,index); 
        string f2 = str.substr(index+1);
        int f1num=m[f1];
        int f2num=m[f2];
        
        
        vec[f1num][f2num]+=1;
        jisu[f1num]+=1;
        jisu[f2num]-=1;
        
    }
    for(int i=0;i<fNum;i++){
        int sun=0;
        for(int j=0;j<fNum;j++){
            if(vec[i][j]>vec[j][i])sun++;
            else if(vec[i][j]==vec[j][i]){
                if(jisu[i]>jisu[j])sun++;
            }    
        }
        if(sun>answer)answer=sun;
    }
    
    return answer;
}