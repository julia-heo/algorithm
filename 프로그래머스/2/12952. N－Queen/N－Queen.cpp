#include <string>
#include <vector>
#include <cmath>

using namespace std;
int col[15]={0,};
int answer = 0;
int nsize=0;

int check(int now){
    for(int i=0;i<now;i++){
        if(col[i]==col[now]||now-i==abs(col[now]-col[i])){
            return 0;
        }
    }
    return 1;
}

void queen(int now){
    if(nsize==now){
        answer++;
        return;
    } else {
        for(int i=0;i<nsize;i++){
            col[now]=i;
            if(check(now)){
                queen(now+1);
            }
        }
    }
}

int solution(int n) {
    nsize=n;
    queen(0);
    
    return answer;
}