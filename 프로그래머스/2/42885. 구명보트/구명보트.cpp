#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// 그리디의 구체적인 공식을 모르겠음

int solution(vector<int> people, int limit) {
    int answer = 0;
    int num=people.size();
    sort(people.begin(),people.end());
    int light=0,heavy=num-1;
    
    while(light<=heavy){
        if(people[light]+people[heavy]>limit){
            answer++;
            heavy--;
        }
        else{
            answer++;
            light++;
            heavy--;
        }
    }
    
    return answer;
}