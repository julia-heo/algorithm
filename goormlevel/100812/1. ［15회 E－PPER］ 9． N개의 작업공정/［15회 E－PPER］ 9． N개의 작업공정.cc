#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;


int solution(int n[],int r[][100],int goal,int N,int R){
    int answer=0;
		for(int i=0;i<R;i++){
			if(r[i][1]==goal){
				answer=max(answer,n[goal-1]+solution(n, r, r[i][0], N, R));
			}
		}
		if (answer==0) answer=n[goal-1];
		return answer;
}


int main() {
    int N;
    int R;
    int n[100] = {0};
    int r[100][100] = {0};
    int goal, k;

    scanf("%d %d", &N, &R);

    for (int i = 0; i < N; i++) {
        scanf("%d", &n[i]);
    }
	
    for (int k = 0; k < R; k++) {
        for (int j = 0; j < 2; j++) {
            scanf("%d", &r[k][j]);
        }
    }

    scanf("%d", &goal);
    k = solution(n, r, goal, N, R);
    printf("%d\n", k);
}