#include <string>
#include <vector>
#include <cmath>

using namespace std;
int col[15] = {0,};
int N;
int answer=0;

int check(int n){
    for(int i=0;i<n;i++){
        if(col[i]==col[n]) return 0;
        if(n-i==abs(col[i]-col[n]))return 0;
    }
    return 1;
}

void queen(int n){ 
    if(n==N){
        answer++;
    } else {
        for(int i=0;i<N;i++){
            col[n]=i;
            if(check(n)) queen(n+1);
        }
    }
}

int solution(int n) {
    N=n;
    
    queen(0);
    return answer;
}